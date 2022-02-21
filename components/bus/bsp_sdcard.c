/**
 * @file sdmmc_private.c
 * @brief 
 * @version 0.1
 * @date 2021-11-04
 * 
 * @copyright Copyright 2021 Espressif Systems (Shanghai) Co. Ltd.
 *
 *      Licensed under the Apache License, Version 2.0 (the "License");
 *      you may not use this file except in compliance with the License.
 *      You may obtain a copy of the License at
 *
 *               http://www.apache.org/licenses/LICENSE-2.0
 *
 *      Unless required by applicable law or agreed to in writing, software
 *      distributed under the License is distributed on an "AS IS" BASIS,
 *      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *      See the License for the specific language governing permissions and
 *      limitations under the License.
 */

#include "bsp_sdcard.h"

static const char *TAG = "bsp_sdcard";

#define SDMMC_BUS_WIDTH (1)
#define GPIO_SDMMC_CLK  (GPIO_NUM_47)
#define GPIO_SDMMC_CMD  (GPIO_NUM_21)
#define GPIO_SDMMC_D0   (GPIO_NUM_48)
#define GPIO_SDMMC_D1   (GPIO_NUM_NC)
#define GPIO_SDMMC_D2   (GPIO_NUM_NC)
#define GPIO_SDMMC_D3   (GPIO_NUM_NC)
#define GPIO_SDMMC_DET  (GPIO_NUM_NC)

#define DEFAULT_FD_NUM  (2)
#define DEFAULT_MOUNT_POINT  "/sdcard"
static sdmmc_card_t *card;

esp_err_t bsp_sdcard_init(char *mount_point, size_t max_files)
{
    if (NULL != card) {
        return ESP_ERR_INVALID_STATE;
    }

    esp_err_t ret_val = ESP_OK;

	/**
	 * @brief Options for mounting the filesystem.
	 *   If format_if_mount_failed is set to true, SD card will be partitioned and
	 *   formatted in case when mounting fails.
	 */
	esp_vfs_fat_sdmmc_mount_config_t mount_config = {
        .format_if_mount_failed = false,
        .max_files = max_files,
        .allocation_unit_size = 16 * 1024
    };

	/**
	 * @brief Use settings defined above to initialize SD card and mount FAT filesystem.
	 *   Note: esp_vfs_fat_sdmmc/sdspi_mount is all-in-one convenience functions.
	 *   Please check its source code and implement error recovery when developing
	 *   production applications.
	 */
    sdmmc_host_t host = SDMMC_HOST_DEFAULT();

	/**
	 * @brief This initializes the slot without card detect (CD) and write protect (WP) signals.
	 *   Modify slot_config.gpio_cd and slot_config.gpio_wp if your board has these signals.
	 */
    sdmmc_slot_config_t slot_config = SDMMC_SLOT_CONFIG_DEFAULT();

    /* Config SD data width. 0, 4 or 8. Currently for SD card, 8 bit is not supported. */
    slot_config.width = SDMMC_BUS_WIDTH;

	/**
	 * @brief On chips where the GPIOs used for SD card can be configured, set them in
	 *   the slot_config structure.
	 * 
	 */
#if SOC_SDMMC_USE_GPIO_MATRIX
    slot_config.clk = GPIO_SDMMC_CLK;
    slot_config.cmd = GPIO_SDMMC_CMD;
    slot_config.d0 = GPIO_SDMMC_D0;
    slot_config.d1 = GPIO_SDMMC_D1;
    slot_config.d2 = GPIO_SDMMC_D2;
    slot_config.d3 = GPIO_SDMMC_D3;
#endif
    slot_config.cd = GPIO_SDMMC_DET;
    slot_config.flags |= SDMMC_SLOT_FLAG_INTERNAL_PULLUP;

	/**
	 * @brief Enable internal pullups on enabled pins. The internal pullups
	 *   are insufficient however, please make sure 10k external pullups are
	 *   connected on the bus. This is for debug / example purpose only.
	 */

	/* get FAT filesystem on SD card registered in VFS. */
    ret_val = esp_vfs_fat_sdmmc_mount(mount_point, &host, &slot_config, &mount_config, &card);

	/* Check for SDMMC mount result. */
    if (ret_val != ESP_OK) {
        if (ret_val == ESP_FAIL) {
            ESP_LOGE(TAG, "Failed to mount filesystem. "
                "If you want the card to be formatted, set the EXAMPLE_FORMAT_IF_MOUNT_FAILED menuconfig option.");
        } else {
            ESP_LOGE(TAG, "Failed to initialize the card (%s). "
                "Make sure SD card lines have pull-up resistors in place.", esp_err_to_name(ret_val));
        }
        return ret_val;
    }

    /* Card has been initialized, print its properties. */
    sdmmc_card_print_info(stdout, card);
	
	return ret_val;
}

esp_err_t bsp_sdcard_init_default(void)
{
	return bsp_sdcard_init(DEFAULT_MOUNT_POINT, DEFAULT_FD_NUM);
}

esp_err_t bsp_sdcard_deinit(char *mount_point)
{
    if (NULL == mount_point) {
        return ESP_ERR_INVALID_STATE;
    }

    /* Unmount an SD card from the FAT filesystem and release resources acquired */
    esp_err_t ret_val = esp_vfs_fat_sdcard_unmount(mount_point, card);

    /* Make SD/MMC card information structure pointer NULL */
    card = NULL;

	return ret_val;
}

esp_err_t bsp_sdcard_deinit_default(void)
{
    return bsp_sdcard_deinit(DEFAULT_MOUNT_POINT);
}
