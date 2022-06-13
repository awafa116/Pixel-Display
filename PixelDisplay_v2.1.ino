// REMOTE CONTROL
#include <IRremote.h>
int RECV_PIN = 9;  // the IO pin connected to the IR reciever
IRrecv irrecv(RECV_PIN);
decode_results results;

// LED STRIP
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define PIXEL_PIN    6  // Digital IO pin connected to the NeoPixels.
#define PIXEL_COUNT 98  // the number of pixels in the strip

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

boolean isOff = true;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  strip.begin(); // Initialize NeoPixel strip object (REQUIRED)
  strip.setBrightness(100);
  strip.show(); // Initialize all pixels to 'off'/
}

void loop() {
  if (irrecv.decode(&results)) {
//  Serial.println(results.value,DEC);  // to print the remote readings to serial

    // turn on and off    
    if(results.value == 16712445){
      toggleOff();
    }
    // DIY 1
    else if (results.value == 16724175){
      drawHeart(30);
    }
    // DIY 2
    else if (results.value == 16756815){
      drawSmile(30);
    }
    // DIY 3
    else if (results.value == 16740495){
      drawBox(30);
    }
    // DIY 4
    else if (results.value == 16716015){
      drawCherry(30);
    }
    // DIY 5
    else if (results.value == 16748655){
      drawFace(30);
    }
    // DIY 6
    else if (results.value == 16732335){
      drawChart(30);
    }
    // Colors Buttons
    else {
      singleColor(results.value, 30);
    }
  
    
    irrecv.resume();
  }
}

/*****************************************
          A N I M A T I O N S
******************************************/
// turn the LED off
void animateOut(int wait){
  for(int i=1; i<=(strip.numPixels()/2); i++){
    for(int j=0; j<2; j++){
      strip.setPixelColor(pixelNumbers(i)+j, (0,0,0));
    }
    strip.show();
    delay(wait);
  }
}

/****************************************************************************/

// Single color
void singleColor(int button, int wait){
  uint32_t color = getColor(button);
  for(int i=1; i<=(strip.numPixels()/2); i++){
    for(int j=0; j<2; j++){
      strip.setPixelColor(pixelNumbers(i)+j, color);
    }
    strip.show();
    delay(wait);
  }
  isOff = false;
}

/****************************************************************************/

// Heart (DIY1)
void drawHeart(int wait){
  uint32_t r = strip.Color(255,000,000); //Red
  uint32_t w = strip.Color(255,255,255); //White
  uint32_t arr[] = {w,w,w,w,w,w,w,w,w,r,w,r,w,w,w,r,r,r,r,r,w,w,r,r,r,r,r,w,w,w,r,r,r,w,w,w,w,w,r,w,w,w,w,w,w,w,w,w,w};
  
  for(int i=1; i<=(strip.numPixels()/2); i++){
    for(int j=0; j<2; j++){
      strip.setPixelColor(pixelNumbers(i)+j, arr[i-1]);
    }
    strip.show();
    delay(wait);
  }
  
  isOff = false;  
}

/****************************************************************************/

// Smile (DIY2)
void drawSmile(int wait){
  uint32_t p = strip.Color(255,000,200); //Pink
  uint32_t w = strip.Color(255,255,255); //White
  uint32_t arr[] = {p,p,p,p,p,p,p,p,p,w,p,w,p,p,p,p,w,p,w,p,p,p,p,p,p,p,p,p,p,w,p,p,p,w,p,p,p,w,w,w,p,p,p,p,p,p,p,p,p};

  for(int i=1; i<=(strip.numPixels()/2); i++){
    for(int j=0; j<2; j++){
      strip.setPixelColor(pixelNumbers(i)+j, arr[i-1]);
    }
    strip.show();
    delay(wait);
  }

  isOff = false;

}

/****************************************************************************/

// Orange Box (DIY3)
void drawBox(int wait){
  uint32_t y = strip.Color(255,255,000); //Yellow
  uint32_t o = strip.Color(255,80,000); //Orange
  uint32_t arr[] = {o,o,y,y,y,o,o,o,y,y,o,y,y,o,y,y,o,o,o,y,y,y,o,o,o,o,o,y,y,y,o,o,o,y,y,o,y,y,o,y,y,o,o,o,y,y,y,o,o};

  for(int i=1; i<=(strip.numPixels()/2); i++){
    for(int j=0; j<2; j++){
      strip.setPixelColor(pixelNumbers(i)+j, arr[i-1]);
    }
    strip.show();
    delay(wait);
  }
  
  isOff = false;
}

/****************************************************************************/

// Cherry (DIY4)
void drawCherry(int wait){
  uint32_t r = strip.Color(255,10,40); //Red
  uint32_t g = strip.Color(50,255,20); //Green
  uint32_t b = strip.Color(000,255,255); //Blue
  uint32_t arr[] = {b,b,b,b,b,b,b,b,b,b,g,b,b,b,b,b,g,b,g,b,b,b,b,g,b,g,b,b,b,r,r,b,r,r,b,b,r,r,b,r,r,b,b,b,b,b,b,b,b};
  
  for(int i=1; i<=(strip.numPixels()/2); i++){
    for(int j=0; j<2; j++){
      strip.setPixelColor(pixelNumbers(i)+j, arr[i-1]);
    }
    strip.show();
    delay(wait);
  }

  isOff = false;
}

/****************************************************************************/

