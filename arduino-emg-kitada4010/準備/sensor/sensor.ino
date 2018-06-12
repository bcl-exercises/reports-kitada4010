
int val=0; //入力される値を格納する為の変数
int vala=0;
int h=10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //モニターに出力する為の設定
//  vala=analogRead(0)/4;
}

void loop() {
  // put your main code here, to run repeatedly:
  //ANALOGINの0番ピンからデータを受け付ける
  val=analogRead(0)/4;
  vala+= (val-vala)/h;
  Serial.println(vala);
 // delay(50);
}
