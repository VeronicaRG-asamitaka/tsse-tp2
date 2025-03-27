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
 * @file main.c
 * @brief Implementación de las funciones principales para la manipulación de pines GPIO.
 *
 * Este archivo contiene las implementaciones de las funciones que permiten configurar,
 * leer y escribir en los pines GPIO. Estas funciones interactúan con la capa de hardware
 * para controlar los pines de entrada y salida.
 */

/* === Headers files inclusions =============================================================== */
#include "hal.h"

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

/**
 * @brief Establece la dirección de un pin GPIO.
 *
 * Esta función configura la dirección de un pin GPIO, especificando si el pin debe ser una
 * entrada o salida, dependiendo del valor del parámetro `direction`.
 *
 * @param port El puerto del pin GPIO.
 * @param bit El bit del pin del puerto.
 * @param direction Indica la dirección del pin.
 *
 * @note La implementación de esta función depende de la plataforma utilizada.
 */
void hal_gpio_set_direction(uint8_t port, uint8_t bit, bool direction) {
}

/**
 * @brief Establece el estado de salida de un pin GPIO.
 *
 * Esta función configura el estado lógico de un pin GPIO configurado como salida. El pin
 * se pondrá en estado alto (`true`) o bajo (`false`), dependiendo del valor del parámetro `state`.
 *
 * @param port El puerto del pin GPIO.
 * @param bit El bit del pin dentro del puerto.
 * @param state El estado lógico a establecer en el pin.
 *
 * @note La implementación de esta función depende de la plataforma utilizada.
 */
void hal_gpio_set_output(uint8_t port, uint8_t bit, bool state) {
}

/**
 * @brief Obtiene el estado lógico de un pin GPIO configurado como entrada.
 *
 * Esta función lee el valor lógico de un pin que está configurado como entrada.
 *
 * @param port El puerto del pin GPIO.
 * @param bit El bit del pin dentro del puerto.
 *
 * @return El estado lógico del pin GPIO.
 *
 * @note La implementación de esta función depende de la plataforma utilizada.
 */
bool hal_gpio_get_input(uint8_t port, uint8_t bit) {

    return false;
}

/* === End of documentation ==================================================================== */
