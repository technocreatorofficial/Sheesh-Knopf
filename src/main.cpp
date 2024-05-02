#include "dmx.h"
#include "Arduino.h"
#define button_1 33
#define button_2 32

void setup() {
  Serial.begin(115200);
  DMX::Initialize(input);
pinMode(button_1, INPUT_PULLUP);
pinMode(button_2, INPUT_PULLUP);

}

void loop(){
  
  //lese alte Kanäle und schreibe
  for (int i = 1; i < 13; i++)
  {
    DMX::Write(i, DMX::Read(i));
  }

  //neue Kanäle schreiben

  if (digitalRead(button_1) == LOW)
  {
    DMX::Write(15, 255);
    Serial.println("Button 1 gedrückt");
  }
  else
  {
    DMX::Write(15, 0);
  }

  if (digitalRead(button_2) == LOW)
  {
    DMX::Write(16, 255);
    Serial.println("Button 2 gedrückt");
  }
  else
  {
    DMX::Write(16, 0);
  }

}