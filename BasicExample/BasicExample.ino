/*******************************************************************
 *  An example for the Lightpipe 7-segment display.
 *  Counts from 0-9 repeatedly
 *
 *  By Brian Lough
 *  YouTube: https://www.youtube.com/brianlough
 *  Twitch: https://www.twitch.tv/brianlough
 *  Twitter: https://twitter.com/witnessmenow
 *******************************************************************/

#include <Adafruit_NeoPixel.h>

// Pin on the Arduino that is connected to the NeoPixels
#define PIN            10

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      14

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

// 0 = a, 1 = b ... etc
int segments[][2] = {{13, 12}, {11, 10}, {8, 7}, {6, 5}, {4, 3}, {0, 1}, {2, 9}};



void setup() {
  Serial.begin(9600);
  pixels.begin(); 
}

void clearPixels() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Black (off)
  }

  pixels.show(); // This sends the updated pixel color to the hardware.
}

void setSegment(int seg, uint32_t colour) {
    Serial.print("seg: ");
  Serial.println(seg);
  for (int i = 0; i < 2; i++ ) {
    pixels.setPixelColor(segments[seg][i], colour);
  }
}


void setNumber(int number) {
  Serial.print("number: ");
  Serial.println(number);
  uint32_t colour = pixels.Color(0,255,0);
  switch (number) {
    case 0:
      {
        colour = pixels.Color(0,255,0);
        setSegment(0, colour);
        setSegment(1, colour);
        setSegment(2, colour);
        setSegment(3, colour);
        setSegment(4, colour);
        setSegment(5, colour);
        break;
      }
    case 1:
      {
        colour = pixels.Color(0,0,255);
        setSegment(1, colour);
        setSegment(2, colour);
        break;
      }
    case 2:
      {
        colour = pixels.Color(255,0,0);
        setSegment(0, colour);
        setSegment(1, colour);
        setSegment(6, colour);
        setSegment(4, colour);
        setSegment(3, colour);
        break;
      }
    case 3:
      {
        colour = pixels.Color(0,255,255);
        setSegment(0, colour);
        setSegment(1, colour);
        setSegment(6, colour);
        setSegment(2, colour);
        setSegment(3, colour);
        break;
      }
    case 4:
      {
        colour = pixels.Color(255,255,0);
        setSegment(5, colour);
        setSegment(1, colour);
        setSegment(6, colour);
        setSegment(2, colour);
        break;
      }
    case 5:
      {
        colour = pixels.Color(255,0,255);
        setSegment(0, colour);
        setSegment(5, colour);
        setSegment(6, colour);
        setSegment(2, colour);
        setSegment(3, colour);
        break;
      }
    case 6:
      {
        colour = pixels.Color(0,255,0);
        setSegment(0, colour);
        setSegment(5, colour);
        setSegment(6, colour);
        setSegment(2, colour);
        setSegment(3, colour);
        setSegment(4, colour);
        break;
      }
    case 7:
      {
        colour = pixels.Color(0,0,255);
        setSegment(0, colour);
        setSegment(1, colour);
        setSegment(2, colour);
        break;
      }
    case 8:
      {
        colour = pixels.Color(255,0,0);
        setSegment(0, colour);
        setSegment(1, colour);
        setSegment(5, colour);
        setSegment(6, colour);
        setSegment(2, colour);
        setSegment(3, colour);
        setSegment(4, colour);
        break;
      }
    case 9:
      {
        colour = pixels.Color(0,255,255);
        setSegment(0, colour);
        setSegment(1, colour);
        setSegment(5, colour);
        setSegment(6, colour);
        setSegment(2, colour);
        setSegment(3, colour);
        break;
      }


  }

  Serial.println("-------");
}


void loop() {


  for (int i = 0; i < 10; i++) {
    clearPixels();
    setNumber(i);
    pixels.show();
    delay(1000); 

  }
}
