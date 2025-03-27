/************************************************************************************************
Copyright (c) 2023, Veronica Ruiz Galvan <veronica.ruizgalvan@hotmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/
/**
 * @file gpio.c
 * @brief Implementación de las funciones para el manejo de pines GPIO.
 */

/* === Headers files inclusions =============================================================== */

#include "gpio.h"
#include "hal.h"
#include <string.h>
#include <stddef.h>

/* === Macros definitions ====================================================================== */

/**
 * @brief Número máximo de instancias GPIO permitidas.
 *
 * Define la cantidad máxima de instancias GPIO que pueden ser creadas.
 */
#ifndef GPIO_MAX_INSTANCES
#define GPIO_MAX_INSTANCES 10
#endif

/* === Private data type declarations ========================================================== */

/**
 * @brief Estructura que representa una instancia de un pin GPIO.
 *
 * La estructura gpio_s contiene información sobre el puerto, el bit y si el pin está configurado
 * como salida.
 */
struct gpio_s {
    uint8_t port;
    uint8_t bit;
    bool output;
#ifndef USE_DYNAMIC_MEM
    bool used;
#endif
};

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/**
 * @brief Asigna dinámicamente una instancia de gpio_s cuando no se usa memoria dinámica.
 *
 * Esta función busca un espacio dentro del arreglo estático de instancias de GPIO.
 *
 * @return Un puntero a la instancia de gpio_s libre.
 */
#ifndef USE_DYNAMIC_MEM
static gpio_t allocateInstance() {
    static struct gpio_s instances[GPIO_MAX_INSTANCES] = {0};

    gpio_t result = NULL;
    for (int index = 0; index < GPIO_MAX_INSTANCES; index++) {
        if (!instances[index].used) {
            result = &instances[index];
            result->used = true;
            break;
        }
    }
    return result;
}
#endif

/* === Public function implementation ========================================================== */

/**
 * @brief Constructor de un pin GPIO.
 *
 * Esta función actúa como un "constructor",
 * asignando el puerto y el bit especificados. Si la memoria dinámica está habilitada,
 * se asigna memoria dinámica para este; de lo contrario, se utiliza un arreglo estático.
 *
 * @param port Puerto del pin.
 * @param bit Bit del puerto.
 *
 * @return Un puntero a la nueva instancia de gpio_t.
 */
gpio_t gpioCreate(uint8_t port, uint8_t bit) {
#ifdef USE_DYNAMIC_MEM
    gpio_t self = malloc(sizeof(struct gpio_s));
#else
    gpio_t self = allocateInstance();
#endif

    if (self) {
        self->port = port;
        self->bit = bit;
        self->output = false;
    }
    return self;
}

/**
 * @brief Establece el modo de salida de un pin.
 *
 * Esta función configura el pin especificado como salida o no, dependiendo del parámetro `output`.
 *
 * @param self Instancia de gpio_t que representa el pin.
 * @param output Valor booleano que indica si el pin debe ser configurado como salida = true o
 * entrada = false.
 */
void gpioSetOutput(gpio_t self, bool output) {
    self->output = output;
    hal_gpio_set_direction(self->port, self->bit, output);
}

/**
 * @brief Establece el estado lógico de un pin configurado como salida.
 *
 * Esta función establece el estado lógico del pin (alto o bajo) si está configurado como salida.
 *
 * @param self Instancia de gpio_t que representa el pin.
 * @param state Estado lógico del pin : true = alto, false = bajo.
 */
void gpioSetState(gpio_t self, bool state) {
    if (self->output) {
        hal_gpio_set_output(self->port, self->bit, state);
    }
}

/**
 * @brief Obtiene el estado lógico de un pin configurado.
 *
 * Esta función lee el estado lógico del pin, si está configurado como entrada.
 *
 * @param self Instancia de gpio_t que representa el pin.
 *
 * @return El estado lógico del pin: true = alto, false = bajo).
 */
bool gpioGetState(gpio_t self) {
    return hal_gpio_get_input(self->port, self->bit);
}

/* === End of documentation ==================================================================== */
