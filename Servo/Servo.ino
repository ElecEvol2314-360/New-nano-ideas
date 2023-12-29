#include <Servo.h>

Servo esc;  

void setup() {
  esc.attach(6);
  esc.write(30);
  delay(3000);  
}

void loop() {    
  esc.write(60);                                            
}
