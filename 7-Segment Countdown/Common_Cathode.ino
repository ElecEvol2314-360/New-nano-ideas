const int segmentA = 2; // Connect segment A of the display to pin 2
const int segmentB = 3; // Connect segment B of the display to pin 3
const int segmentC = 4; // Connect segment C of the display to pin 4
const int segmentD = 5; // Connect segment D of the display to pin 5
const int segmentE = 6; // Connect segment E of the display to pin 6
const int segmentF = 7; // Connect segment F of the display to pin 7
const int segmentG = 8; // Connect segment G of the display to pin 8

const int digit1 = 9;   // Connect digit 1 of the display to pin 9
const int digit2 = 10;  // Connect digit 2 of the display to pin 10

int digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  // Set the display pins as outputs
  pinMode(segmentA, OUTPUT);
  pinMode(segmentB, OUTPUT);
  pinMode(segmentC, OUTPUT);
  pinMode(segmentD, OUTPUT);
  pinMode(segmentE, OUTPUT);
  pinMode(segmentF, OUTPUT);
  pinMode(segmentG, OUTPUT);
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
}

void displayDigit(int digit) {
  digitalWrite(segmentA, digits[digit][0]);
  digitalWrite(segmentB, digits[digit][1]);
  digitalWrite(segmentC, digits[digit][2]);
  digitalWrite(segmentD, digits[digit][3]);
  digitalWrite(segmentE, digits[digit][4]);
  digitalWrite(segmentF, digits[digit][5]);
  digitalWrite(segmentG, digits[digit][6]);
}

void loop() {
  for (int i = 9; i >= 0; i--) {
    displayDigit(i);

    // Display the digit on digit1
    digitalWrite(digit1, HIGH);
    digitalWrite(digit2, LOW);
    delay(1000);

    // Display the digit on digit2
    digitalWrite(digit1, LOW);
    digitalWrite(digit2, HIGH);
    delay(1000);
  }
}
