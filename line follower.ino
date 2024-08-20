#include <SoftwareSerial.h>
SoftwareSerial BT_Serial(0, 1); // RX, TX



#define left 10
#define center 11
#define right 9


#define ENA 3
#define IN1 2
#define IN2 4
#define ENB 5
#define IN3 7
#define IN4 8


int bt_data; // 2el data 2el btta5d
int Speed = 90;  

int mode=0;

void setup(){ // ht7t 2el setup code

pinMode(right, INPUT);   
pinMode(left, INPUT); 
pinMode(center, INPUT);
pinMode(ENA, OUTPUT); 
pinMode(IN1, OUTPUT);  
pinMode(IN2, OUTPUT);  
pinMode(IN3, OUTPUT);  
pinMode(IN4, OUTPUT); 
pinMode(ENB, OUTPUT); 
Serial.begin(9600); 
BT_Serial.begin(9600); 
delay(500);
}


void loop(){  
  
if(BT_Serial.available() > 0){      
bt_data = BT_Serial.read();      
if(bt_data > 20){Speed = bt_data;}      
}

     if(bt_data == 8){mode=1; Speed=90;} 
else if(bt_data == 9){mode=0; Stop();}    

analogWrite(ENA, Speed); 
analogWrite(ENB, Speed); 

if(mode==0){     


     if(bt_data == 1){forword(); }  
else if(bt_data == 2){backword();}  
else if(bt_data == 3){turnLeft();}  
else if(bt_data == 4){turnRight();} 
else if(bt_data == 5){Stop(); }     

   
else if(bt_data == 6){turnLeft();  delay(400);  bt_data = 5;}
else if(bt_data == 7){turnRight(); delay(400);  bt_data = 5;}
}else{    



if((digitalRead(right) == 1)&&(digitalRead(left) == 1)&&(digitalRead(center) == 0)){forword();}  
if((digitalRead(right) == 0)&&(digitalRead(left) == 1)&&(digitalRead(center) == 0)){turnRight();}
if((digitalRead(right) == 1)&&(digitalRead(left) == 0)&&(digitalRead(center) == 0)){turnLeft();} 
if((digitalRead(right) == 0)&&(digitalRead(left) == 0)&&(digitalRead(center) == 0)){Stop();} 
if((digitalRead(right) == 1)&&(digitalRead(left) == 1)&&(digitalRead(center) == 1)){Stop();} 
if((digitalRead(right) == 0)&&(digitalRead(left) == 1)&&(digitalRead(center) == 1)){turnRight();}
if((digitalRead(right) == 1)&&(digitalRead(left) == 0)&&(digitalRead(center) == 1)){turnLeft();}   
} 

delay(10);
}

void forword() {
  analogWrite(ENA, Speed-12);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2,LOW); 
  digitalWrite(IN3,HIGH );
  digitalWrite(IN4, LOW);
}
void turnLeft() {
  analogWrite(ENA, Speed-12);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
void turnRight() {
  analogWrite(ENA, Speed-12);
  analogWrite(ENB, Speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
void Stop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}


void backword(){ //backword
 analogWrite(ENA, Speed-12);
  analogWrite(ENB, Speed);
digitalWrite(IN1, LOW);  
digitalWrite(IN2, HIGH); 
digitalWrite(IN3, HIGH);
digitalWrite(IN4, LOW);  
}


