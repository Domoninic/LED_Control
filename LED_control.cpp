#include "LED_control.h"

LED_control::LED_control(int pin) {
  ledPin = pin;
  LED_control();
  }

LED_control::LED_control() {
  pinMode(ledPin, OUTPUT); 
  operate(); // turn off the LED
  }

void LED_control::operate(){
  digitalWrite(ledPin, ledState);
  }
  
void LED_control::resetState(){
	interval = period = pulsingElapsed = 0;
	blinking = pulsing = pulseRising = false;
}

void LED_control::toggle(bool reset){
	if (reset) {
		resetState();
	}
	ledState = !ledState;
	operate();
}

void LED_control::Update() {

	currentMillis = millis();
	if ( (blinking) && (((ledState) && (currentMillis - previousMillis >= period)) || ((!ledState) && (currentMillis - previousMillis >= interval))) ){
			// save the last time you blinked the LED
			previousMillis = currentMillis;
			toggle(false); 
		}
	else if (pulsing) {
		pulsingElapsed =  (float)(currentMillis - previousMillis) / (float)period;
		
		if (pulsingElapsed >= 1 ) {
			pulseRising = !pulseRising;
			previousMillis = currentMillis;
		}
		if ( pulseRising ) {
			analogWrite( ledPin , (int)(pulsingElapsed * 255.0) );
		} else {
			analogWrite( ledPin , (int)(255.0 - pulsingElapsed * 255.0) );
		}
	}
}

void LED_control::On(){
	resetState();
  ledState = HIGH;
  operate();
  }

void LED_control::Off(){
  resetState();
  ledState = LOW;
  operate();
  }
  
 void LED_control::Pulse(int Period){
	 resetState();
	period = Period;
	pulsingElapsed = 0;
	pulsing = true;
  }

void LED_control::Blink (int Period){
  Blink(Period, Period);
  }

  void LED_control::Blink (int Period, int Interval){
	  resetState();
  On(); //turn LED ON  
  previousMillis = millis();
  period = Period;
  interval = Interval;
  blinking = true;
  }

void LED_control::Toggle(){
	toggle(true);
  }

bool LED_control::getState(){
  return ledState;
  }

