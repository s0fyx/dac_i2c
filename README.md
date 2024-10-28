# dac_i2c_mcp4725

Este es un ejemplo sencillo para el uso de i2c con ESP32 para el modulo MCP4725 en ESP-IDF 5.4

# Uso

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

# Funciones

```c
esp_err_t i2c_mcp4725_init(i2c_port_num_t port, uint8_t sda, uint8_t scl, uint16_t speed);
esp_err_t mcp4725_set_output(uint16_t value, bool eeprom);
esp_err_t mcp4725_set_voltage(float vdd, float value, bool eeprom);
```
