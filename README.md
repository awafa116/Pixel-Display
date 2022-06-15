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







## The Final Product
