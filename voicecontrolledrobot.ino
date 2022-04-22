#define m1 2
#define m2 3
#define m3 4
#define m4 5
int led = 10;
int speedPin = 6;
int mSpeed=150;
void setup() {
pinMode(m1,OUTPUT);
pinMode(m2,OUTPUT);
pinMode(m3,OUTPUT);
pinMode(m4,OUTPUT);
pinMode(speedPin,OUTPUT);
pinMode(led,OUTPUT);
Serial.begin(9600);
}
void loop() {
while (Serial.available()==0){
}
String voice = Serial.readString();
Serial.println(voice);
if (voice=="*forward#"){
analogWrite(speedPin,255);
digitalWrite(m1,LOW);
digitalWrite(m2,HIGH);
digitalWrite(m3,LOW);
digitalWrite(m4,HIGH);
digitalWrite(led,HIGH);
}
if(voice == "*backward#")
{
analogWrite(speedPin,255);
digitalWrite(m1,HIGH);
digitalWrite(m2,LOW);
digitalWrite(m3,HIGH);
digitalWrite(m4,LOW);
}
if(voice=="*left#")
{
digitalWrite(m1,LOW);
digitalWrite(m2,LOW);
digitalWrite(m3,LOW);
digitalWrite(m4,HIGH);
analogWrite(speedPin,255);
delay(10);
analogWrite(speedPin,mSpeed);
delay(3000);
voice="*stop#";
}
if(voice=="*right#")
{
digitalWrite(m1,LOW);
digitalWrite(m2,HIGH);
digitalWrite(m3,LOW);
digitalWrite(m4,LOW);
analogWrite(speedPin,255);
delay(10);
analogWrite(speedPin,mSpeed);
delay(3000);
voice="*stop#";
}
if(voice=="*stop#")
{
digitalWrite(m1,LOW);
digitalWrite(m2,LOW);
digitalWrite(m3,LOW);
digitalWrite(m4,LOW);
digitalWrite(led,HIGH);
}
}
