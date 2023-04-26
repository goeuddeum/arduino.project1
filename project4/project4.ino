#include "pitches.h"
const int buttonPin = 9; 
int seg[7] = {2,3,4,5,6,7,8};
int green=10;
int red=11;
int buz=12;

int num[11][7] = {
  {0,0,0,1,1,0,0},  //9
  {0,0,0,0,0,0,0}, //8
  {0,0,0,1,1,0,1},//7
  {0,1,0,0,0,0,0}, //6
  {0,1,0,0,1,0,0},//5
  {1,0,0,1,1,0,0}, //4
  {0,0,0,0,1,1,0},//3
  {0,0,1,0,0,1,0}, //2
   {1,0,0,1,1,1,1}, //1
  {0,0,0,0,0,0,1}, //0
  {1,1,1,1,1,1,1}, //끝
};

void setup() {
  for(int i = 0; i < 7; i++){
    pinMode(seg[i],OUTPUT);
  }
 pinMode(buttonPin, INPUT_PULLUP);
 Serial.begin(9600);
 pinMode(green,OUTPUT);
 pinMode(red,OUTPUT);
 pinMode(buz,OUTPUT);
}

void loop() {
  if(digitalRead(buttonPin) ==HIGH) {
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
    tone(buz,262);
  for(int i = 0; i < 11; i++){
    for(int j = 0; j < 7; j++){
      digitalWrite(seg[j], num[i][j]);
      
      
    }
    delay(1000);
+
  }

  delay(500);
}
else{
  digitalWrite(green,LOW);
  digitalWrite(red,HIGH);
  noTone(buz);
}
}

