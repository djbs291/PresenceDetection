#include <stdio.h>

#include "driver/gpio.h"
#include "pir.h"
#include "esp_log.h"

#define TAG "Presence"

struct _led_state led_state[LEDS_QUANTITY] = {
    {LIGHT_ON, LIGHT_OFF, GPIO_LED},
};

void readPIR(){
    int pir_read = gpio_get_level(GPIO_PIR);

    ESP_LOGI(TAG, "pir_read = %d", pir_read);

    if(pir_read){
        ESP_LOGI(TAG, "Motion detected");
        led_state[0].current = LIGHT_ON;
    } else {
        ESP_LOGI(TAG, "Motion not detected");
        led_state[0].current = LIGHT_OFF;
    }
}

static void init_pir(void){
    gpio_pad_select_gpio(GPIO_PIR);
    gpio_set_direction(GPIO_PIR, GPIO_MODE_INPUT);
}

void presence_init(void){
    init_pir();
}