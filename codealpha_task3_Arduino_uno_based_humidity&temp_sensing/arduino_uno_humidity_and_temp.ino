#include <DHT.h>

#define DHTPIN 2        // DHT11 DATA pin connected to D2
#define DHTTYPE DHT11   // Sensor type

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  Serial.println("DHT11 Temperature and Humidity Sensor");
  Serial.println("------------------------------------");

  dht.begin();
}

void loop() {
  // Read humidity
  float humidity = dht.readHumidity();

  // Read temperature in Celsius
  float temperature = dht.readTemperature();

  // Check if reading failed
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT11 sensor!");
    delay(2000);
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  Serial.println("--------------------");

  delay(2000);
}
