#include "mbed.h"
#include "C12832.h"
#include <stdio.h>

DigitalOut led1(LED1);
DigitalOut led_app_red(D5);
DigitalOut led_app_green(D9);
C12832 lcd(D11, D13, D12, D7, D10);
AnalogIn pot1(A0); // Pot 1 - Left
AnalogIn pot2(A1); // Pot 2 - Right
float pot1Val;
float pot2Val;
DigitalIn joystick[5] = {D4, A2, A3, A4, A5};
char symbols[] = {'C', 'U', 'D', 'L', 'R'};
char joystickVal;

int main() {
    int i;

    lcd.cls();
    led_app_red = 1;

    while (true) {
        pot1Val = pot1.read();
        pot2Val = pot2.read();
        joystickVal = '-';
        for (i = 0; i < 5; i+=1) {
            if (joystick[i] == 1) {
                joystickVal = symbols[i];
                break;
            }
        }
        led1 = !led1;
        led_app_green = !led_app_green;
        lcd.locate(0, 0);
        lcd.printf("L: %0.2f", pot1Val);
        lcd.locate(0, 8);
        lcd.printf("R: %0.2f", pot2Val);
        lcd.locate(0, 16);
        lcd.printf("J: %c", joystickVal);
        wait(0.5);
    }
}
 
