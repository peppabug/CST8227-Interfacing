/* Demo 1 */
//const int ledRed = 23;
//const int ledBlue = 21;
//const int ledGreen = 20;

void setup()   {
/* Demo 1 */
//  pinMode(ledRed, OUTPUT);
//  pinMode(ledGreen, OUTPUT);
//  pinMode(ledBlue, OUTPUT);

/* Demo 2 */
  Serial.begin(38400);
}

/* Demo 1 */
//int redIntensity = 0;

/* Demo 2 */
int code;
float celsius;
float fahrenheit;

void loop()                     
{
/* Demo 1 */
//  redIntensity = analogRead(0) / 4;
//  
//  analogWrite(ledRed, redIntensity);
//  analogWrite(ledGreen, 255 - redIntensity);
//  analogWrite(ledBlue, 0);
//
//  delay(10);

/* Demo 2 */
  code = analogRead(1);
  if (code <= 289) {
    celsius = 5 + (code - 289) / 9.82;
  }
  if (code > 289 && code <= 342) {
    celsius = 10 + (code - 342) / 10.60;
  }
  if (code > 342 && code <= 398) {
    celsius = 15 + (code - 398) / 11.12;
  }
  if (code > 398 && code <= 455) {
    celsius = 20 + (code - 455) / 11.36;
  }
  if (code > 455 && code <= 512) {
    celsius = 25 + (code - 512) / 11.32;
  }
  if (code > 512 && code <= 566) {
    celsius = 30 + (code - 566) / 11.00;
  }
  if (code > 566 && code <= 619) {
    celsius = 35 + (code - 619) / 10.44;
  }
  if (code > 619 && code <= 667) {
    celsius = 40 + (code - 667) / 9.73;
  }
  if (code > 667) {
    celsius = 45 + (code - 712) / 8.90;
  }
  fahrenheit = celsius * 1.8 + 32;
  Serial.print("temperature: ");
  Serial.print(celsius);
  Serial.print(" Celsius, ");
  Serial.print(fahrenheit);
  Serial.println(" Fahrenheit");
  delay(1000);
}
