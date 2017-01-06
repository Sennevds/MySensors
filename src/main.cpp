#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>

// Enable debug prints to serial monitor
#define MY_DEBUG

// Use a bit lower baudrate for serial prints on ESP8266 than default in MyConfig.h
#define MY_BAUD_RATE 9600

// Enables and select radio type (if attached)
//#define MY_RADIO_NRF24
//#define MY_RADIO_RFM69

#define MY_GATEWAY_MQTT_CLIENT
#define MY_GATEWAY_ESP8266

// Set this node's subscribe and publish topic prefix
#define MY_MQTT_PUBLISH_TOPIC_PREFIX "mygateway3-out"
#define MY_MQTT_SUBSCRIBE_TOPIC_PREFIX "mygateway3-in"

// Set MQTT client id
#define MY_MQTT_CLIENT_ID "mysensors-3"

// Enable these if your MQTT broker requires usenrame/password
#define MY_MQTT_USER "xxxx"
#define MY_MQTT_PASSWORD "xxxxx"

#define MY_ESP8266_SSID "xxxxxx"
#define MY_ESP8266_PASSWORD "xxxxxx"

// Set the hostname for the WiFi Client. This is the hostname
// it will pass to the DHCP server if not static.
#define MY_ESP8266_HOSTNAME "Gateyway_3"

// Enable UDP communication
//#define MY_USE_UDP

// Enable MY_IP_ADDRESS here if you want a static ip address (no DHCP)
//#define MY_IP_ADDRESS 192,168,178,87

// If using static ip you need to define Gateway and Subnet address as well
#define MY_IP_ADDRESS 192,168,0,9
#define MY_IP_GATEWAY_ADDRESS 192,168,0,1
#define MY_IP_SUBNET_ADDRESS 255,255,255,0

#define MY_CONTROLLER_IP_ADDRESS 192, 168, 0, 207
// The port to keep open on node server mode
#define MY_PORT 1883

// How many clients should be able to connect to this gateway (default 1)
#define MY_GATEWAY_MAX_CLIENTS 2

#include <ESP8266WiFi.h>

#include <SPI.h>
#include <MySensors.h>

#define CHILD_ID 3

//MyMessage msg(CHILD_ID,V_LIGHT);

void setup()
{

	ArduinoOTA.onStart([]() {
		Serial.println("ArduinoOTA start");
	});
	ArduinoOTA.onEnd([]() {
		Serial.println("\nArduinoOTA end");
	});
	ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
		Serial.printf("OTA Progress: %u%%\r", (progress / (total / 100)));
	});
	ArduinoOTA.onError([](ota_error_t error) {
		Serial.printf("Error[%u]: ", error);
		if (error == OTA_AUTH_ERROR) {
			Serial.println("Auth Failed");
		} else if (error == OTA_BEGIN_ERROR) {
			Serial.println("Begin Failed");
		} else if (error == OTA_CONNECT_ERROR) {
			Serial.println("Connect Failed");
		} else if (error == OTA_RECEIVE_ERROR) {
			Serial.println("Receive Failed");
		} else if (error == OTA_END_ERROR) {
			Serial.println("End Failed");
		}
	});
	ArduinoOTA.begin();
	Serial.println("Ready");
	Serial.print("IP address: ");
	Serial.println(WiFi.localIP());

}

void presentation()
{
	// Present locally attached sensors here
	//present(CHILD_ID, S_LIGHT);
}


void loop()
{
	// Send locally attech sensors data here
	ArduinoOTA.handle();
}
