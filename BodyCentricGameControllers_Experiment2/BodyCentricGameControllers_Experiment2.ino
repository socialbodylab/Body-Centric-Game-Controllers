
/**************************************************************************
   Body-Centric Game Controller Workshop
   Social Body Lab + Dames Making Games
   Working with Arduino Micro board and conductive materials
   A 10K potentiometer is connected to pin A0 for to control threshold (for calibration).
   11 textile sensors are connected to pins A1-A5.
   Used to control any browser game that uses keyboard arrows.

   Arduino Example code:
   https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardwrite/
   https://www.arduino.cc/en/Reference/KeyboardModifiers
   Keyboard Ascii References:
   http://www.asciitable.com/
   Social Body Lab, March 2019
**************************************************************************/
#include <Keyboard.h>

int threshold = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Keyboard.begin();
}

// the loop routine runs over and over again forever:
void loop() {
  threshold = analogRead(analogPotPin);
  int sensorValue = analogRead(A1); //Left
  int sensorValue2 = analogRead(A2); //Right
  int sensorValue3 = analogRead(A3); //Up
  int sensorValue4 = analogRead(A4); //Down

  // read the input on analog pin 0:

  if (sensorValue > threshold)
  {
    Keyboard.write(216);
    Serial.print("Left");
    delay(100);
  }

  else if (sensorValue2 > threshold)
  {
    Keyboard.write(215);
    Serial.print("Right");
    delay(100);
  }
  else if (sensorValue3 > threshold)
  {
    Keyboard.write(218);
    Serial.print("Up");
    delay(100);
  }
  else if (sensorValue4 > threshold)
  {
    Keyboard.write(217);
    Serial.print("Down");
    delay(100);
  }
  // print out the value you read:
  //  Serial.print("sensorValue = ");
  //  Serial.print(sensorValue);
  //  Serial.print("\t sensorValue2  = ");
  //  Serial.print(sensorValue2);
  //  Serial.print("\t sensorValue3  = ");
  //  Serial.print(sensorValue3);
  //  Serial.print("\t sensorValue4  = ");
  //  Serial.println(sensorValue4);

  delay(20);        // delay in between reads for stability
}
