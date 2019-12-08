/*** Note: OneWire and DS18B20 Libraries are required ***/
#include <DS18B20.h>

/*** PID Parameters ***/
const float kP = 8.0, kI = 5.0, kD = 0.7, kN = 2.0;
const float Out_min = -100.0, Out_max = 100.0, dt = 0.1;

/*** SetPoint Temperature ***/
const float T_setpoint = 5.0;
/*** DS18B20 Device Address ***/
const unsigned int devAddr = 2;
/*** Cooler Control Pin ***/
const unsigned int coolerCtrlPin = 9;

/*** Runtime Global Variables ***/
float IState = 0.0;
float DStatePost = 0.0;
DS18B20 ds(devAddr);

/******************************/
void setup() {
  Serial.begin(9600);
  pinMode(coolerCtrlPin, OUTPUT);

  delay(1000);
}

/******************************/
void loop() {
  /** DS18B20 Data Convert **/
  ds.doConversion();

  /** PID Controller **/
  float T_measure = ds.getTempC();
  float T_error = T_setpoint - T_measure;

  float df = (kD * T_error - DStatePost) * kN;
  IState += kI * T_error * dt;
  
  DStatePost += df * dt;
  float powerOut = kP * T_error + IState + df;
  if(powerOut > Out_max) powerOut = Out_max;
  if(powerOut < Out_min) powerOut = Out_min;

  float powerRatio = (powerOut - Out_min) / (Out_max - Out_min);
  analogWrite(coolerCtrlPin, int(powerRatio * 255.0));
  
  Serial.print("Fridge-Temp: ");
  Serial.print(T_measure);
  Serial.println(' C');
  
  delay(int(1000.0 * dt));
}
