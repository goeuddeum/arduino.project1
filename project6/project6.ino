const int buttonPin = 2; 
const int buttonPin2 =10; 
const int trigPin = 12;  
const int echoPin = 13;
float duration = 0, distance = 0; 
int seg[7] = {9,3,4,5,6,7,8};
int green=A1;
int red=A2;
int buz=11;
unsigned int on_off=0;
unsigned long t1_prev=0;
const unsigned long t1_delay=500;
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
void stopall() {
  digitalWrite(green, LOW);
  digitalWrite(red, HIGH);
  noTone(buz);
}
void trapiclight(){
  noTone(buz);
  delay(100);
  for(int i = 0; i < 11; i++){
    for(int j = 0; j < 7; j++){
      digitalWrite(seg[j], num[i][j]);
      digitalWrite(red,LOW);
      digitalWrite(green,HIGH);
    if(i>5){
      tone(buz,262);
    }
    }
    delay(1000);
  }
  delay(500);
}
void usual(){
  noTone(buz);
  delay(100);
   for(int i = 0; i < 11; i++){
    for(int j = 0; j < 7; j++){
      digitalWrite(seg[j], num[i][j]);
      digitalWrite(green,LOW);
      digitalWrite(red,HIGH);
 if(i>5){
      tone(buz,523);
    }
    }
    delay(500);
  }
  delay(500);
}
void setup() {
  for(int i = 0; i < 7; i++){
    pinMode(seg[i],OUTPUT);
  }
 Serial.begin(9600);
 pinMode(green,OUTPUT);
 pinMode(red,OUTPUT);  
 pinMode(buz,OUTPUT);
 pinMode(buttonPin,OUTPUT);
 pinMode(buttonPin2,OUTPUT);
 pinMode(trigPin, OUTPUT);  
pinMode(echoPin, INPUT);  
}
void loop() {
trapiclight();
delay(100);
stopall();
delay(3000);
usual();
delay(100);
  }