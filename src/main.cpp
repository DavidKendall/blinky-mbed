#include "mbed.h"
 
DigitalOut led1(LED1);
DigitalOut led_app_red(D5);
DigitalOut led_app_green(D9);

int main() {
    led_app_red = 1;
    while (true) {
        led1 = !led1;
        led_app_green = !led_app_green;
        wait(0.5);
    }
}
 
