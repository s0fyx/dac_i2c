/*

 ██████  ██████  ███    ██ ███████ ██  ██████  
██      ██    ██ ████   ██ ██      ██ ██       
██      ██    ██ ██ ██  ██ █████   ██ ██   ███ 
██      ██    ██ ██  ██ ██ ██      ██ ██    ██ 
 ██████  ██████  ██   ████ ██      ██  ██████  


 - Code by: s4mu3l
 - last update: 27-10-2024

*/
/*═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

#include <stdlib.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <limits.h>
#include <math.h>
#include <unistd.h>
#include <sys/lock.h>
#include <sys/param.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "esp_system.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_check.h"
#include "driver/gpio.h"
#include "driver/i2c_master.h"
#include "driver/temperature_sensor.h"

/*═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

#define TAG_MAIN_T       "[ main_task ]"

#define I2C_SDA_IO     41
#define I2C_CLK_IO     42
#define I2C_CLK_SRC    I2C_CLK_SRC_DEFAULT
#define I2C_PORT       I2C_NUM_1
#define I2C_CLK_SPEED  100000

#define MCP4725A0_I2C_ADDR0 0x60
#define MCP4725A0_I2C_ADDR1 0x61

#define MCP4725_MAX_VALUE   0x0fff

/*═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

/**
 * Power mode, see datasheet
 */
/*
typedef enum
{
    MCP4725_PM_NORMAL = 0,   //!< Normal mode
    MCP4725_PM_PD_1K,        //!< Power down, 1kOhm resistor to ground
    MCP4725_PM_PD_100K,      //!< Power down, 100kOhm resistor to ground
    MCP4725_PM_PD_500K,      //!< Power down, 500kOhm resistor to ground
} mcp4725_power_mode_t;
*/

/*═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

int32_t float_to_int32(float value);
int string_to_int(const char *str);
float string_to_float(const char *str);
void int_to_string(int value, char *buffer, size_t buffer_size);
void float_to_string(float value, char *buffer, size_t buffer_size);
float round_to_nearest(float value);
int truncate_float(float value);
float calculate_square(float value);
float calculate_square_root(float value);
float calculate_power(float base, float exponent);
void reverse_array(int *array, size_t size);
float calculate_average(const float *array, size_t size);
bool is_even(int number);
bool is_prime(int number);

/*═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/
