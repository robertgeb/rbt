
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_HMC5883_U.h>

Adafruit_HMC5883_Unified mag = Adafruit_HMC5883_Unified(12345);

int motorSpeedA = 5,
  motorSpeedB = 6,
  motorA1 = 7,
  motorA2 = 8,
  motorB1 = 12,
  motorB2 = 13;

void setup(void) {
  pinMode(motorSpeedA , OUTPUT);
  pinMode(motorSpeedB , OUTPUT);
  pinMode(motorA1 , OUTPUT);
  pinMode(motorA2 , OUTPUT);
  pinMode(motorB1 , OUTPUT);
  pinMode(motorB2 , OUTPUT);
  if(!mag.begin())
  {
    while(1){
      motor(1);
      delay(500);
      motor(6);
      delay(500);
    }
  }
  Serial.begin(9600);
}

void loop(void) {
}

float magsen(void){
  sensors_event_t event; 
  mag.getEvent(&event);
  
  //Arctangente de x e y
  float heading = atan2(event.magnetic.y, event.magnetic.x);

  // Corrige se o sinal estiver reverso.
  if(heading < 0)
    heading += 2*PI;

  // Convertendo para graus
  float headingDegrees = heading * 180/M_PI;
  return headingDegrees;
}

void motor(int action){
  switch (action){
    case 0:                       // Parar motores
      analogWrite(motorSpeedA, 0);
      analogWrite(motorSpeedB, 0);
      break;
    case 1:                       // Acelerar motores
      analogWrite(motorSpeedA, 255);
      analogWrite(motorSpeedB, 255);
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, HIGH);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, HIGH);
      break;
    case 2:                       // Acelerar Esquerda, parar Direita 
      analogWrite(motorSpeedA, 255);
      analogWrite(motorSpeedB, 0);
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, HIGH);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, HIGH);
      break;
    case 3:                       // Acelerar Direita, parar Esquerda!
      analogWrite(motorSpeedA, 0);
      analogWrite(motorSpeedB, 255);
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, HIGH);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, HIGH);
      break;
    case 4:                       // Reverter Esquerda, parar Direita
      analogWrite(motorSpeedA, 255);
      analogWrite(motorSpeedB, 0);
      digitalWrite(motorA1, HIGH);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, HIGH);
      digitalWrite(motorB2, LOW);
      break;
    case 5:                       // Reverter Direita, parar Esquerda!
      analogWrite(motorSpeedA, 0);
      analogWrite(motorSpeedB, 255);
      digitalWrite(motorA1, HIGH);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, HIGH);
      digitalWrite(motorB2, LOW);
      break;
    case 6:                           // MARCHA RÉ
      analogWrite(motorSpeedA, 255);
      analogWrite(motorSpeedB, 255);
      digitalWrite(motorA1, HIGH);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, HIGH);
      digitalWrite(motorB2, LOW);
      break;
    case 7:                           //  FORÇAR PARA ESQUERDA
      analogWrite(motorSpeedA, 255);
      analogWrite(motorSpeedB, 125);
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, HIGH);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, HIGH);
      break;
    case 8:                           //  FORÇAR PARA DIREITA
      analogWrite(motorSpeedA, 125);
      analogWrite(motorSpeedB, 255);
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, HIGH);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, HIGH);
      break;
    
  }
}

