/*

███████ ██    ██ ███    ██  ██████ ████████ ██  ██████  ███    ██ ███████ 
██      ██    ██ ████   ██ ██         ██    ██ ██    ██ ████   ██ ██      
█████   ██    ██ ██ ██  ██ ██         ██    ██ ██    ██ ██ ██  ██ ███████ 
██      ██    ██ ██  ██ ██ ██         ██    ██ ██    ██ ██  ██ ██      ██ 
██       ██████  ██   ████  ██████    ██    ██  ██████  ██   ████ ███████ 


 - Code by: s4mu3l
 - last update: 27-10-2024

*/
/*═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

#include "config.h"

/*═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/

/* FUNTIONS */
int32_t float_to_int32(float value)
{
    if (value > INT32_MAX)
        return INT32_MAX; // Manejo de desbordamiento superior

    if (value < INT32_MIN)
        return INT32_MIN; // Manejo de desbordamiento inferior

    return (int32_t)roundf(value); // Redondeo al entero más cercano
}

int string_to_int(const char *str)
{
    return atoi(str); // Convierte una cadena a int
}

float string_to_float(const char *str)
{
    return atof(str); // Convierte una cadena a float
}

void int_to_string(int value, char *buffer, size_t buffer_size)
{
    snprintf(buffer, buffer_size, "%d", value); // Convierte int a cadena
}

void float_to_string(float value, char *buffer, size_t buffer_size)
{
    snprintf(buffer, buffer_size, "%.2f", value); // Convierte float a cadena con 2 decimales
}

float round_to_nearest(float value)
{
    return roundf(value); // Redondea al entero más cercano
}

int truncate_float(float value)
{
    return (int)value; // Trunca el valor float a int
}

float calculate_square(float value)
{
    return value * value; // Calcula el cuadrado
}

float calculate_square_root(float value)
{
    return sqrtf(value); // Calcula la raíz cuadrada
}

float calculate_power(float base, float exponent)
{
    return powf(base, exponent); // Calcula base^exponente
}

void reverse_array(int *array, size_t size)
{
    for (size_t i = 0; i < size / 2; i++) {
        int temp = array[i];
        array[i] = array[size - 1 - i];
        array[size - 1 - i] = temp; // Invierte un arreglo de enteros
    }
}

float calculate_average(const float *array, size_t size)
{
    float sum = 0.0f;
    for (size_t i = 0; i < size; i++) {
        sum += array[i]; // Suma todos los elementos
    }
    return (size > 0) ? (sum / size) : 0.0f; // Calcula el promedio
}

bool is_even(int number)
{
    return number % 2 == 0; // Verifica si un número es par
}

bool is_prime(int number)
{
    if (number <= 1) return false;
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) return false; // Verifica si un número es primo
    }
    return true;
}

/*═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════*/
