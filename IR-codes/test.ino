#include <IRremote.h>

const int IR = A0;

void setup()
{
   Serial.begin(9600);
   Serial.println("ir test");
   IrReceiver.begin(IR, ENABLE_LED_FEEDBACK);
}

void loop()
{
   if (IrReceiver.decode())
   {
      String ir_code = String(IrReceiver.decodedIRData.command, HEX);
      Serial.println(ir_code);

      IrReceiver.resume();
   }
}
