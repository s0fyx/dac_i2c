# dac_i2c_mcp4725

Sample example for using I2C with ESP32 for the MCP4725 module in ESP-IDF 5.4

# Use

```c
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
```

# Functions

```c
esp_err_t i2c_mcp4725_init(i2c_port_num_t port, uint8_t sda, uint8_t scl, uint16_t speed);
esp_err_t mcp4725_set_output(uint16_t value, bool eeprom);
esp_err_t mcp4725_set_voltage(float vdd, float value, bool eeprom);
```
