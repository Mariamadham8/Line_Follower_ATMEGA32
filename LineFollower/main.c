/*
 * main.c
 *
 *  Created on: Oct 27, 2024
 *      Author: Mariem
 */



//#include <avr/io.h>
#include"stdTypes.h"
#include"errorStates.h"

#include"DIO_int.h"
#include"DIO_config.h"

#include <util/delay.h>

#define LEFT_SENSOR_PIN 0
#define RIGHT_SENSOR_PIN 1

#define LEFT_SENSOR  (PIND & (1 << LEFT_SENSOR_PIN))
#define RIGHT_SENSOR (PIND & (1 << RIGHT_SENSOR_PIN))


uint8_t debounce_sensor(uint8_t sensor_pin) {
    uint8_t stable_state = PIND & (1 << sensor_pin);
    for (int i = 0; i < 5; i++) {
        _delay_ms(5);
        if ((PIND & (1 << sensor_pin)) != stable_state) {
            return 0;
        }
    }
    return stable_state ? 1 : 0;
}


int main() {
   // DDRD = 0b11111100;
    for(int i=0;i<=1;i++)
    {
    	enuSetPinDirection(DIO_PORTD,i ,INPUT);
    }
    for(int i=2;i<=7;i++)
    {
    	enuSetPinDirection(DIO_PORTD,i ,OUTPUT);
    }


    while (1) {
        uint8_t left_state = debounce_sensor(LEFT_SENSOR_PIN);
        uint8_t right_state = debounce_sensor(RIGHT_SENSOR_PIN);

        if (left_state == 0 && right_state == 1) {
        	enuSetPinValue(DIO_PORTD,DIO_PIN3 ,HIGH);
        	enuSetPinValue(DIO_PORTD,DIO_PIN5 ,LOW);
        }
        else if (left_state == 1 && right_state == 0) {
        	enuSetPinValue(DIO_PORTD,DIO_PIN5 ,HIGH);
        	enuSetPinValue(DIO_PORTD,DIO_PIN3 ,LOW);
        }
        else if (left_state == 0 && right_state == 0) {
        	enuSetPinValue(DIO_PORTD,DIO_PIN3 ,HIGH);
        	enuSetPinValue(DIO_PORTD,DIO_PIN5 ,HIGH);
        }
        else {
        	enuSetPortValue(DIO_PORTD,0x00);
        }
    }

    return 0;
}