// Green Face (DIY5)
void drawFace(int wait){
  uint32_t g = strip.Color(000,255,105); //Green
  uint32_t w = strip.Color(255,255,255); //Blue
  uint32_t k = strip.Color(000,000,000); //Black
  uint32_t arr[] = {g,g,g,g,g,g,g,g,w,k,g,w,k,g,g,w,w,g,w,w,g,g,g,g,g,g,g,g,g,w,w,w,w,w,g,g,w,w,w,w,w,g,g,g,g,g,g,g,g};

  for(int i=1; i<=(strip.numPixels()/2); i++){
    for(int j=0; j<2; j++){
      strip.setPixelColor(pixelNumbers(i)+j, arr[i-1]);
    }
    strip.show();
    delay(wait);
  }

  isOff = false;
}

/****************************************************************************/

// Mixed Color Chart (DIY6)
void drawChart(int wait){
  uint32_t p = strip.Color(255,20,100); //Pink
  uint32_t t = strip.Color(000,255,255); //Teal
  uint32_t arr[] = {t,t,t,t,t,t,t,t,t,t,t,t,t,t,p,t,t,t,t,p,t,t,p,t,t,p,t,p,p,p,p,t,p,p,p,p,p,p,p,p,p,p,p,p,p,p,p,p,p};

  for(int i=1; i<=(strip.numPixels()/2); i++){
    for(int j=0; j<2; j++){
      strip.setPixelColor(pixelNumbers(i)+j, arr[i-1]);
    }
    strip.show();
    delay(wait);
  }

  isOff = false;
}
  


/*****************************************
            C O N T R O L S
******************************************/

void toggleOff(){
  //turn on the display with the last color
  if(isOff){
    singleColor(16720605,30);
    isOff = false;
  } 
  //turn off the display
  else{
    animateOut(30);
    isOff = true;
  }
}

/*****************************************
      H E L P E R   F U N C T I O N S
******************************************/
// get the start led number of the pixel
int pixelNumbers(int pixel){
  switch (pixel){
    case 1:
      return 0;
      break;
    case 2:
      return 26;
      break;    
    case 3:
      return 28;
      break;
    case 4:
      return 54;
      break;
    case 5:
      return 56;
      break;
    case 6:
      return 82;
      break;
    case 7:
      return 84;
      break;
    case 8:
      return 86;
      break;
    case 9:
      return 80;
      break;
    case 10:
      return 58;
      break;
    case 11:
      return 52;
      break;
    case 12:
      return 30;
      break;
    case 13:
      return 24;
      break;
    case 14:
      return 2;
      break;
    case 15:
      return 4;
      break;
    case 16:
      return 22;
      break;
    case 17:
      return 32;
      break;
    case 18:
      return 50;
      break;
    case 19:
      return 60;
      break;
    case 20:
      return 78;
      break;
    case 21:
      return 88;
      break;
    case 22:
      return 90;
      break;
    case 23:
      return 76;
      break;
    case 24:
      return 62;
      break;
    case 25:
      return 48;
      break;
    case 26:
      return 34;
      break;
    case 27:
      return 20;
      break;
    case 28:
      return 6;
      break;
    case 29:
      return 8;
      break;
    case 30:
      return 18;
      break;
    case 31:
      return 36;
      break;
    case 32:
      return 46;
      break;
    case 33:
      return 64;
      break;
    case 34:
      return 74;
      break;
    case 35:
      return 92;
      break;
    case 36:
      return 94;
      break;
    case 37:
      return 72;
      break;
    case 38:
      return 66;
      break;
    case 39:
      return 44;
      break;
    case 40:
      return 38;
      break;
    case 41:
      return 16;
      break;
    case 42:
      return 10;
      break;
    case 43:
      return 12;
      break;
    case 44:
      return 14;
      break;
    case 45:
      return 40;
      break;
    case 46:
      return 42;
      break;
    case 47:
      return 68;
      break;
    case 48:
      return 70;
      break;
    case 49:
      return 96;
      break;    
  }  
}

// get the color from remote button
uint32_t getColor(int button){
   
  switch(button){
    //Red1    
    case 16718565:
      return strip.Color(255,000,000);
      break;
    //Red2
    case 16722645:
      return strip.Color(255,105,000);
      break;
    //Red3
    case 16714485:
      return strip.Color(255,145,000);
      break;
    //Red4
    case 16726215:
      return strip.Color(255,185,000);
      break;
    //Red5
    case 16718055:
      return strip.Color(255,255,000);
      break;


    //Green1
    case 16751205:
      return strip.Color(000,255,000);
      break;    
    //Green2
    case 16755285:
      return strip.Color(000,255,105);
      break;
    //Green3
    case 16747125:
      return strip.Color(000,255,145);
      break;
    //Green4
    case 16758855:
      return strip.Color(000,255,185);
      break;
    //Green5
    case 16750695:
      return strip.Color(000,255,255);
      break;


      
    //Blue1
    case 16753245:
      return strip.Color(000,000,255);
      break;
    //Blue2
    case 16749165:
      return strip.Color(105,000,255);
      break;
    //Blue3
    case 16757325:
      return strip.Color(145,000,255);
      break;
    //Blue4
    case 16742535:
      return strip.Color(185,000,230);
      break;
    //Blue5
    case 16734375:
      return strip.Color(255,000,200);
      break;



    //White1
    case 16720605:
      return strip.Color(255,255,255);
      break;
    //Whie2
    case 16716525:
      return strip.Color(255,241,224);
      break;
    //White3
    case 16724685:
      return strip.Color(255,214,170);
      break;
    //White4
    case 16775175:
      return strip.Color(255,197,143);
      break;
    //White5
    case 16767015:
      return strip.Color(255,147,041);
      break;
  }
}
