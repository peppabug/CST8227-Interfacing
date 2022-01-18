/*
  Calibration

  Demonstrates one technique for calibrating sensor input. The sensor readings
  during the first five seconds of the sketch execution define the minimum and
  maximum of expected values attached to the sensor pin.

  The sensor minimum and maximum initial values may seem backwards. Initially,
  you set the minimum high and listen for anything lower, saving it as the new
  minimum. Likewise, you set the maximum low and listen for anything higher as
  the new maximum.

  The circuit:
  - analog sensor (potentiometer will do) attached to analog input 0
  - LED attached from digital pin 9 to ground

  created 29 Oct 2008
  by David A Mellis
  modified 30 Aug 2011
  by Tom Igoe
  modified 09 March 2021
  ny Michael Turner

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Calibration
*/
/* Demo 1 */
////These constants won't change:
//const int sensorPin = 22;     // pin that the sensor is attached to
//const int ledPin = 14;        // pin that the LED is attached to
//
////variables:
//int sensorValue = 0;         // the sensor value
//int sensorMin = 1000;        // minimum sensor value
//int sensorMax = 0;           // maximum sensor value
//
//void setup() {
//// turn on LED to signal the stdisplart of the calibration period:
//  pinMode(ledPin, OUTPUT);
//
//  Serial.begin(38400);
//
//  // calibrate during the first five seconds
//  while (millis() < 5000) {
//    sensorValue = touchRead(sensorPin);
//    
//    digitalWrite(ledPin, HIGH);
//
//    Serial.println(sensorValue);
//
//    // record the maximum sensor value
//    if (sensorValue > sensorMax) {
//      sensorMax = sensorValue;
//    }
//
//    // record the minimum sensor value
//    if (sensorValue < sensorMin) {
//      sensorMin = sensorValue;
//    }
//  }
//
//  // signal the end of the calibration period
//  digitalWrite(ledPin, LOW);
//}
//
//void loop() {
//  // read the sensor:
//  sensorValue = touchRead(sensorPin);
//
//  // apply the calibration to the sensor reading
//  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);
//
//  // in case the sensor value is outside the range seen during calibration
//  sensorValue = constrain(sensorValue, 0, 255);
//
//  Serial.println(sensorValue);
//
//  // fade the LED using the calibrated value:
//  analogWrite(ledPin, sensorValue);
//
//  delay(100);
//}
/* End of Demo 1 */

/* Demo 2 */
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

int tempo = 108;

const int sensorPin = 15;
const int piezoPin = A1;
const int ledPin = 13;         // pin that the LED is attached to

int sensorValue = 0;
int sensorMin = 1000;
int sensorMax = 0;

int melody[] = {
  //1
  NOTE_AS4,8, NOTE_AS4,8, NOTE_AS4,8,
  NOTE_F5,2, NOTE_C6,2,
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,8, NOTE_C5,8, NOTE_C5,8,
  NOTE_F5,2, NOTE_C6,2,
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  //8
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,
  NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,-8, NOTE_C5,16, 
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C5,-8, NOTE_C5,16,
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  //13
  NOTE_C6,-8, NOTE_G5,16, NOTE_G5,2, REST,8, NOTE_C5,8,
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C6,-8, NOTE_C6,16,
  NOTE_F6,4, NOTE_DS6,8, NOTE_CS6,4, NOTE_C6,8, NOTE_AS5,4, NOTE_GS5,8, NOTE_G5,4, NOTE_F5,8,
  NOTE_C6,1
};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholeNote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(piezoPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  digitalWrite(piezoPin, LOW);
  
  Serial.begin(38400);

  // calibrate during the first five seconds
  while (millis() < 5000) {
    sensorValue = touchRead(sensorPin);
    digitalWrite(ledPin, HIGH);

    // record the maximum sensor value
    if (sensorValue > sensorMax) {
      sensorMax = sensorValue;
    }

    // record the minimum sensor value
    if (sensorValue < sensorMin) {
      sensorMin = sensorValue;
    }
  }

  // signal the end of the calibration period
  digitalWrite(ledPin, LOW);
}

void loop() {
  // read the sensor:
  sensorValue = touchRead(sensorPin);

  // apply the calibration to the sensor reading
  sensorValue = map(sensorValue, sensorMin, sensorMax, 0, 255);

  // in case the sensor value is outside the range seen during calibration
  sensorValue = constrain(sensorValue, 0, 255);

  // fade the LED using the calibrated value:
  analogWrite(ledPin, sensorValue);
  buzz(sensorValue);
}

void buzz(int sensorValue) {
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {
    divider = melody[thisNote + 1];
    if (divider > 0) {
      noteDuration = (wholeNote) / divider;
    } else if (divider < 0) {
      noteDuration = (wholeNote) / abs(divider);
      noteDuration *= 1.5;
    }
    tone(piezoPin, melody[thisNote], noteDuration * 0.9);
    delay(noteDuration);
    noTone(piezoPin);
  }
}
/* End of Demo 2 */
