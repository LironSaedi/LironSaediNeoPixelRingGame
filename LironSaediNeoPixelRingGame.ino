#include <Adafruit_NeoPixel.h>
int button = 12;
int delayv = 100;
int neoPixelNumber = 50;
int i = 0;

bool isGameRunning = true;

Adafruit_NeoPixel ring (12, 6);
void setup()
{
  pinMode( button, INPUT_PULLUP );
  // put your setup code here, to run once:

  Serial.begin(9600);

  ring.begin();
  ring.setBrightness(10);

}

void loop()
{

  // put your main code here, to run repeatedly:  //  delay(delayV);

  if (isGameRunning == true)
  {
    if (i < 12)
    {
      i++;
      ring.clear();
      ring.setPixelColor(3, ring.Color(0, 0, 255));
      ring.show();  //  delay(delayV);
      //  writeNum(eight, false);
      //  delay(delayV);
      ring.setPixelColor(i, ring.Color(0, 255, 185));
      ring.show();
      delay(delayv);

      ring.clear();


    }
    if (i == 12)
    {
      i = 0;
      ring.clear();
    }
  }
  if (digitalRead (button) == LOW)
  {

    Serial.println(String(i, DEC));
    if (i == 3)
    {
      isGameRunning = false;
    }

  }
  else
  {
    Serial.println("0");
  }


}
//    delay(delayv);
//    ring.setPixelColor(i, ring.Color(0, 0, 0));
//    delay(delayv);
//    ring.setPixelColor(i, ring.Color(0, 0, 255));
//    ring.show();
