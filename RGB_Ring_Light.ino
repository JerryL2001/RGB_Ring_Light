#define BLINKER_WIFI

#include "Blinker.h"
#include "FastLED.h"

#define DATA_PIN    D4        //where the data pin of the ws2812b is connected to
#define LED_TYPE    WS2812B  //you can find all supported led chipsets at: https://github.com/FastLED/FastLED/blob/master/README.md
#define COLOR_ORDER GRB
#define NUM_LEDS    23       //the actual number of led lamp beads


CRGB leds[NUM_LEDS];


char auth[] = "";//电灯科技上的密钥  the key obtained from Blinker
char ssid[] = "";//你家的WiFi名字   enter your wifi name（can be a mobile phone hotspot or a router's WiFi. If you want to remotely control via the Internet, then this WiFi must have an Internet connection）
char pswd[] = "";//你家WiFi的密码   enter your wifi password

BlinkerButton Button1("switch");     //The button set on the blinker mobile terminal. Entered between the quotation marks is the name of the button you set on the mobile app
BlinkerButton Button2("white");
BlinkerButton Button3("warm");
BlinkerButton Button4("rgb");
BlinkerButton Button5("initialize");
BlinkerSlider Slider1("light");      //The slider set on the blinker mobile terminal. Entered between the quotation marks is the name of the slider you set on the mobile app. You can set the minimum and maximum value of the slider on the app
BlinkerSlider Slider2("red");
BlinkerSlider Slider3("green");
BlinkerSlider Slider4("blue");

//参数变量//
uint8_t BRIGHTNESS=255;  //Define the brightness of led

//全局变量//
uint8_t sw=1;           //if sw==1, all leds are on. else, all leds are off
uint8_t lamp=0;         //if lamp==0, all leds will emit light of the set color（rgb） if lamp==1, all leds will emit in response to botton2, 3 and 4
uint8_t i=0;            //record the mode according to the button pressed down
uint8_t rvalue=0;       //value of red(0~255)
uint8_t gvalue=0;       //value of green(0~255)
uint8_t bvalue=0;       //value of blue(0~255)

void dataRead(const String & data)  //get data from mobile app
{
    BLINKER_LOG("Blinker readString: ", data);

    Blinker.vibrate();
    
    uint32_t BlinkerTime = millis();
    
    Blinker.print("millis", BlinkerTime);
}

//按钮反馈函数    feedback function of bottons
void button1_callback(const String & state)     //Toggle the on/off state of all leds
{
    sw=(sw+1)%2;
    Blinker.vibrate();
    //Blinker.print(sw);
    Button1.print();
}

void button2_callback(const String & state)     //if pressed down, all leds emit white light
{
      sw=1;
      lamp=1;
      i=1;
      Blinker.vibrate();
      Button2.print();
    
}

void button3_callback(const String & state)     //if pressed down, all leds emit light yellow light
{
      sw=1;
      lamp=1;
      i=2;
      Blinker.vibrate();
      Button3.print();
}

void button4_callback(const String & state)      //if pressed down, the light ring will emit flowing colored light
{
      sw=1;
      lamp=1;
      i=3;
      Blinker.vibrate();
      Button4.print();
}

void button5_callback(const String & state)     //if pressed down, all the value will be initialized
{
    sw=1;
    lamp=0;
    i=0;
    rvalue=0;
    gvalue=0;
    bvalue=0;
    BRIGHTNESS=255;
    Blinker.vibrate();
    Button5.print("Initialize succeed!");
}

//滑块反馈函数        feedback function of sliders
void slider1_callback(int32_t value)      //get the brightness number from slider1(0~255)
{
    BLINKER_LOG("get slider value: ", value);
    BRIGHTNESS=value;
    sw=1;
}

void slider2_callback(int32_t value)    //get the red value(0~255)
{
    lamp=0;
    BLINKER_LOG("get slider value: ", value);
    rvalue=value;
    sw=1;
}

void slider3_callback(int32_t value)   //get the green value(0~255)
{
    lamp=0;
    BLINKER_LOG("get slider value: ", value);
    gvalue=value;
    sw=1;
}

