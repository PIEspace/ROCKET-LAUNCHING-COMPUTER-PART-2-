

#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// DEFINE THE BUZZER 
const int BUZZER = 4;

// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4

#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

// Hardware SPI connection
MD_Parola LCD = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
// Arbitrary output pins
// MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

void buzzer_startup_tone(){

    int frequency_first[] = {200,400,600,800,1000,1200,1400,1600,1800,2000};

    for(int first_vaue = 0 ; first_vaue < 10 ; first_vaue++){
        tone(BUZZER,frequency_first[first_vaue] , 100);
        delay(50); //delay for 50 millisecond for realstic sound 
    }

    // define for the hard tone 
    for(int second_value = 0 ; second_value < 4 ; second_value++){
        tone(BUZZER , 300);
        tone(BUZZER , 600);
        tone(BUZZER , 900);
        tone(BUZZER , 1200);
        tone(BUZZER , 1500);
        tone(BUZZER , 1800);
        
        delay(100);
    }
    noTone(BUZZER);
    delay(100);

}

void setup(void)
{
    // in this case i am using 9600 bits per second(bps)
    Serial.begin(9600);
    // define the lcd
    LCD.begin();
    // define the buzzer 
    pinMode(BUZZER , OUTPUT);
    buzzer_startup_tone();
}

void loop(void)
{
  if (LCD.displayAnimate())
    LCD.displayText("Hello", PA_CENTER, LCD.getSpeed(), 1000, PA_SCROLL_DOWN, PA_SCROLL_DOWN);


}
