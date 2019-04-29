
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
//#include <aREST.h>
WiFiClient client;
WiFiServer server(80);
const int E1 = 10;
const int E2 = 11;
const int motor1pin1 = 8;
const int motor1pin2 = 9;
const int motor2pin1 = 12;
const int motor2pin2 = 13;

int moveRobot = 0;
String data = "";
const char* ssid = "Chestnut_Sq";
const char* password = "3200chestnut";

void setup() {
  //  Serial.begin(9600);
  Serial.println("read");

  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  WiFi.softAP(ssid, password);

  //  digitalWrite(switchState, moveRobot);
}

void loop() {
  if (Serial.available()) {
    int moveRobot = Serial.read();

    if (moveRobot == 0) {
      stopp();
    }
    else if (moveRobot == 1) {
      forward();
    }
    else if (moveRobot == 2) {
      left();
    }
    else if (moveRobot == 3) {
      right();
    }
    else if (moveRobot == 4) {
      back();
    }
  }
}

void forward() {

  digitalWrite(E1, HIGH);
  digitalWrite(E2, HIGH);

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}

void left() {

  digitalWrite(E1, LOW);
  digitalWrite(E2, HIGH);

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}

void right() {

  digitalWrite(E1, LOW);
  digitalWrite(E2, HIGH);

  digitalWrite(motor1pin1, HIGH);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, HIGH);
}


void back() {

  digitalWrite(E1, HIGH);
  digitalWrite(E2, HIGH);

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, HIGH);
  digitalWrite(motor2pin1, HIGH);
  digitalWrite(motor2pin2, LOW);
}

void stopp() {

  digitalWrite(E1, LOW);
  digitalWrite(E2, LOW);

  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  digitalWrite(motor2pin1, LOW);
  digitalWrite(motor2pin2, LOW);
}
