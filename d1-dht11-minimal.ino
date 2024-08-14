// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"

//#include <ESP8266WiFi.h>
//#include <PubSubClient.h>

#define DHTPIN    2  // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment whatever type you're using!
//define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 3 (on the right) of the sensor to GROUND (if your sensor has 3 pins)
// Connect pin 4 (on the right) of the sensor to GROUND and leave the pin 3 EMPTY (if your sensor has 4 pins)
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);

  // Store WLAN access data here
//  const char* ssid = "OpenWrt"; // Keep quotation marks
//  const char* password = "j2G2tHFpF8m"; // Keep quotation marks, e.g. like this: "Secret"

// Store the data required for the MQTT server here
//  const char* mqtt_client = "DHT-11-HW507"; // If several "NEOE-IoT-Kit-1" are in use, simply number them consecutively with the last number
//  const char* mqtt_server = "192.168.1.10"; // Keep quotation marks, e.g. like this: "192.168.0.236"
//  const uint16_t mqtt_port = 1883;
//  const char* mqtt_user = "root"; // Keep quotation marks
//  const char* mqtt_password = "Dinge"; // Keep quotation marks, e.g. like this: "Secret"
//  const char* mqtt_topic = "Badezimmer/Luftfeuchtigkeit"; // Change the name of the room if necessary
//  const char* mqtt_topic2 = "Badezimmer/Temperatur";

//void setup_wifi() {
//  delay(10);
//  /* Connect to WiFi */
//  WiFi.begin(ssid, password);
//  while (WiFi.status() != WL_CONNECTED) {  
//    delay(500);
//  }  
//}

//WiFiClient espClient;
//PubSubClient client(espClient);

void setup() {
  Serial.begin(9600);
//  setup_wifi();
//  client.setServer(mqtt_server, mqtt_port);
//  client.setBufferSize(512);
//  if (!client.connected()) client.connect(mqtt_client, mqtt_user, mqtt_password);

  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(5000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
 // float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  //float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  //float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.println(F("°C "));
  //client.publish(mqtt_topic, String(h).c_str());
  //client.publish(mqtt_topic2, String(t).c_str());

//  Serial.print(f);
//  Serial.print(F("°F  Heat index: "));
//  Serial.print(hic);
//  Serial.print(F("°C "));
//  Serial.print(hif);
//  Serial.println(F("°F"));
}
