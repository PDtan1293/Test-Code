#include <Encoder.h>
#define ENCA_PIN                      24          
#define ENCB_PIN                      26       
#define ENTER_PIN                      5  

void setup()
{
  // put your setup code here, to run once:
  Encoder.begin(ENCA_PIN, ENCB_PIN, ENTER_PIN);   //initialize Encoder
  Serial.begin(112500);
  Encoder.setMin(0);
  Encoder.setMax(11);
  Encoder.setCount(9);
  
  Serial.println("Ready!");
  
}

void loop()
{
  // put your main code here, to run repeatedly:
  Serial.println(Encoder.getCount());
  delay(100);
}
