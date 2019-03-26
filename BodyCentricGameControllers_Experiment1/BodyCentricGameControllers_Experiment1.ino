
/**************************************************************************
 * Body-Centric Game Controller Workshop 
 * Social Body Lab + Dames Making Games
 * Working with Arduino Micro board and conductive materials
 * A 10K potentiometer is connected to pin A0 for to control threshold (for calibration). 
 * 11 textile sensors are connected to pins A1-A11. 
 * Used to control the game Patatap: https://patatap.com/ 
 * 
 * Arduino Example code:
 * https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardwrite/
 * https://www.arduino.cc/en/Reference/KeyboardModifiers
 * Keyboard Ascii References:
 * http://www.asciitable.com/
 * Social Body Lab, March 2019
**************************************************************************/


#include <Keyboard.h>

const int numSensors = 11; //when changing the numSensors, put the same number of zeroes in sensorValue[] below
const int analogPotPin = A0;

int threshold = 0;
int sensorValue[] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
}; //Same number of zeros as numSensors

void setup() {
  Serial.begin(9600);
  Keyboard.begin(); 
}

void loop() {
  threshold = analogRead(analogPotPin);
  Serial.print("Threshold: ");
  Serial.println(threshold);
 
  for (int i = 0; i < numSensors; i++) {
    sensorValue[i] = analogRead(i+1);           //it is ok to refer to A0, A1, A2 as 0, 1, 2 for analogRead (but not for analogWrite())
                                                //SensorValue[0] is read from analog pin 1.
    if (sensorValue[i] > threshold)  {
      Keyboard.write(97 + i);
      Serial.println(char(97 + i));                   //ASCII code for 'a' is 97, 'b' is 98, etc
      delay(200);                                    //wait (in milliseconds) to prevent rapidly pressing the key repeatedly
    }
    Serial.print("\t"); 
    Serial.print(sensorValue[i]);
  }
  Serial.println(); 
  delay(1);        // delay in between reads for stability  

}
   
