const int segmentA = 2;  // Connect segment A to digital pin 2
const int segmentB = 3;  // Connect segment B to digital pin 3
const int segmentC = 4;  // Connect segment C to digital pin 4
const int segmentD = 5;  // Connect segment D to digital pin 5
const int segmentE = 6;  // Connect segment E to digital pin 6
const int segmentF = 7;  // Connect segment F to digital pin 7
const int segmentG = 8;  // Connect segment G to digital pin 8
const int commonAnode = 9;  // Connect common anode to digital pin 9

const int delayTime = 1000;  // Set the delay time in milliseconds

void setup() {
  // Define segments as outputs
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  pinMode(commonAnode, OUTPUT);

  // Initialize the common anode to HIGH (common anode is connected to VCC)
  digitalWrite(commonAnode, HIGH);
}

void displayDigit(int digit) {
  // Define the 7-segment patterns for digits 0-9
  byte patterns[] = {
    B11111100,  // 0
    B01100000,  // 1
    B11011010,  // 2
    B11110010,  // 3
    B01100110,  // 4
    B10110110,  // 5
    B10111110,  // 6
    B11100000,  // 7
    B11111110,  // 8
    B11110110   // 9
  };

  // Display the digit on the 7-segment display
  digitalWrite(segmentA, bitRead(patterns[digit], 0));
  digitalWrite(segmentB, bitRead(patterns[digit], 1));
  digitalWrite(segmentC, bitRead(patterns[digit], 2));
  digitalWrite(segmentD, bitRead(patterns[digit], 3));
  digitalWrite(segmentE, bitRead(patterns[digit], 4));
  digitalWrite(segmentF, bitRead(patterns[digit], 5));
  digitalWrite(segmentG, bitRead(patterns[digit], 6));
}

void loop() {
  // Display a reverse countdown from 9 to 0
  for (int i = 9; i >= 0; i--) {
    displayDigit(i);
    delay(delayTime);
  }
}
