#define T 1000
#include<Wire.h> // 失敗
const int L3GD20_ADDR =0x6A;
int val=0; //読み取り値の変数を用意
int vala=0;
int a=10;
int inByte;


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
  inByte = 0;
  // 通信を開始
 // establishContact();
}

void loop() {
  // put your main code here, to run repeatedly:
  int x, y, z;
  int h, l;

  val=analogRead(0)/4;
 // vala+= (val-vala)/a;
  Serial.write(val);
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

  Serial.write(",");
  Serial.write(x/T);
  Serial.write(",");
  Serial.write(y/T);
  Serial.write(",");
  Serial.write(z/T);
  Serial.write("¥n");

  Serial.read();
  
  delay(200);

}

/*
void establishContact() {
  // Processingから何か文字が送られてくるのを待つ
  while (Serial.available() <= 0) {
    // 初期化用の文字列
    Serial.println("0,0"); 
    delay(300);
  }
  
}
*/
