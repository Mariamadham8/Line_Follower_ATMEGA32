/*
 * main2.c
 *
 *  Created on: Oct 31, 2024
 *      Author: Mariem
 */
/*

#include <avr/io.h>








#include <util/delay.h>

#define LEFT_SENSOR_PIN 0
#define RIGHT_SENSOR_PIN 1

#define LEFT_SENSOR  (PIND & (1 << LEFT_SENSOR_PIN))
#define RIGHT_SENSOR (PIND & (1 << RIGHT_SENSOR_PIN))

uint8_t debounce_sensor(uint8_t sensor_pin) {
    uint8_t stable_state = PIND & (1 << sensor_pin);
    for (int i = 0; i < 5; i++) {
        _delay_ms(20);
        if ((PIND & (1 << sensor_pin)) != stable_state) {
            return 0;
        }
    }
    return stable_state ? 1 : 0;
}

int main()
{

	return 0;
}
*/
