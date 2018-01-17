#ifndef LED_CONTROL_INCLUDED
#define LED_CONTROL_INCLUDED

  #if defined(ARDUINO) && ARDUINO >= 100
    #include "arduino.h"
  #else
    #include "WProgram.h"
  #endif

class LED_control{
  
#pragma region protected
protected:

  unsigned long currentMillis = 0;
  unsigned long previousMillis = 0;        // will store last time LED was updated
  int period = 0;
  int interval = 0;
  
  int ledPin = LED_BUILTIN;
  
  void operate(); 
  void resetState();
  void toggle(bool reset);
  bool blinking = false;
  bool pulsing = false;
  bool pulseRising = false;
  float pulsingElapsed = 0;
  bool ledState = LOW;
  
#pragma endregion

#pragma region public

 public:
  LED_control();
  LED_control(int pin); 
  void On();
  void Off();
  void Pulse(int Period = 1000);
  void Blink(int Period = 1000);
  void Blink(int Period , int Interval);
  void Toggle();
  bool getState();
  void Update();

#pragma endregion

};

#endif /* LED_CONTROL_INCLUDED*/
