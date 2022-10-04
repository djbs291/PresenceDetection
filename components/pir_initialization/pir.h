#ifndef _PIR_H_
#define _PIR_H_

#include "sdkconfig.h"
#include "driver/gpio.h"

#define GPIO_LED GPIO_NUM_25
#define GPIO_PIR GPIO_NUM_26

#define LEDS_QUANTITY 1

#define LIGHT_ON           1
#define LIGHT_OFF          0

struct _led_state{
    uint8_t current;
    uint8_t previous;
    uint8_t pin;
};

void readPIR();

void presence_init(void);

#endif