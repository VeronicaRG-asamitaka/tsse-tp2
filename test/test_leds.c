/************************************************************************************************
Copyright (c) 2025, Veronica Ruiz Galvan <veronica.ruizgalvan@hotmail.com>

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
 * @file test_led.c
 * @brief Pruebas unitarias de la biblioteca para el control de LEDs
 **/

/**

 */

/* === Headers files inclusions =============================================================== */

#include "unity.h"
#include "leds.h"

/* === Macros definitions ====================================================================== */

/** @brief Puerto en el que se encuentra el led rojo. */
#define LED_RED_PORT 1

/** @brief Pin de bit en el puerto donde está conectado el led rojo. */
#define LED_RED_BIT 7

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */
static uint16_t leds_virtuals = 0xFFFF;
static uint16_t all_leds_on = 0xFFFF;
static uint16_t all_leds_off = 0x0000;
static uint8_t led_virtual_cuatro = 4;
static uint8_t led_virtual_seis = 6;
static uint8_t led_virtual_ocho = 8;
static uint8_t led_virtual = 5;
static uint8_t led_virtual_min = 1;
static uint8_t led_virtual_max = 16;
static uint8_t led_virtual_out_min = 0;
static uint8_t led_virtual_out_max = 17;
/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */
void setUp(void) {

    LedsInit(&leds_virtuals);
}

/**
 * @brief Función principal del programa.
 *
 *
 * @return int Valor de retorno: 0 si todo se ejecuta correctamente.
 */

//! * @test 1. Con la inicialización todos los LEDs quedan apagados.
void test_todos_los_leds_inician_apagados(void) {
    uint16_t leds_virtuals = 0xFFFF;

    LedsInit(&leds_virtuals);
    TEST_ASSERT_EQUAL_HEX16(0x0000, leds_virtuals);
}

//! * @test  2. Prender un LED individual.
void test_encender_led_individual(void) {
    LedTurnOnSingle(led_virtual_cuatro);
    TEST_ASSERT_EQUAL_HEX16(0x0008, leds_virtuals);
}

//! * @test  3. Apagar un LED individual.
void test_apagar_led_individual(void) {
    LedTurnOnSingle(led_virtual_cuatro);
    LedTurnOffSingle(led_virtual_cuatro);
    TEST_ASSERT_EQUAL_HEX16(0x0000, leds_virtuals);
}

//! * @test  4. Prender y apagar múltiples LED’s.
void test_encender_y_apagar_multiples_leds(void) {
    LedTurnOnSingle(led_virtual_cuatro);
    LedTurnOnSingle(led_virtual_seis);

    LedTurnOffSingle(led_virtual_cuatro);
    LedTurnOffSingle(led_virtual_ocho);

    TEST_ASSERT_EQUAL_HEX16(0x0020, leds_virtuals);
}

//! * @test  5. Prender todos los LEDs de una vez.
void test_prender_todos_los_leds(void) {
    LedChangeStateAll(all_leds_on);

    TEST_ASSERT_EQUAL_HEX16(0xFFFF, leds_virtuals);
}

//! * @test  6. Apagar todos los LEDs de una vez.
void test_apagar_todos_los_leds(void) {
    LedChangeStateAll(all_leds_on);
    LedChangeStateAll(all_leds_off);

    TEST_ASSERT_EQUAL_HEX16(0x0000, leds_virtuals);
}

//! * @test  7. Consultar el estado de un LED que está encendido
void test_consultar_estado_led_encendido(void) {
    LedTurnOnSingle(led_virtual);

    TEST_ASSERT_EQUAL(1, LedGetState(led_virtual));
}

//!* @test  8. Consultar el estado de un LED que est apagado
void test_consultar_estado_led_apagado(void) {
    LedTurnOnSingle(led_virtual);
    LedTurnOffSingle(led_virtual);

    TEST_ASSERT_EQUAL(0, LedGetState(led_virtual));
}

//! * @test  9. Revisar limites de los parametros.
void test_limites_parametros(void) {

    TEST_ASSERT_EQUAL(1, isLedValid(led_virtual_min));
    TEST_ASSERT_EQUAL(1, isLedValid(led_virtual_max));
}
//! * @test  10. Revisar parámetros fuera de los limites.
void test_parametros_fuera_de_limites(void) {
    TEST_ASSERT_EQUAL(0, isLedValid(led_virtual_out_min));
    TEST_ASSERT_EQUAL(0, isLedValid(led_virtual_out_max));
}

/* === End of documentation ==================================================================== */
