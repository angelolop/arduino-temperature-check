
#include <DHT.h>;
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,4);
#define DHTPIN 2
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

float humidity;
float temprature;

void setup()
{
 dht.begin();
 Serial.begin(9600);
 lcd.init();
 lcd.backlight();
}
void loop()
{
    delay(2000);
    humidity = dht.readHumidity();
    temprature = dht.readTemperature();

    Serial.print("Humidade :");
    Serial.println(humidity);
    Serial.print("Temperatura :");
    Serial.println(temprature);

    lcd.setCursor(0,1);
    lcd.print("H :");
    lcd.println(humidity);
    lcd.setCursor(0,6);
    lcd.print("%");
  

    lcd.setCursor(0,0);
    lcd.print("T :");
    lcd.println(temprature);
    lcd.print("c");
   
    
    delay(2000);
}