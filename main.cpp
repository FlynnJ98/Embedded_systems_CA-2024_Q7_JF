#include "mbed.h"
#include "string.h"
#include <cstdio>

/* Write an mbed OS program to toggle the LEDs with the intervals specified below
LED1 - every 2 seconds
LED2 - every 5 seconds

Created seperate void loops so the LED's can work independently with their respective delays as stated above.
Otherwise the LED's didnt work in the intervals set for the question which caused them to wait on eachother. 
*/

// Names of LED 1 & LED 2
DigitalOut led1(PA_5);
DigitalOut led2(PB_14);

//loop funtion to toggle LED 1
void toggle_led1() {
    while (1) {
// while the loop to true, LED 1 is not equal to LED 1
    led1 = !led1;
    ThisThread::sleep_for(2000ms); // 2 seconds delay
    }
}
//loop funtion to toggle LED 2
void toggle_led2() {
    while (1) {
// while the loop to true, LED 2 is not equal to LED 2
    led2 = !led2;
    ThisThread::sleep_for(5000ms); // 5 seconds delay
    }
}

int main() {
// Thread t1 & t2
    Thread t1;
    Thread t2;
//Start Thread 1, the void loop (Toggle_led1)
    t1.start(toggle_led1);
//Start Thread 2, the void loop (Toggle_led2)
    t2.start(toggle_led2);

//run this program while its true
    while (1) {
    ThisThread::sleep_for(1000ms); 
}
}