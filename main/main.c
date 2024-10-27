/*

███    ███  █████  ██ ███    ██ 
████  ████ ██   ██ ██ ████   ██ 
██ ████ ██ ███████ ██ ██ ██  ██ 
██  ██  ██ ██   ██ ██ ██  ██ ██ 
██      ██ ██   ██ ██ ██   ████ 


 - Code by: s4mu3l
 - last update: 27-10-2024

*/
/*═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#include "config.h"

/*═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

#define TAG_MAIN  "[main]"

/*═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

i2c_master_dev_handle_t dev_handle = NULL;
i2c_master_bus_handle_t bus_handle = NULL;

uint8_t buffer[] = {0b01000000, 0b01111101, 0b00000000}; // 2000 = 0111_1101_0000

/*═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

esp_err_t i2c_mcp4725_init(i2c_port_num_t port, uint8_t sda, uint8_t scl, uint16_t speed);
esp_err_t mcp4725_set_output(uint16_t value, bool eeprom);
esp_err_t mcp4725_set_voltage(float vdd, float value, bool eeprom);

/*═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/


void app_main(void)
{

    ESP_ERROR_CHECK(i2c_mcp4725_init(I2C_PORT, I2C_SDA_IO, I2C_CLK_IO, I2C_CLK_SPEED));
    ESP_ERROR_CHECK(mcp4725_set_voltage(3.3, 1.7, false));


    while (true)
    {
        /* code */
        vTaskDelay(pdMS_TO_TICKS(10));
    }
    
}


/*═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

esp_err_t i2c_mcp4725_init(i2c_port_num_t port, uint8_t sda, uint8_t scl, uint16_t speed)
{

    esp_err_t err = 0;

    i2c_master_bus_config_t i2c_mst_config = {
        .clk_source = I2C_CLK_SRC,
        .i2c_port = port,
        .scl_io_num = scl,
        .sda_io_num = sda,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true,
    };

    i2c_device_config_t dev_cfg = {
        .dev_addr_length = I2C_ADDR_BIT_LEN_7,
        .device_address = MCP4725A0_I2C_ADDR0,
        .scl_speed_hz = speed,
    };

    err = i2c_new_master_bus(&i2c_mst_config, &bus_handle);
    assert(ESP_OK == err);

    err = i2c_master_bus_add_device(bus_handle, &dev_cfg, &dev_handle);

    return err;

}

esp_err_t mcp4725_set_output(uint16_t value, bool eeprom)
{
    esp_err_t err = 0;

    uint8_t data[] = {
        (eeprom ? 0x60 : 0x40),
        value >> 4,
        value << 4
    };

    err = i2c_master_transmit(dev_handle, data, sizeof(data), -1);

    return err;
}

esp_err_t mcp4725_set_voltage(float vdd, float value, bool eeprom)
{
    esp_err_t err = 0;

    err = mcp4725_set_output(MCP4725_MAX_VALUE / vdd * value, eeprom);

    return err;
}

/*═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/
