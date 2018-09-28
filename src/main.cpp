#include "mbed.h"
#include "C12832.h"
#include "MMA7660.h"
#include "LM75B.h"
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
MMA7660 accel(D14, D15);
float accelVal[3];
LM75B temp(D14, D15);
float tempVal;

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
        accelVal[0] = accel.x();
        accelVal[1] = accel.y();
        accelVal[2] = accel.z();
        tempVal = temp.read();
        led1 = !led1;
        led_app_green = !led_app_green;
        lcd.locate(0, 0);
        lcd.printf("L: %0.2f", pot1Val);
        lcd.locate(0, 8);
        lcd.printf("R: %0.2f", pot2Val);
        lcd.locate(0, 16);
        lcd.printf("J: %c", joystickVal);
        lcd.locate(43, 0);
        lcd.printf("X: %0.2f", accelVal[0]);
        lcd.locate(43, 8);
        lcd.printf("Y: %0.2f", accelVal[1]);
        lcd.locate(43, 16);
        lcd.printf("Z: %0.2f", accelVal[2]);
        lcd.locate(86, 0);
        lcd.printf("T: %02.2f", tempVal);
        wait(0.5);
    }
}
 
