#include <LED_control.h>

#define BLUE_LED_PIN 9
#define RED_LED_PIN 6
#define GREEN_LED_PIN 5
#define YELLOW_LED_PIN 3

LED_control BLUE_LED = LED_control(BLUE_LED_PIN);
LED_control RED_LED = LED_control(RED_LED_PIN);
LED_control GREEN_LED = LED_control(GREEN_LED_PIN);
LED_control YELLOW_LED = LED_control(YELLOW_LED_PIN);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BLUE_LED.Blink(1000);
  RED_LED.Blink(500);
  GREEN_LED.Blink(500);
  YELLOW_LED.Blink(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  BLUE_LED.Update();
  RED_LED.Update();
  GREEN_LED.Update();
  YELLOW_LED.Update();
}