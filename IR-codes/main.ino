#include <IRremote.h>

const int IR_PIN = A0;

const int LED1 = 2;
const int LED2 = 3;
const int LED3 = 4;
const int LED4 = 5;

void setup() {  
   IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);
   
   pinMode(LED1, OUTPUT);
   pinMode(LED2, OUTPUT);
   pinMode(LED3, OUTPUT);
   pinMode(LED4, OUTPUT);
}

void loop() {
   
   if (IrReceiver.decode())
   {
      String ir_code = String(IrReceiver.decodedIRData.command, HEX);
      Serial.println(ir_code);

      if(ir_code == "4")
        digitalWrite(LED1, HIGH);
      else if(ir_code == "2")
        digitalWrite(LED1, LOW);
      if(ir_code == "5")
        digitalWrite(LED2, HIGH);
      else if(ir_code == "2")
        digitalWrite(LED2, LOW);
      if(ir_code == "6")
        digitalWrite(LED3, HIGH);
      else if(ir_code == "2")
        digitalWrite(LED3, LOW);
      if(ir_code == "7")
        digitalWrite(LED4, HIGH);
      else if(ir_code == "2")
        digitalWrite(LED4, LOW);
      
      IrReceiver.resume();
   }
}
