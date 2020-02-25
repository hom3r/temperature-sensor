#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN  A0
#define DHTTYPE DHT22

#define SEG_A 0
#define SEG_B 1
#define SEG_C 2
#define SEG_D 3
#define SEG_E 4
#define SEG_F 5
#define SEG_G 6

#define SEG2_A 7
#define SEG2_B 8
#define SEG2_C 9
#define SEG2_D 10
#define SEG2_E 11
#define SEG2_F 12
#define SEG2_G 13

DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;

void setup() {
  Serial.begin(9600);

  // set pins for first digit display
  pinMode(SEG_A, OUTPUT);
  pinMode(SEG_B, OUTPUT);
  pinMode(SEG_C, OUTPUT);
  pinMode(SEG_D, OUTPUT);
  pinMode(SEG_E, OUTPUT);
  pinMode(SEG_F, OUTPUT);
  pinMode(SEG_G, OUTPUT);

  // set pins for second digit display
  pinMode(SEG2_A, OUTPUT);
  pinMode(SEG2_B, OUTPUT);
  pinMode(SEG2_C, OUTPUT);
  pinMode(SEG2_D, OUTPUT);
  pinMode(SEG2_E, OUTPUT);
  pinMode(SEG2_F, OUTPUT);
  pinMode(SEG2_G, OUTPUT);

  // set temperature sensor
  dht.begin();
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  delayMS = sensor.min_delay / 1000;
  
  Serial.println(F("DHTxx Unified Sensor Example"));
  Serial.println(F("------------------------------------"));
  Serial.println(F("Temperature Sensor"));
  Serial.print  (F("Sensor Type: ")); Serial.println(sensor.name);
  Serial.print  (F("Driver Ver:  ")); Serial.println(sensor.version);
  Serial.print  (F("Unique ID:   ")); Serial.println(sensor.sensor_id);
  Serial.print  (F("Max Value:   ")); Serial.print(sensor.max_value); Serial.println(F("°C"));
  Serial.print  (F("Min Value:   ")); Serial.print(sensor.min_value); Serial.println(F("°C"));
  Serial.print  (F("Resolution:  ")); Serial.print(sensor.resolution); Serial.println(F("°C"));
  Serial.println(F("------------------------------------"));
}

void loop() {
  
  delay(delayMS);

  
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    // print to serial
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));

    // send to displays
    displayDigit((int)event.temperature / 10);
    displaySecondDigit((int)event.temperature % 10);
  }
}

void displayDigit(int value) {
  switch (value) {
    case 0:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, LOW);
      break;
    
    case 1:
      digitalWrite(SEG_A, LOW);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, LOW);
      break;
    
    case 2:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, LOW);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, HIGH);
      break;
      
    case 3:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, HIGH);
      break;
      
    case 4:
      digitalWrite(SEG_A, LOW);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;

    case 5:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, LOW);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;

    
    case 6:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, LOW);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;

    
    case 7:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, LOW);
      digitalWrite(SEG_G, LOW);
      break;

    
    case 8:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;

    
    case 9:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, HIGH);
      digitalWrite(SEG_C, HIGH);
      digitalWrite(SEG_D, LOW);
      digitalWrite(SEG_E, LOW);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
      break;
      
    default:
      digitalWrite(SEG_A, HIGH);
      digitalWrite(SEG_B, LOW);
      digitalWrite(SEG_C, LOW);
      digitalWrite(SEG_D, HIGH);
      digitalWrite(SEG_E, HIGH);
      digitalWrite(SEG_F, HIGH);
      digitalWrite(SEG_G, HIGH);
  }
}


