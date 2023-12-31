
// transmitter code := 


#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


const int BUZZER = 4;
const int FIRST_LED = A0;
const int SECOND_LED = A1;
const int THIRD_LED = A2;
const int FOUR_LED = A3;
const int first_monFate = 8 ;




const int CE_PIN = 2;
const int CNS_PIN = 3;

RF24 radio(CE_PIN, CNS_PIN);
const byte address[][6] = {"7870", "78702"};


int buttonstate = 0;
int buttonstate_one = 0 ;



void buzzer_tone_first(){
    int buzzer_tone_frequency[] = {200, 400, 800, 1200, 1600, 2000, 2400, 2800, 3200, 3600, 4000};

    for (int buzzer_tone_value = 0; buzzer_tone_value < 11; buzzer_tone_value++)
    {
        tone(BUZZER, buzzer_tone_frequency[buzzer_tone_value], 100);
        delay(50);
    }

    int buzzer_tone_frequncy_second[] = {600, 1200, 1800, 2400, 3000, 3600, 4200, 4800, 5400, 6000};

    for (int large_tone = 0; large_tone < 10; large_tone++)
    {
        tone(BUZZER, buzzer_tone_frequncy_second[large_tone], 100);
        delay(150);
    }

    for (int beep_tone = 0; beep_tone < 3; beep_tone++)
    {

        tone(BUZZER, 1800);
        delay(100);
        noTone(BUZZER);

        tone(BUZZER, 2400);
        delay(100);
        noTone(BUZZER);

        tone(BUZZER, 1200);
        delay(100);
        noTone(BUZZER);

        digitalWrite(BUZZER, LOW);
        delay(50);
    }
}

void setup() {
    Serial.begin(9600);

    pinMode(BUZZER, OUTPUT);
    pinMode(FIRST_LED, OUTPUT);
    pinMode(SECOND_LED, OUTPUT);
    pinMode(THIRD_LED, OUTPUT);
    pinMode(FOUR_LED, OUTPUT);

    pinMode(first_monFate , OUTPUT);

    radio.begin();
    radio.openWritingPipe(address[1]);
    radio.openReadingPipe(1, address[0]);
    radio.setPALevel(RF24_PA_HIGH);


    buzzer_tone_first();

    
}

void loop() {
    
    // radio.stopListening();

    // const char text[] = "hello world";
    // radio.write(&text, sizeof(text));
    // delay(100);

    radio.startListening();
    
    radio.read(&buttonstate , sizeof(buttonstate));
    if(buttonstate == HIGH){
        digitalWrite(FIRST_LED , HIGH);
        digitalWrite(SECOND_LED , HIGH);
        digitalWrite(THIRD_LED , HIGH);
        digitalWrite(FOUR_LED , HIGH);
        digitalWrite(BUZZER , HIGH);
        digitalWrite(first_monFate , HIGH);
        delay(5000); //DELAY FOR 5 SECOND 
    }
    else if (buttonstate == LOW)
    {
        digitalWrite(FIRST_LED , LOW);
        digitalWrite(SECOND_LED , LOW);
        digitalWrite(THIRD_LED , LOW);
        digitalWrite(FOUR_LED , LOW);
        digitalWrite(BUZZER , LOW);
        digitalWrite(first_monFate , LOW);
        delay(1000);

    }


    radio.read(&buttonstate_one , sizeof(buttonstate_one));
    if(buttonstate_one == HIGH){
        digitalWrite(FIRST_LED , HIGH);
        digitalWrite(SECOND_LED , HIGH);
        digitalWrite(THIRD_LED , HIGH);
        digitalWrite(FOUR_LED , HIGH);
        digitalWrite(BUZZER , HIGH);
        digitalWrite(first_monFate , HIGH);
        delay(5000); //DELAY FOR 5 SECOND 
    }
    else if (buttonstate_one == LOW)
    {
        digitalWrite(FIRST_LED , LOW);
        digitalWrite(SECOND_LED , LOW);
        digitalWrite(THIRD_LED , LOW);
        digitalWrite(FOUR_LED , LOW);
        digitalWrite(BUZZER , LOW);
        digitalWrite(first_monFate , LOW);
        delay(1000);

    }
    
}
