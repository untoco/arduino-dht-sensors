#include <iarduino_DHT.h>
#include <U8glib.h>

iarduino_DHT sensor(4);
U8GLIB_SSD1306_128X64 u8g(13, 11, 10, 9, 8);
int sensorValue;

void draw(){
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(0,10);
  u8g.print((String) "noka3oMeTP");
  u8g.setPrintPos(0,27);
  sensorValue = analogRead(0);
  u8g.print((String) "CO2: " + sensorValue + " ppm");
  u8g.setPrintPos(0,45);
  u8g.print((String) "Humd: " + sensor.hum + " %");
  u8g.setPrintPos(0,63);
  u8g.print((String) "Temp: " + sensor.tem + " *C");
}

void setup(){
    if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
  
  pinMode(8, OUTPUT);

  Serial.begin(9600);
  delay(1000);
}
void loop(){
    u8g.firstPage();  
  do {
    draw();
  } while( u8g.nextPage() );
  
  Serial.print  ("CEHCOP B KOMHATE: ");
  switch(sensor.read()){
    case DHT_OK:             Serial.println((String) sensor.hum + "% - " + sensor.tem + "*C"); break;
    case DHT_ERROR_CHECKSUM: Serial.println("HE PABEHCTBO KC");                                break;
    case DHT_ERROR_DATA:     Serial.println("OTBET HE COOTBETCTB. CEHCOPAM 'DHT'");            break;
    case DHT_ERROR_NO_REPLY: Serial.println("HET OTBETA");                                     break;
    default:                 Serial.println("ERROR");                                          break;
  } delay(5000);
}
