//these teensy pins are PWM capable pins
int greenLED = 20;//3.0V, ~33ohm or bigger - LEDs turn ON with very little current so the 220 ohm that came with the tri-color LED are fine
int blueLED = 21;//2.3V, ~111ohm
int redLED = 23;//1.6V, ~189ohm

int pushButton = 10;
volatile int counter = 0;

long dutyCycleRandNumber;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(blueLED,  OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED,   OUTPUT);

  pinMode(pushButton, INPUT);
  pinMode(A0, INPUT);//use this open circuited pin for a seed to the random number generator

  //TODO: Demo #4, Lab03
  //README: https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
  attachInterrupt( pushButton, cycleRGB, FALLING );
}

void loop() {
//   put your main code here, to run repeatedly:

//   DEMO 1
//   int myDelay = 800;
//   digitalWrite(redLED, HIGH);
//   delay(myDelay);
//   digitalWrite(redLED, LOW);
//
//   digitalWrite(greenLED, true);
//   delay(myDelay);
//   digitalWrite(greenLED, false);
//
//   digitalWrite(blueLED, 1);
//   delay(myDelay);
//   digitalWrite(blueLED, 0);

//    DEMO 2
//    randomSeed(analogRead(A0));
//    dutyCycleRandNumber = random(256);
//    analogWrite(redLED, dutyCycleRandNumber);
//
//    dutyCycleRandNumber = random(256);
//    analogWrite(greenLED, dutyCycleRandNumber);
//
//    dutyCycleRandNumber = random(256);
//    analogWrite(blueLED, dutyCycleRandNumber);
//
//    delay(500);

//  DEMO 3
//  randomSeed(analogRead(A0));
//  randomLights();
//  
//  if ( digitalRead(pushButton) == LOW ) {
//    counter++;
//    if ( counter > 10 ) counter = 1;  // reset counter after 10 presses
//    Serial.print("Press (freeze).... counter is: ");
//    Serial.println( counter );
//    delay(1000);  // freeze lights of LED
//  }
//  
//  while ( counter > 0 && counter < 10 ) {
//    if( digitalRead(pushButton) == LOW ) {
//      counter++;
//      Serial.print("Another Press (random)... counter is: ");
//      Serial.println( counter );
//      randomLights();
//    }   
//  }

//  DEMO 4
  randomLights();
} //end loop()

//DEMO 3 and 4 continued
void randomLights() {
  dutyCycleRandNumber = random(256);
  analogWrite(redLED, dutyCycleRandNumber);
  
  dutyCycleRandNumber = random(256);
  analogWrite(greenLED, dutyCycleRandNumber);
  
  dutyCycleRandNumber = random(256);
  analogWrite(blueLED, dutyCycleRandNumber);
  
  delay(500);
}

//  DEMO 4 continued
void cycleRGB() {
  int onPin, offPin_1, offPin_2;

  counter++;
  //FIXME: no I/O in ISR; only here for teaching purposes
  Serial.println( "cycleRBG() ISR");
  Serial.print( "counter: ");
  Serial.println( counter );

  int beacon = counter % 3;
  
  if ( beacon == 0 ) {
    onPin = redLED;
    offPin_1 = greenLED;
    offPin_2 = blueLED;
  } else if ( beacon == 1 ) {
    onPin = greenLED;
    offPin_1 = redLED;
    offPin_2 = blueLED;
  } else { // must be Blue
    onPin = blueLED;
    offPin_1 = redLED;
    offPin_2 = greenLED;
  }
  
  analogWrite(onPin, HIGH);
  analogWrite(offPin_1, LOW);
  analogWrite(offPin_2, LOW);
  delay(200);
}
