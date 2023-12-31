// CHECK THE BUZZER 

#include<Arduino.h>

const int BUZZER = 4;

void setup(){
    pinMode(BUZZER , OUTPUT);

}


void loop(){
    int frequency [] = {200,400,600,800,1200,1400,1600,1800,2000};

    for(int a = 0 ; a< 10 ; a++){
        tone(BUZZER , frequency[a] , 100);
        delay(50);
    }

}