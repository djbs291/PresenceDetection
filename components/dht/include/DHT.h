/* 

	DHT22 temperature sensor driver

*/

#ifndef DHT_H_
#define DHT_H_

#define DHT_OK 0
#define DHT_CHECKSUM_ERROR -1
#define DHT_TIMEOUT_ERROR -2

#define INITIAL_TEMPERATURE 0x00
#define INITIAL_HUMIDITY    0x00
#define HEATER_ON           1
#define HEATER_OFF          0
#define FAN_ON              1
#define FAN_OFF             0

// DHT_State structure used to save all the essential data
// to be used in the messages between nodes

struct _dht_state{
	uint16_t unsignedTemperature;
	float temperature;
	bool isheater;
	bool currentHeaterStatus;
	bool oldHeaterStatus;
	bool currentFanStatus;
	bool oldFanStatus;
};

// == function prototypes =======================================

void setDHTgpio(int gpio);
void errorHandler(int response);
int readDHT();
float getHumidity();
float getTemperature();
uint16_t getUnsignedTemperature();
int getSignalLevel(int usTimeOut, bool state);

#endif