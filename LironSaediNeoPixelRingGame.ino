#include <Adafruit_NeoPixel.h>
int button = 12;

int neoPixelNumber = 50;
int i = 0;
Adafruit_NeoPixel ring (12, 6);
const int ledPin = LED_BUILTIN;
int ledstate = LOW;
unsigned long previousMillis = 0;

long start = 1000;
long rate = 500;
long finish = 0;
long interval = start;



void setup()
{
  randomSeed(analogRead(A0));
  b 
  pinMode( button, INPUT_PULLUP );
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  ring.begin();
  ring.setBrightness(10);

}


void loop()
{

  // put your main code here, to run repeatedly:  //  delay(delayV);
  unsigned long currentMillis = millis();


  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;

    if (i < 12)
    {
      ring.clear();

      i++;
      if (i == 12)
      {
        i = 0;
      }

      ring.setPixelColor(3, ring.Color(0, 0, 255));
      ring.show();
      ring.setPixelColor(i, ring.Color(0, 255, 185));
      ring.show();
    }
  }

  if (digitalRead (button) == LOW)
  {
    Serial.println(String(i, DEC));
    if (i == 3)
    {
      interval -= rate;
      GameOver(true);
      Serial.println("speed up");
    }
    else
    {
      GameOver(false);
      interval = start;
      Serial.println("speed down");
    }
  }
  else
  {
    Serial.println("0");
  }

}
void rainBowColors()
{
  for (int i = 0;  i < 12; i++)

  {
    int red = random(0,256);
    int green = random(1,123);
    int blue = random(1,214);
    ring.setPixelColor(i, ring.Color(red, green, blue));
    delay(500);
  }
}

void RedColors()
{
  Serial.println("red colors");
  for (int i = 0; i < 12; i++)
  {
    ring.setPixelColor(i, ring.Color(255, 0, 0));
  }
  ring.show();

  delay(300);
  //after 2 seconds, restart the game
}
void GreenColors()
{

  for ( int i = 0; i < 12; i++)
  {
    ring.setPixelColor(i, ring.Color(0, 255, 0));
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
    if (interval <= finish)
    {
      rainBowColors();
      interval = start;
    }
    else
    {
      GreenColors();
    }
    //speed up
  }
  else
  {
    Serial.println("YOU LOSE");
    RedColors();

  }
  delay(300);
}
