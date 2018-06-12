#include "Wire.h"

int U4PortA = 0;
int U4PortB = 0;
int U4PortC = 0;
int U4PortD = 0;
int U4PortE = 0;
int U4PortF = 0;
int U4PortG = 0;
int U4PortH = 0;
int U4PortI = 0;
int U4PortJ = 0;


void setup() {
  Serial.begin(9600);
  Wire.begin();

  Wire.beginTransmission(0x21);
  Wire.write(0x00);
  Wire.write(0x00);
  Wire.endTransmission();

  Wire.beginTransmission(0x21);
  Wire.write(0x01);
  Wire.write(0x00);
  Wire.endTransmission();

  Wire.beginTransmission(0x21);
  Wire.write(0x02);
  Wire.write(0x00);
  Wire.endTransmission();

  Wire.beginTransmission(0x21);
  Wire.write(0x04);
  Wire.write(0x00);
  Wire.endTransmission();

  Wire.beginTransmission(0x21);
  Wire.write(0x05);
  Wire.write(0x00);
  Wire.endTransmission();

  /*  Wire.beginTransmission(0x21);
    Wire.write(0x06);
    Wire.write(0x00);
    Wire.endTransmission();
  */

  Wire.beginTransmission(0x21);
  Wire.write(0x07);
  Wire.write(0x00);
  Wire.endTransmission();

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  //  pinMode(A6, INPUT);
  pinMode(A7, INPUT);
}

void loop() {
  Wire.beginTransmission(0x21);
  Wire.write(0x12);
  Wire.write(0);
  Wire.write(1);
  Wire.write(2);
  Wire.write(3);
  Wire.write(4);
  Wire.write(5);
  Wire.write(7);
  Wire.endTransmission();
  U4PortA = analogRead(A0);
  U4PortB = analogRead(A1);
  U4PortC = analogRead(A2);
  U4PortD = analogRead(A3);
  U4PortE = analogRead(A4);
  U4PortF = analogRead(A5);
  // U4PortG = analogRead(A7);
  //
  //  Wire.beginTransmission(0x21);
  //  Wire.write(0x12);
  //  Wire.write(8);
  //  Wire.endTransmission();
  //  U4PortH=analogRead(A8);
  //
  //  Wire.beginTransmission(0x21);
  //  Wire.write(0x12);
  //  Wire.write(9);
  //  Wire.endTransmission();
  //  U4PortI=analogRead(A9);
  //
  //  Wire.beginTransmission(0x21);
  //  Wire.write(0x12);
  //  Wire.write(12);
  //  Wire.endTransmission();
  //  U4PortJ=analogRead(A12);

  Serial.print(U4PortA);
  Serial.print(",");
  Serial.print(U4PortB);
  Serial.print(",");
  Serial.print(U4PortC);
  Serial.print(",");
  Serial.print(U4PortD);
  Serial.print(",");
  Serial.print(U4PortE);
  Serial.print(",");
  Serial.println(U4PortF);
  //  Serial.print(",");
  //  Serial.print(U4PortG);
  //  Serial.print(",");
  //  Serial.print(U4PortH);
  //  Serial.print(",");
  //  Serial.print(U4PortI);
  //  Serial.print(",");
  //  Serial.println(U4PortJ);
  //    inByte=Serial.read();
  //    for(int i=0;i<NUM;i++){
  //      sensors[i]=analogRead(i);
  //      Serial.print(sensors[i]);
  //      if(i<NUM-1){
  //        Serial.print(",");
  //      }
  //      else{
  //        Serial.print('\n');
  //      }
  //    }
}
