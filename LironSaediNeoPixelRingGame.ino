#include <Adafruit_NeoPixel.h>
int button = 12;
int delayv = 200;
int delaye = 300;
int neoPixelNumber = 50;
int i = 0;
Adafruit_NeoPixel ring (12, 6);
bool isGameRunning = true;
cons int ledPin = LED_BUILTIN;
int ledstate = LOW;
unsigned long perviousMillis = 0;
const long interval = 1000;



void setup()
{
  
  pinMode( button, INPUT_PULLUP );
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);

  ring.begin();
  ring.setBrightness(10);

}

void loop()
{

  // put your main code here, to run repeatedly:  //  delay(delayV);
unsigned long currentMillis = millis;
if (currentMillis - perviousMillis >= interval)
{
  previousMillis = currentMillis;
if (ledState == LOW)
{
  ledState = HIGH;
}
 else 
 {
  ledtstate == LOW;
  }
  r
}
  if (isGameRunning == true)
  {
    if (i < 12)
    {

      ring.clear();
      
      i++;
      if (i == 12)
      {
        i = 0;
      }

      ring.setPixelColor(3, ring.Color(0, 0, 255));
      ring.show();  //  delay(delayV);
      //  writeNum(eight, false);
      //  delay(delayV);
      ring.setPixelColor(i, ring.Color(0, 255, 185));
      ring.show();
      delay(delayv);

    }


    if (digitalRead (button) == LOW)
    {

      Serial.println(String(i, DEC));
      if (i == 3)
      {
        isGameRunning = false;
        GameOver(true);
        delay(delayv - 10);
        Serial.println("speed up");
      }
      else
      {
        isGameRunning = false;
        GameOver(false);
        delay(delayv + 140);
        Serial.println("speed down");
      }

    }
    else
    {
      Serial.println("0");
    }
  }


}
//    delay(delayv);
//    ring.setPixelColor(i, ring.Color(0, 0, 0));
//    delay(delayv);
//    ring.setPixelColor(i, ring.Color(0, 0, 255));
//    ring.show();

void RedColors()
{
  Serial.println("red colors");
  for (int i = 0; i < 12; i++)
  {
    ring.setPixelColor(i, ring.Color(255, 0, 0));
  }
  ring.show();

  delay(delaye);
  isGameRunning = true;
  //after 2 seconds, restart the game
}
void GreenColors()
{

  for ( int i = 0; i < 12; i++)
  {
   ring.setPixelColor(i, ring.Color(0,255,0));
  }

  ring.show();
}

void GameOver(bool win)
{
  Serial.println("GAME OVER");
  if (win)
  {
    Serial.println("YOU WIN");
    //GreenColors
    GreenColors();
    //speed up
  }
  else
  {
    Serial.println("YOU LOSE");
    RedColors();
   
  }
  delay(delaye);
  isGameRunning = true;
}
