// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include "Adafruit_NeoPixel.h"
#include "Ultrasonic.h"

Ultrasonic ultrasonic;
const int pin = 2; 
int dist_cm = 0;

#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            6
#define NUMPIXELS      30
#define SOUND          4

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 50;

bool is_open() {
  dist_cm = ultrasonic.UltrasonicRangerRead(pin);
  Serial.println(dist_cm);
 if (dist_cm > 20){
  return true;
 }
 else {
  return false;
 }
}

void setup() {
  Serial.begin(9600);
  pixels.begin(); 
}

void loop() {
    if (is_open()) {
    //Play sound
    digitalWrite(SOUND,HIGH);
   //Led on 
     for(int i=0;i<25;i++) {
      for(int j=0;j<NUMPIXELS;j++){
         pixels.setPixelColor(j, pixels.Color(255,0,0)); 
       }   
      pixels.setBrightness(250);
      pixels.show();
      delay(delayval); 
       for(int j=0;j<NUMPIXELS;j++){
         pixels.setPixelColor(j, pixels.Color(0,0,0)); 
       }   
      pixels.show();
      delay(delayval); 
     }
     //Sound Reset
    digitalWrite(SOUND,LOW);
  }
    else {
  //Led on green
    for(int i=0;i<200;i=i+20){
      for(int j=0;j<NUMPIXELS;j++){
         pixels.setPixelColor(j, pixels.Color(0,140,0)); 
       }
   
      pixels.setBrightness(i);
      pixels.show();
      delay(delayval); 
    }

    for(int i=201;i>0;i=i-20){
      pixels.setBrightness(i);
      pixels.show(); 
      delay(delayval); 
     }
      delay(50);
    }
}

