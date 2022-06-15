![cover (2)](https://user-images.githubusercontent.com/99819306/173768834-51e00b35-c3e0-44b7-a8fc-ce9b9091cb4f.jpg)

# Pixel Art Display

I started learning arduino lately, and I made few robots using different sensors and servo motors (including one that gives you the middle finger *-* ). But I wanted to make something more creative and artistic, so I thought, what can be better than LEDs !!
so I made this " 7x7 Pixel art display " using Arduino UNO, led strips and some other materials. 
Here is how I made it .  
  
- [Creating The Box](#making-the-box)  
- [Circuit Connections](#circuit-connection)  
- [The Code](#coding)  
- [The Final Product](#the-final-product)




## Making the box

- **I started by making the pixels grid using foam boards.**  
I cut 7 strips with 14 LED units on each of them (every pixel will have two LEDs).  
Then I cut a square foam board then stuck the 7 LED strips on it with equal gaps between them.
Then I started measuring the horizontal and vertical gaps, then I devided them to produce 49 equal squares (7x7), then I started to hot glue foam board parriers to seperate the pixels from each others.  
 
<img src="https://user-images.githubusercontent.com/99819306/173791151-d4538780-d496-4b7d-90f2-af8453fd713f.jpg" alt="drawing" style="width:800px;"/>
  
- **after that I started making the frozen glass panel**  
I cut a square piece of acrylic glass sheet, then I covered it with matte wrapping film on one side, and diffuser plastic sheets on the other side. which gave it a nor-reflective surface, and made it difuse the light emitted from the LEDs as well.

<img src="https://user-images.githubusercontent.com/99819306/173812850-c146d54b-b286-4168-acb6-b1d35db60910.jpg" alt="drawing" style="width:800px;"/>

- **Last step was to create a box that will hold all of the pieces together**  
so I made a box out of MDF, which I discovered later that it wasn't the best choice due to it's heavy weight :(  
I then carved some grooves on the four sides to hold the glass panel

<img src="https://user-images.githubusercontent.com/99819306/173815291-23762d88-18c9-43fe-ab99-a729f5938302.jpg" alt="drawing" style="width:800px;"/>

**NOTE**: I covered the mdf with white film  later as a finish.

## Circuit Connection

**components:**
1. Arduino UNO
2. ws2812b LED strip
3. IR receiver
4. IR remote (I uesd old remote I had for another LED strip)
5. 5V Powersupply (whatts depends on how long the strip is)
6. Bunch of jumper wires

<img src="https://user-images.githubusercontent.com/99819306/173817209-2a2eba9d-0c82-4646-bf78-7cbdf2d2f03f.jpg" alt="drawing" style="width:800px;"/>



## Coding  

**content:**  
- [controlling via remote](#how-it-is-being-controlled)
- [animating](#animating)  
- [single color](#single-color)  
- [custom art](#custom-art)

### How it is being controlled
I used the IR reciever with the arduino to read the serial number that each button on the remote control sends (usint the IRremote library). then using if statments, I became able to call different functions depending on which button was pressed. 
```
// if the remote was pressed:
if (irrecv.decode(&results)) {
    // turn on and off    
    if(results.value == 16712445){
      toggleOff();
    }
    // DIY 1
    else if (!isOff && results.value == 16724175){
      drawHeart(30);
    }
    // DIY 2
    else if (!isOff && results.value == 16756815){
      drawSmile(30);
    }
    // DIY 3
    else if (!isOff && results.value == 16740495){
      drawBox(30);
    }
    // DIY 4
    else if (!isOff && results.value == 16716015){
      drawNinja(30);
    }
    // DIY 5
    else if (!isOff && results.value == 16748655){
      drawFace(30);
    }
    // DIY 6
    else if (!isOff && results.value == 16732335){
      drawChart(30);
    }
}
```


### Animating

first of all, I started by fixing a small issue i made while building the led grid. when I bult it, the flow of the LEDs was animating vertically, although I wanted it to animate HORIZONTALLY.  
so I made a function to assign every two LEDs to one pixel (every pixel in my display contains two LED units), and giving them a new order (to animate horizontally).

<img src="https://user-images.githubusercontent.com/99819306/173862421-fde6adf3-33ac-4181-bec1-343d8ec1d25c.jpg" alt="drawing" style="width:800px;"/>

and this was done using this function that takes the number of pixel as a parameter, then returns the associated LED indexes of that pixel:
```
int pixelNumbers(int pixel){
  switch (pixel){
    case 1:
      return 1;
      break;
    case 2:
      return 27;
      break;    
    case 3:
      return 29;
      break;
    case 4:
      return 55;
      break;
    case 5:
      return 57;
      break;
    case 6:
      return 83;
      break;
      
    // and so on and so forth...
    
  }
}
```
this way, I could animate the strip in the new order, and using arduinos `delay()` function, I can make the animation move in different speeds.  
**NOTE:** I would use this function in a for loop, and then increment the returned value by one to turn on the second LED of the pixel as well.

now that we have a new order, we need to use it to animate the strip on. using for loops and the `Adafruit_NeoPixel` library, I was able to do just that.
```
// animating the strip ON
for(int i=1; i<=(strip.numPixels()/2); i++){
    // turning both LEDs of the pixel ON
    for(int j=0; j<2; j++){
      strip.setPixelColor(pixelNumbers(i)+j, color);
    }
    strip.show();
    delay(wait);
  }
```


### single color 

To set the strip to certain color when a button is pressed, I wrote a function that takes one parameter (the reading of the IR receiver of the pressed button), then returns the color associated with that button:
```
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
      
    // and so on and so forth...

  }
}
```
<img src="https://user-images.githubusercontent.com/99819306/173851597-4303fab5-e44e-4729-b68f-d5d634f6cb49.jpg" alt="drawing" style="width:800px;"/>

this way I can use this function to set colors instead of hard coding the entire thing.


### custom art

to draw custom shapes on the display, I could've used a for loop for every group of adjacent pixels which have the same color, but that would've took ton of lines to write. Instead, I declared the colors in variables, then created an array that holds the color of each pixel in order using these variables. this way I can use this array with a for loop to set the desirable color for each pixel.
```
void drawMain(int wait){
  uint32_t a = strip.Color(255,255,255); //White
  uint32_t b = strip.Color(5,5,5); //Black
  uint32_t arr[] = {a,a,a,a,a,a,a,a,b,a,b,a,b,a,a,b,a,b,a,a,a,a,b,a,b,b,b,a,a,b,a,b,a,b,a,a,b,a,b,a,b,a,a,a,a,a,a,a,a};

  draw(arr, 30);

  isOff = false;
}

void draw(uint32_t arr[], int wait){
  for(int i=1; i<=(strip.numPixels()/2); i++){
    for(int j=0; j<2; j++){
      strip.setPixelColor(pixelNumbers(i)+j, arr[i]);
    }
    strip.show();
    delay(wait);
  }
}
```


## The Final Product
Finally, the product's *finished*, and here it is...  

custom art:
![rgb (2)](https://user-images.githubusercontent.com/99819306/173871004-bafeb238-ca9f-444c-b216-46f495909020.jpg)  
![custom-gif](https://user-images.githubusercontent.com/99819306/173875043-9c25e228-a3fa-4226-ab17-c96cfe3ad697.gif)

solid colors:
![rgbb (1)](https://user-images.githubusercontent.com/99819306/173871045-01f1c700-a0d8-44ab-892b-e3adfffb63d0.jpg)  
![rgb-gif](https://user-images.githubusercontent.com/99819306/173874370-5bd98974-47ac-424b-9025-b1a2dd3b9a34.gif)  



