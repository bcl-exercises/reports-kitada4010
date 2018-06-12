
int val=0; //入力される値を格納する為の変数

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //モニターに出力する為の設定
}

void loop() {
  // put your main code here, to run repeatedly:
  //ANALOGINの0番ピンからデータを受け付ける
  val=analogRead(0)/4;
  Serial.println(val);
  delay(50);
}