void slider4_callback(int32_t value)    //get the blue value(0~255)
{
    lamp=0;
    BLINKER_LOG("get slider value: ", value);
    bvalue=value;
    sw=1;
}

void analyse()  //analyze the data entered
{
  if(lamp==1 && sw==1)
    {
      if(i==1)
      {
        FastLED.setBrightness(BRIGHTNESS);      //set brightness
        CRGB myRGBcolor(250,218,141);           //rgb data of white, this should be determined after actually testing the leds you bought
        fill_solid(leds, NUM_LEDS, myRGBcolor);
      }
      if(i==2)
      {
        FastLED.setBrightness(BRIGHTNESS);
        CRGB myRGBcolor(201,116,28);           //rgb data of light yellow, this should be determined after actually testing the leds you bought
        fill_solid(leds, NUM_LEDS, myRGBcolor);
      }
      if(i==3)
      {
        FastLED.setBrightness(BRIGHTNESS);
        pride();                               //function defined to realize the color flow of leds
      }
    }
    if(lamp==0 && sw==1)                       //light leds according to the set color 
    {
      FastLED.setBrightness(BRIGHTNESS);
      CRGB myRGBcolor(rvalue,gvalue,bvalue);
      fill_solid(leds, NUM_LEDS, myRGBcolor);
    }
    if(sw==0)                                  //turn off all leds
    {
      CRGB myRGBcolor(0,0,0);
      fill_solid(leds, NUM_LEDS, myRGBcolor);
    }
}

void setup() 
{                                 
    Serial.begin(115200);
    BLINKER_DEBUG.stream(Serial);
    
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN,HIGH);
    
    FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS)
    .setCorrection(TypicalLEDStrip)
    .setDither(BRIGHTNESS < 255);
    
    Blinker.begin(auth, ssid, pswd);
    Blinker.attachData(dataRead);
    Button1.attach(button1_callback);
    Button2.attach(button2_callback);
    Button3.attach(button3_callback);
    Button4.attach(button4_callback);
    Button5.attach(button5_callback);
    Slider1.attach(slider1_callback);
    Slider2.attach(slider2_callback);
    Slider3.attach(slider3_callback);
    Slider4.attach(slider4_callback);
}

void loop()
{
    Blinker.run();
    analyse();
    FastLED.show();
}

void pride()      //function of color flow 
{
  static uint16_t sPseudotime = 0;
  static uint16_t sLastMillis = 0;
  static uint16_t sHue16 = 0;
 
  uint8_t sat8 = beatsin88( 87, 220, 250);
  uint8_t brightdepth = beatsin88( 341, 96, 224);
  uint16_t brightnessthetainc16 = beatsin88( 203, (25 * 256), (40 * 256));
  uint8_t msmultiplier = beatsin88(147, 23, 60);

  uint16_t hue16 = sHue16;//gHue * 256;
  uint16_t hueinc16 = beatsin88(113, 1, 3000);
  
  uint16_t ms = millis();
  uint16_t deltams = ms - sLastMillis ;
  sLastMillis  = ms;
  sPseudotime += deltams * msmultiplier;
  sHue16 += deltams * beatsin88( 400, 5,9);
  uint16_t brightnesstheta16 = sPseudotime;
  
  for( uint16_t i = 0 ; i < NUM_LEDS; i++) {
    hue16 += hueinc16;
    uint8_t hue8 = hue16 / 256;

    brightnesstheta16  += brightnessthetainc16;
    uint16_t b16 = sin16( brightnesstheta16  ) + 32768;

    uint16_t bri16 = (uint32_t)((uint32_t)b16 * (uint32_t)b16) / 65536;
    uint8_t bri8 = (uint32_t)(((uint32_t)bri16) * brightdepth) / 65536;
    bri8 += (255 - brightdepth);
    
    CRGB newcolor = CHSV( hue8, sat8, bri8);
    
    uint16_t pixelnumber = i;
    pixelnumber = (NUM_LEDS-1) - pixelnumber;
    
    nblend( leds[pixelnumber], newcolor, 64);
  }
}
