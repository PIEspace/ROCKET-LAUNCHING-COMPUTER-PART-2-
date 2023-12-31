// RECEIVER :--------

#include<Arduino.h>
#include<FastLED.h>
#include<Wire.h>
#include<LiquidCrystal_I2C.h>
#include<SPI.h>
#include<nRF24L01.h>
#include<RF24.h>


// define the ws2812-b number of leds and led pin number 
#define LED_PIN  9  
#define NUM_LEDS 1 

CRGB led [NUM_LEDS];


// define the buzzer 
const int BUZZER = 2;

// define the pushbutton
const int FIRST_BUTTON = 3;
const int SECOND_BUTTON = 4;
const int THIRD_BUTTON = 5;
const int FOUR_BUTTON = 6;


// define the liquidCrystal lcd display 16x2
LiquidCrystal_I2C LCD_DISPLAY (0x27 , 16 , 2);



// define the rf24 radio and address 
const int CE_PIN = 7 ;
const int CNS_PIN = 8;
RF24 radio(CE_PIN , CNS_PIN);
const byte address[][6] = {"7870" , "78702"};

// write a startup code 
void buzzer_tone_first(){
    int frequency [] = {200,400,600,800,1000,1200,1400,1600,1800,2000};
    for(int first_tone = 0 ; first_tone < 10 ; first_tone++)
    {
        tone(BUZZER,frequency[first_tone] , 100);
        delay(50);
    }
    noTone(BUZZER);
    delay(100);

    int frequency_second [] = {300,600,900,1200,1500,1800,2100,2400,2700,3000};
    for(int second_tone = 0 ; second_tone < 10 ; second_tone++)
    {
        tone(BUZZER,frequency[second_tone] , 100);
        delay(50);
    }
    noTone(BUZZER);
    delay(100);

}

void lcd_display_second(){
    LCD_DISPLAY.print("PIE.SPACE");
}

void ws2812b_led_glow(){

    for(int four_value = 0 ; four_value < 5 ; four_value++){
        // glow = red 
        fill_solid(led, NUM_LEDS, CRGB::Red);
        FastLED.show();
        delay(100);

        // glow = green 
        fill_solid(led, NUM_LEDS, CRGB:: Green);
        FastLED.show();
        delay(100);

        // glow = blue
        fill_solid(led, NUM_LEDS, CRGB::Blue);
        FastLED.show();
        delay(100);

        // flow = pink
        fill_solid(led, NUM_LEDS, CRGB::Pink);
        FastLED.show();
        delay(100);

        // flow = orange
        fill_solid(led, NUM_LEDS, CRGB::Orange);
        FastLED.show();
        delay(100);
    }

    fill_solid(led, NUM_LEDS, CRGB::Black);
    FastLED.show();
    delay(100);

}


void buzzer_first_pyro_channel_start()
{

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


// define the millis 
unsigned long previoustime = 0 ;
int delay_value = 500;

void lcd_write(){
    unsigned long currenttime = millis();
    if(currenttime - previoustime >= delay_value){
        previoustime = currenttime;

        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("COUNTDOWN START");
        delay(3000);
        LCD_DISPLAY.clear();

        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-20");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();

        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-19");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-18");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-17");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-16");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-15");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-14");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-13");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-12");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-11");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-10");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-09");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-08");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-07");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-06");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-05");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();



        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-04");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-03");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-02");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();



        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-01");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-00");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();

        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("____FIRE____");
        delay(1000);
        LCD_DISPLAY.clear();


       

    }
}


// void define the 10 second delay 


unsigned long previousVALUE = 0 ;
int delay_value_ONE = 500;

void lcd_write_one(){
    unsigned long currenttime_value = millis();
    if(currenttime_value - previousVALUE >= delay_value_ONE){
        previousVALUE = currenttime_value;

        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("COUNTDOWN START");
        delay(3000);
        LCD_DISPLAY.clear();

        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-10");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();

        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-09");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-08");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-07");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-06");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-05");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-04");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-03");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-02");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-01");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("ROCKET LAUNCH IN");
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("T-00");
        digitalWrite(BUZZER , HIGH);
        delay(1000);
        digitalWrite(BUZZER , LOW);
        delay(1000);
        LCD_DISPLAY.clear();


        LCD_DISPLAY.setCursor(0,0);
        LCD_DISPLAY.print("____FIRE____");
        delay(1000);
        LCD_DISPLAY.clear();




    }

}



void setup(){
    // define the bud rate
    // in this case i am using 9600 bits per second 
    Serial.begin(9600);

    // define the ws2812-b led stripe 
    FastLED.addLeds<WS2812B , LED_PIN , GRB>(led , NUM_LEDS);

    // define the buzzer 
    pinMode(BUZZER , OUTPUT);
    // define the button
    pinMode(FIRST_BUTTON , INPUT);
    pinMode(SECOND_BUTTON , INPUT);
    pinMode(THIRD_BUTTON , INPUT);
    pinMode(FOUR_BUTTON , INPUT);

    // initialize the lcd (liquid crystal lcd display )
    LCD_DISPLAY.init();
    LCD_DISPLAY.backlight();

    // initialize the rf24 radio
    radio.begin();
    radio.openWritingPipe(address[0]);
    radio.openReadingPipe(1,address[1]);
    radio.setPALevel(RF24_PA_HIGH);


    // start the startup code 
    buzzer_tone_first();
    lcd_display_second();
    ws2812b_led_glow();
    buzzer_tone_first();
}

void loop(){

    // radio.startListening();

    // if(radio.available()){
    //     char text[32] ="";
    //     radio.read(&text , sizeof(text));
    //     Serial.println(text);
    // }

    radio.stopListening();
    int buttonstate = digitalRead(FIRST_BUTTON);

    if(buttonstate == HIGH){

        buzzer_first_pyro_channel_start();
        LCD_DISPLAY.clear();
        lcd_write();
        radio.write(&buttonstate , sizeof(buttonstate));
    }

    else if (buttonstate == LOW)
    {
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("____PIE.SPACE____");

    }


    // DEFINE THE ANTHER BUTTON 
    int buttonstate_one = digitalRead(SECOND_BUTTON);
    if(buttonstate_one == HIGH){
        buzzer_first_pyro_channel_start();
        LCD_DISPLAY.clear();
        lcd_write_one();

        radio.write(&buttonstate_one , sizeof(buttonstate_one));

    }

    else if (buttonstate_one == LOW)
    {
        LCD_DISPLAY.setCursor(0,1);
        LCD_DISPLAY.print("____PIE.SPACE____");

    }

}