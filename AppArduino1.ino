#include <Servo.h>

int data1 = 127;
int data2 = 127;
int data3 = 0;
int data4 = 0;
int data5 = 0;
int data6 = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  while (Serial.available() > 0) {
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
    Serial.print(data1);
    Serial.print("  ");
    Serial.print(data2);
    Serial.print("  ");
    Serial.print(data3);
    Serial.print("  ");
    Serial.print(data4);
    Serial.print("  ");
    Serial.print(data5);
    Serial.print("  ");
    Serial.println(data6);
}
