// LETS CHECK THE SWITCH
#include<Arduino.h>

const int switch_one = 3;
const int switch_two = 4;
const int switch_three = 5;
const int switch_four = 6;

void setup(){
    Serial.begin(9600);

    pinMode(switch_one , INPUT);
    pinMode(switch_two , INPUT);
    pinMode(switch_three , INPUT);
    pinMode(switch_four , INPUT);



}

void loop(){
    int switch_value = digitalRead(switch_one);
    int switch_value_two = digitalRead(switch_two);
    int switch_value_three = digitalRead(switch_three);
    int switch_value_four = digitalRead(switch_four);

    Serial.print("switch one = ");
    Serial.print(switch_value);
    Serial.print(",");

    Serial.print("switch two = ");
    Serial.print(switch_value_two);
    Serial.print(",");
    

    Serial.print("switch three = ");
    Serial.print(switch_value_three);
    Serial.print(",");
    

    Serial.print("switch four = ");
    Serial.println(switch_value_four);
    
    





}