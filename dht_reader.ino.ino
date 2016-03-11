#include <DHT.h>

#define DHTPIN 2            //arduino due pin where it will receive data
#define DHTTYPE DHT11       //type of sensor, which is DHT11

DHT dht(DHTPIN, DHTTYPE);  //making sensor object to call methods from

void setup() {
  Serial.begin(9600);
  dht.begin();  //initialize sensor mcu so it starts reading
}

void loop() {
  delay(4000);
  float h = dht.readHumidity();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(f)){
    Serial.println("No se leyo bien del sensor");
    return;
  }

  Serial.print("Humidity: ");  //unitless, it's a percent
  Serial.print(h);
  Serial.print(" ");
  Serial.print("Farenheit: ");
  Serial.println(f);           //like it says above, it's in Farenheit
  
}
