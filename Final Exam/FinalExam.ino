/************************************************************
* Practical Question: Winter 2021
*
* Level Achieved: Level A+
*
* Status: Complete
*
* @author Michael Turner
*/

//minimum and maximum temperature readings for mode n
const float MIN_TEMP = 15.0;
const float MAX_TEMP = 33.0;

//shift register pins
const int SER = 14;
const int LATCH = 15;
const int CLOCK = 16;

//time interval variables
const int timePeriod = 1500;
unsigned int timeStart;
unsigned int timeNow;

//7-segment display common anode
const char commonAnode = 'a';

//temperature variables
int initReading;
float temperature;

//7-segment diaplay
byte segDisplay;

//mode variable
char mode;

void setup() {
  pinMode(SER, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);

  Serial.begin(9600);
  timeStart = millis();
  mode = 'n';
}

void loop() {
  //mode injections
  if (mode == 'n') initReading = analogRead(3);
  else if (mode == 'L') initReading = -80;
  else initReading = 800;

  //convert initial temperature reading to Celsius
  if (initReading <= 289) {
    temperature = 5 + (initReading - 289) / 9.82;
  }
  if (initReading > 289 && initReading <= 342) {
    temperature = 10 + (initReading - 342) / 10.60;
  }
  if (initReading > 342 && initReading <= 398) {
    temperature = 15 + (initReading - 398) / 11.12;
  }
  if (initReading > 398 && initReading <= 455) {
    temperature = 20 + (initReading - 455) / 11.36;
  }
  if (initReading > 455 && initReading <= 512) {
    temperature = 25 + (initReading - 512) / 11.32;
  }
  if (initReading > 512 && initReading <= 566) {
    temperature = 30 + (initReading - 566) / 11.00;
  }
  if (initReading > 566 && initReading <= 619) {
    temperature = 35 + (initReading - 619) / 10.44;
  }
  if (initReading > 619 && initReading <= 667) {
    temperature = 40 + (initReading - 667) / 9.73;
  }
  if (initReading > 667) {
    temperature = 45 + (initReading - 712) / 8.90;
  }

  //update displayed mode on 7-segment display
  if (temperature >= MIN_TEMP && temperature <= MAX_TEMP) segDisplay = tempToMode('n');
  else if (temperature < MIN_TEMP) segDisplay = tempToMode('L');
  else segDisplay = tempToMode('H');
  updateDisplay(segDisplay);

  //time intervals for serial output
  //change from mode n, to L, to H, to n...
  timeNow = millis();
  if (timeNow - timeStart >= timePeriod) {
    if (mode == 'n') mode = 'L';
    else if (mode == 'L') {
      Serial.println("INJECT: LOW");
      mode = 'H';
    }
    else {
      Serial.println("INJECT: HIGH");
      mode = 'n';
    }
    Serial.print("Temperature: ");
    Serial.print(initReading);
    Serial.print(" (raw), ");
    Serial.print(temperature, 2);
    Serial.print(" Celsius");
    Serial.println("");
    Serial.println("--------------------------------------");
    
    timeStart = timeNow;
  }
}

void updateDisplay(byte segDisplay) {
  if (commonAnode == 'a') {
    segDisplay = segDisplay ^ B11111111;
  }

  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLOCK, LSBFIRST, segDisplay);
  digitalWrite(LATCH, HIGH);
}

byte tempToMode(char mode) {
  switch (mode) {
  case 'n': return B00101010;
    break;
  case 'L': return B00011101;
    break;
  case 'H': return B01101111;
    break;
  default: return B10010010;
    break;
  }
}
