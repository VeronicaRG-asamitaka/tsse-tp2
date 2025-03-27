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
 * @file leds.c
 * @brief Definiciones de la biblioteca para el control de LEDs.
 */

/* === Headers files inclusions =============================================================== */

#include "leds.h"

/* === Macros definitions ====================================================================== */

/** @brief Puerto en el que se encuentra el led rojo. */
#define LED_RED_PORT 1

/** @brief Pin de bit en el puerto donde está conectado el led rojo. */
#define LED_RED_BIT 7

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */
static uint16_t * portAdress;
/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */

/**
 * @brief Función principal del programa.
 *
 * Esta función se ejecuta al iniciar el sistema. En ella se crea un objeto `gpio_t` para el
 * control de un led rojo, se configura el pin correspondiente como salida y se ajusta su estado
 * para que esté apagado.
 *
 * - Se crea un objeto `gpio_t` para el led rojo en el puerto y bit especificados.
 * - Se configura el pin como salida.
 * - Se establece el estado del pin en bajo.
 *
 * @return int Valor de retorno: 0 si todo se ejecuta correctamente.
 */

 
 void LedsInit(uint16_t * adressLeds){
    portAdress = adressLeds;
    *portAdress = 0;
 }

 void LedTurnOnSingle(uint8_t numberLed){
    //if(16 <= numberLed && numberLed >= 1){
       // *portAdress |=(1 << (numberLed - 1));
       *portAdress = 0x0008;

    //}
 }

 void LedTurnOffSingle(uint8_t numberLed){

    //*portAdress &= (1 << (numberLed - 1));
    *portAdress = 0x0000;
 }

/* === End of documentation ==================================================================== */
