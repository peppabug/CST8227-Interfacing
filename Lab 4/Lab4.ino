const int ledRed = 23;
const int ledBlue = 21;
const int ledGreen = 20;
const int pbIn = 7;
const int pbPU = 8;

void setup() {
  Serial.begin(38400);
  pinMode(pbIn, INPUT);
  pinMode(pbPU, INPUT_PULLUP);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
}

int redIntensity = 0;
int mode = 0;

void loop() {
  analogWrite(ledRed, redIntensity);
  if (mode == 0) {
    analogWrite(ledGreen, 255 - redIntensity);
    analogWrite(ledBlue, 0);
  } else {
    analogWrite(ledGreen, 0);
    analogWrite(ledBlue, 255 - redIntensity);
  }
  
  if (digitalRead(pbIn) == LOW) {
    mode = 0;
    Serial.println("Mode 0");
  }
  if (digitalRead(pbPU) == LOW) {
    mode = 1;
    Serial.println("Mode 1");
  }
  delay(10);

  redIntensity = redIntensity + 1;

  if (redIntensity > 255) {
    redIntensity = 0;
  }
}
