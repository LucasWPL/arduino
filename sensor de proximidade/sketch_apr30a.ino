#include "Ultrasonic.h" 

const int echoPin = 7; 
const int trigPin = 6; 

const int redLed = 2; 
const int yellowLed = 3; 
const int blueLed = 8; 

int distancia; 
int secondsDelay = 500; 
String result; 

Ultrasonic ultrasonic(trigPin,echoPin); 

void setup(){
  pinMode(echoPin, INPUT); 
  pinMode(trigPin, OUTPUT);

  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
}

void loop(){
  initialState();

  distancia = (ultrasonic.Ranging(CM)); 
  result = String(distancia); 

  if(distancia <= 5) {
    critical(100);
  }else if(distancia <= 15) {
    critical(250);
  }else if(distancia <= 30){
    close(500);
  }else if(distancia <= 45){
    far(750);
  }else{
    far(1000);
  }
}

void far(int secondsDelay) {
  delay(secondsDelay); 
  digitalWrite(blueLed, HIGH);
}

void close(int secondsDelay) {
  delay(secondsDelay); 
  digitalWrite(yellowLed, HIGH);
}

void critical(int secondsDelay) {
  delay(secondsDelay); 
  digitalWrite(redLed, HIGH);
}

void initialState() {
  emitsUltrasonicSignal();

  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(blueLed, LOW);
}

void emitsUltrasonicSignal() {
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
}