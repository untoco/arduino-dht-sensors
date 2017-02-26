#include <iarduino_DHT.h>
#include <U8glib.h>

iarduino_DHT sensor(4);
U8GLIB_SSD1306_128X64 u8g(13, 11, 10, 9, 8);
int sensorValue;

void draw(){
  u8g.setContrast(0);
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(0,10);
  u8g.print((String) "Hmdt,%   Temp,*C");
  u8g.setFont(u8g_font_fur30);
  u8g.setPrintPos(0,55);
  u8g.print((String) round(sensor.hum) + "   " + round(sensor.tem));
}

void setup(){
    if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
  
  pinMode(8, OUTPUT);
  delay(1000);
}
void loop(){
    u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
switch(sensor.read())  
delay(5000);
}
