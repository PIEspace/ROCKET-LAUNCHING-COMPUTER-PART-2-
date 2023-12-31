// lets check the led 


#include<Arduino.h>

const int first_led = A0;
const int second_led = A1;
const int third_led = A2;
const int four_led = A3;


void setup(){
    pinMode(first_led , OUTPUT);
    pinMode(second_led , OUTPUT);
    pinMode(third_led , OUTPUT);
    pinMode(four_led , OUTPUT);
}

void loop(){
    digitalWrite(first_led , HIGH);
    digitalWrite(second_led , HIGH);
    digitalWrite(third_led , HIGH);
    digitalWrite(four_led , HIGH);
    delay(1000);
    digitalWrite(first_led , LOW);
    digitalWrite(second_led , LOW);
    digitalWrite(third_led , LOW);
    digitalWrite(four_led , LOW);
    delay(1000);
}