#include<Wire.h> //成功
const int L3GD20_ADDR =0x6A;

unsigned int readRegister(byte reg){
  Wire.beginTransmission(L3GD20_ADDR);
  Wire.write(reg);
  Wire.endTransmission();

  Wire.requestFrom(L3GD20_ADDR, 1);
  return Wire.read();
}

void writeRegister(byte reg, byte data){
  Wire.beginTransmission(L3GD20_ADDR);
  Wire.write(reg);
  Wire.write(data);
  Wire.endTransmission();
}

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);

  int res = readRegister(0x0F);
  Serial.println(res, HEX);

  writeRegister(0x20, B00001111);

}

void loop() {
  // put your main code here, to run repeatedly:
  int x, y, z;
  int h, l;
  
  // read X
  l = readRegister(0x28);
  h = readRegister(0x29);
  x = h << 8| l;

  //read Y
  l=readRegister(0x2A);
  h=readRegister(0x2B);
  y = h<<8 | l;

  //read Z
  l=readRegister(0x2C);
  h=readRegister(0x2D);
  z=h<<8|l;

  Serial.print(x);
  Serial.print(",");
  Serial.print(y);
  Serial.print(",");
  Serial.print(z);
  Serial.print(",     ");
  

  delay(200);

  

}
