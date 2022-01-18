const int SER = 14; //data
const int LATCH = 15; //RCLK
const int CLOCK = 16; //SRCLK
const int delayTime = 200;

/* Demo 3 */
const char commonAnode = 'a';
volatile int counter = 0;
IntervalTimer timer;

/* Demo 2 */
//int numReg = 2;
//byte* stateReg; // I found a solution online that allows any number of shift registors

void setup() {
/*Demo 2 */
//  stateReg = new byte[numReg];
//
//  for (size_t i = 0; i < numReg; i++) {
//    stateReg[i] = 0;
//  }
//  
//  pinMode(SER, OUTPUT);
//  pinMode(CLOCK, OUTPUT);
//  pinMode(LATCH, OUTPUT);

/* Demo 3 */
  pinMode(SER, OUTPUT);
  pinMode(CLOCK, OUTPUT);
  pinMode(LATCH, OUTPUT);

/* Demo 4 */
  timer.begin(resetCounter, 7000000);
}

void loop() {
/* Demo 2 */
//  int prevByte = 0;
//
//  for (int currentByte = 0; currentByte < 16; currentByte++) {
//    byteShift(prevByte, HIGH);
//    byteShift(currentByte, HIGH);
//    prevByte = currentByte;
//    delay(delayTime);
//  }
//
//  for (int currentByte = 15; currentByte >= 0; currentByte--) {
//    byteShift(prevByte, LOW);
//    byteShift(currentByte, LOW);
//    prevByte = currentByte;
//    delay(delayTime);
//  }

  for (counter = 0; counter <= 99; counter++) {
    byte leftDisplay = numberToBits(counter / 10);
    byte rightDisplay = numberToBits(counter % 10);
    updateDisplay(leftDisplay, rightDisplay);
    delay(delayTime);
  }
}

/* Demo 2*/
//void byteShift(int pinData, bool state) {
//  int reg = pinData / 8;
//  int pin = pinData - (8 * reg);
//
//  digitalWrite(LATCH, LOW);
//
//  for (int i = 0; i < numReg; i++) {
//    byte* states = &stateReg[i];
//
//    if (i == reg) {
//      bitWrite(*states, pin, state);
//    }
//
//    shiftOut(SER, CLOCK, LSBFIRST, *states);
//  }
//  digitalWrite(LATCH, HIGH);
//}

void updateDisplay(byte leftDisplay, byte rightDisplay) {
  if (commonAnode == 'a') {
    leftDisplay = leftDisplay ^ B11111111;
    rightDisplay = rightDisplay ^ B11111111;
  }

  digitalWrite(LATCH, LOW);
  shiftOut(SER, CLOCK, LSBFIRST, rightDisplay);
  shiftOut(SER, CLOCK, LSBFIRST, leftDisplay);
  digitalWrite(LATCH, HIGH);
}

byte numberToBits(int num) {
  switch (num) {
    case 0: return B11111100;
      break;
    case 1: return B00001100;
      break;
    case 2: return B11011010;
      break;
    case 3: return B11110010;
      break;
    case 4: return B01100110;
      break;
    case 5: return B10110110;
      break;
    case 6: return B10111110;
      break;
    case 7: return B11100000;
      break;
    case 8: return B11111110;
      break;
    case 9: return B11110110;
      break;
    case 10: return B11101110;
      break;
    case 11: return B00111110;
      break;
    case 12: return B10011100;
      break;
    case 13: return B01111010;
      break;
    case 14: return B10001110;
      break;
    default: return B10010010;
      break;
  }
}

/* Demo 4 */
void resetCounter() {
  noInterrupts();
  counter = 0;
  interrupts();
}