void displaySecondDigit(int value) {
  switch (value) {
    case 0:
      digitalWrite(SEG2_A, HIGH);
      digitalWrite(SEG2_B, HIGH);
      digitalWrite(SEG2_C, HIGH);
      digitalWrite(SEG2_D, HIGH);
      digitalWrite(SEG2_E, HIGH);
      digitalWrite(SEG2_F, HIGH);
      digitalWrite(SEG2_G, LOW);
      break;
    
    case 1:
      digitalWrite(SEG2_A, LOW);
      digitalWrite(SEG2_B, HIGH);
      digitalWrite(SEG2_C, HIGH);
      digitalWrite(SEG2_D, LOW);
      digitalWrite(SEG2_E, LOW);
      digitalWrite(SEG2_F, LOW);
      digitalWrite(SEG2_G, LOW);
      break;
    
    case 2:
      digitalWrite(SEG2_A, HIGH);
      digitalWrite(SEG2_B, HIGH);
      digitalWrite(SEG2_C, LOW);
      digitalWrite(SEG2_D, HIGH);
      digitalWrite(SEG2_E, HIGH);
      digitalWrite(SEG2_F, LOW);
      digitalWrite(SEG2_G, HIGH);
      break;
      
    case 3:
      digitalWrite(SEG2_A, HIGH);
      digitalWrite(SEG2_B, HIGH);
      digitalWrite(SEG2_C, HIGH);
      digitalWrite(SEG2_D, HIGH);
      digitalWrite(SEG2_E, LOW);
      digitalWrite(SEG2_F, LOW);
      digitalWrite(SEG2_G, HIGH);
      break;
      
    case 4:
      digitalWrite(SEG2_A, LOW);
      digitalWrite(SEG2_B, HIGH);
      digitalWrite(SEG2_C, HIGH);
      digitalWrite(SEG2_D, LOW);
      digitalWrite(SEG2_E, LOW);
      digitalWrite(SEG2_F, HIGH);
      digitalWrite(SEG2_G, HIGH);
      break;

    case 5:
      digitalWrite(SEG2_A, HIGH);
      digitalWrite(SEG2_B, LOW);
      digitalWrite(SEG2_C, HIGH);
      digitalWrite(SEG2_D, HIGH);
      digitalWrite(SEG2_E, LOW);
      digitalWrite(SEG2_F, HIGH);
      digitalWrite(SEG2_G, HIGH);
      break;

    
    case 6:
      digitalWrite(SEG2_A, HIGH);
      digitalWrite(SEG2_B, LOW);
      digitalWrite(SEG2_C, HIGH);
      digitalWrite(SEG2_D, HIGH);
      digitalWrite(SEG2_E, HIGH);
      digitalWrite(SEG2_F, HIGH);
      digitalWrite(SEG2_G, HIGH);
      break;

    
    case 7:
      digitalWrite(SEG2_A, HIGH);
      digitalWrite(SEG2_B, HIGH);
      digitalWrite(SEG2_C, HIGH);
      digitalWrite(SEG2_D, LOW);
      digitalWrite(SEG2_E, LOW);
      digitalWrite(SEG2_F, LOW);
      digitalWrite(SEG2_G, LOW);
      break;

    
    case 8:
      digitalWrite(SEG2_A, HIGH);
      digitalWrite(SEG2_B, HIGH);
      digitalWrite(SEG2_C, HIGH);
      digitalWrite(SEG2_D, HIGH);
      digitalWrite(SEG2_E, HIGH);
      digitalWrite(SEG2_F, HIGH);
      digitalWrite(SEG2_G, HIGH);
      break;

    
    case 9:
      digitalWrite(SEG2_A, HIGH);
      digitalWrite(SEG2_B, HIGH);
      digitalWrite(SEG2_C, HIGH);
      digitalWrite(SEG2_D, LOW);
      digitalWrite(SEG2_E, LOW);
      digitalWrite(SEG2_F, HIGH);
      digitalWrite(SEG2_G, HIGH);
      break;
      
    default:
      digitalWrite(SEG2_A, HIGH);
      digitalWrite(SEG2_B, LOW);
      digitalWrite(SEG2_C, LOW);
      digitalWrite(SEG2_D, HIGH);
      digitalWrite(SEG2_E, HIGH);
      digitalWrite(SEG2_F, HIGH);
      digitalWrite(SEG2_G, HIGH);
  }
}
