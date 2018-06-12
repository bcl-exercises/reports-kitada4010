
  int s = 0;
  int tei = 40;
  int CL =30;
  int sounds[] = {262,294,330,349,392,440,494};
  int speaker = 12;
  int BEATTIME = 100;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(0,INPUT);
 // pinMode(1,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
   s = analogRead(0)-tei;
   int katei = CL;
//   int p =analogRead(1);

   noTone(12);
   if(katei*7 < s){
   tone(speaker,sounds[6],BEATTIME);
   }
   else if(katei*6 < s){
    tone(speaker,sounds[5],BEATTIME);
   }
   else if(katei*5 < s){
   tone(speaker,sounds[4],BEATTIME);
   }
   else if(katei*4 < s){
    tone(speaker,sounds[3],BEATTIME);
   }
   else if(katei*3 < s){
   tone(speaker,sounds[2],BEATTIME);
   }   
   else if(katei*2 < s){
   tone(speaker,sounds[1],BEATTIME);
   }
   else if(katei*1 < s){
   tone(speaker,sounds[0],BEATTIME);
   }   
   delay(50);
   Serial.println(s);
}
