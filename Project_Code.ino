#include <ESP32Servo.h>
#include <Wire.h>
#include <Adafruit_MLX90614.h>


const int servoPin = 18;
const int trigPin = 26;
const int echoPin = 25;
const int ledPinR = 17;
const int ledPinG = 16;
const int buzzerPin = 13;

#define SOUND_SPEED 0.034

Adafruit_MLX90614 mlx = Adafruit_MLX90614();
Servo myServo;

void setup() {
  Serial.begin(115200); 
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  myServo.attach(servoPin);
  pinMode(ledPinR, OUTPUT); 
  pinMode(ledPinG, OUTPUT); 
  pinMode(buzzerPin, OUTPUT); 
  digitalWrite(buzzerPin, LOW);
  while (!Serial);

  Serial.println("Adafruit MLX90614 test");

  if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1);
  };

  Serial.print("Emissivity = "); Serial.println(mlx.readEmissivity());
  Serial.println("================================================");

}

long readDistanceCm() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  return duration * SOUND_SPEED / 2;
}

void loop() {
  
  myServo.attach(18);
  for(int pos = 0; pos <= 180; pos++) {
    myServo.write(pos);
    delay(15);

    long distanceCm = readDistanceCm();
    float objectTempC = mlx.readObjectTempC();
    
    
    if(distanceCm < 10) {
      Serial.println("Object detected! Stopping sweep.");
      Serial.println(distanceCm);
      digitalWrite(ledPinR, HIGH);
      digitalWrite(buzzerPin, LOW);
      digitalWrite(ledPinG, LOW);
      myServo.detach(); 
      delay(100);
    }
    else {
      digitalWrite(ledPinG, HIGH);
      digitalWrite(ledPinR, LOW);
      digitalWrite(buzzerPin, HIGH);
      }
    if(objectTempC > 32) {
      Serial.println("Object detected! Stopping sweep.");
      Serial.println(distanceCm);
      Serial.println(objectTempC);
      digitalWrite(ledPinR, HIGH);
      digitalWrite(buzzerPin, LOW);
      digitalWrite(ledPinG, LOW);
      myServo.detach(); 
      delay(100);
    }
    else {
      digitalWrite(ledPinG, HIGH);
      digitalWrite(ledPinR, LOW);
      digitalWrite(buzzerPin, HIGH);
     
    }
  }
  
  myServo.attach(18);
  for(int pos = 180; pos >= 0; pos--) {
    myServo.write(pos);
    delay(15);
  
    long distanceCm = readDistanceCm();
    float objectTempC = mlx.readObjectTempC();
    
    if(distanceCm < 10) {
      Serial.println("Object detected! Stopping sweep.");
      Serial.println(distanceCm);
      digitalWrite(ledPinR, HIGH);
      digitalWrite(buzzerPin, LOW);
      digitalWrite(ledPinG, LOW);
      myServo.detach(); 
      delay(100);
    }
    else {
      digitalWrite(ledPinG, HIGH);
      digitalWrite(ledPinR, LOW);
      digitalWrite(buzzerPin, HIGH);
     
    }


    if(objectTempC > 32) {
      Serial.println("Object detected! Stopping sweep.");
      Serial.println(distanceCm);
      Serial.println(objectTempC);
      digitalWrite(ledPinR, HIGH);
      digitalWrite(buzzerPin, LOW);
      digitalWrite(ledPinG, LOW);
      myServo.detach(); 
      delay(100);
    }
    else {
      digitalWrite(ledPinG, HIGH);
      digitalWrite(ledPinR, LOW);
      digitalWrite(buzzerPin, HIGH);
     
    }
  
  }


}
