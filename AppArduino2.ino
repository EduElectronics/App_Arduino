#include <Servo.h>

int data1 = 127;
int data2 = 127;
int data3 = 0;
int data4 = 0;
int data5 = 0;
int data6 = 0;

Servo servoX;
Servo servoY;

byte led1 = 5;
byte led2 = 6;
byte led3 = 7;
byte led4 = 8;

byte angX;
byte angY;

void setup() {
  Serial.begin(9600);

  servoX.attach(11);
  servoY.attach(12);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  while (Serial.available() > 0) {
    Serial.flush();

    String str1 = Serial.readStringUntil('A');
    data1 = str1.toInt();
    String str2 = Serial.readStringUntil('B');
    data2 = str2.toInt();
    String str3 = Serial.readStringUntil('C');
    data3 = str3.toInt();
    String str4 = Serial.readStringUntil('D');
    data4 = str4.toInt();
    String str5 = Serial.readStringUntil('E');
    data5 = str5.toInt();
    String str6 = Serial.readStringUntil('\n');
    data6 = str6.toInt();

  }
  //------------------------------------------

  angX = map(data1, 0, 255, 170, 10);
  angY = map(data2, 0, 255, 10, 170);

  digitalWrite(led1, data3);
  digitalWrite(led2, data4);
  digitalWrite(led3, data5);
  digitalWrite(led4, data6);

  servoX.write(angX);
  servoY.write(angY);

  //------------------------------------------
    Serial.print(angX);
    Serial.print("  ");
    Serial.print(angY);
    Serial.print("  ");
    Serial.print(data3);
    Serial.print("  ");
    Serial.print(data4);
    Serial.print("  ");
    Serial.print(data5);
    Serial.print("  ");
    Serial.println(data6);
}


