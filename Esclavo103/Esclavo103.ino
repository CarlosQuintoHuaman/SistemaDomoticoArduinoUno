#include <Servo.h>

Servo myServo;  //Libreria para usar el servo

char c;
int led1=2, led2=3, led3=4, led4=5, ventilador=6, servo=9;
int rele1=8, rele2=9, rele3=10, rele4=11;
boolean solo=false;
int dato1=0, dato2=0, t=0, n, i=0, j=179;
//int boton1=6, boton2=7, boton3=8, boton4=9;
int datoBoton1=0, datoBoton2=0, datoBoton3=0, datoBoton4=0, datoBoton5=0, datoBoton6=5;
//int estado1, estado2, estado3, estado4, estado5, estado6;
void setup(){
  Serial.begin(9600);
  //bt.begin(9600);
  myServo.attach(9);
  for(int z=2;z<12;z++){
    pinMode(z,OUTPUT);
    digitalWrite(z,LOW);
  }
  digitalWrite(rele1,HIGH);
  digitalWrite(rele2,HIGH);
  digitalWrite(rele3,HIGH);
  digitalWrite(rele4,HIGH);
}

void loop(){
  if(Serial.available()>0){
    c=Serial.read();
    //n=Serial.parseInt();
  }
  
  if(c=='a'){
    Serial.println('k');
    c=' ';
  }
 
  if(c=='c'){
    datoBoton1=1;
    c=' ';
  }

  if(c=='d'){
    datoBoton1=0;
    c=' ';
  }
    
  if(c=='e'){
    datoBoton2=1;
    c=' ';
  }
  
  if(c=='f'){
    datoBoton2=0;
    c=' ';
  }
  
  if(c=='g'){
    datoBoton3=1;
    c=' ';
  }
  
  if(c=='h'){
    datoBoton3=0;
    c=' ';
  }
  
  if(c=='i'){
    datoBoton4=1;
    c=' ';
  }
  
  if(c=='j'){
    datoBoton4=0;
    c=' ';
  }
  
  if(c=='k'){
    solo=false;
    c=' ';
  }
  
  if(c=='l'){
    solo=true;
    c=' ';
  }
  
  if(solo){
    if(c=='m'){
      datoBoton5=1;
      c=' ';
    }
    
    if(c=='n'){
      datoBoton5=0;
      c=' ';
    }
    
    if(c=='o'){
      datoBoton6=1;
      c=' ';
    }
    
    if(c=='p'){
      datoBoton6=0;
      c=' ';
    }
  }
  
  if(datoBoton1==0) digitalWrite(led1,LOW);
  if(datoBoton1==1) digitalWrite(led1,HIGH);
  
  if(datoBoton2==0) digitalWrite(led2,LOW);
  if(datoBoton2==1) digitalWrite(led2,HIGH);
  
  if(datoBoton3==0) digitalWrite(led3,LOW);
  if(datoBoton3==1) digitalWrite(led3,HIGH);
  
  if(datoBoton4==0) digitalWrite(led4,LOW);
  if(datoBoton4==1) digitalWrite(led4,HIGH);
  
  if(datoBoton5==0) digitalWrite(ventilador,LOW);
  if(datoBoton5==1) digitalWrite(ventilador,HIGH);
  
  if(datoBoton6==1){
    
    myServo.write(i);
    delay(100);
    i++;
    if(i==180){
      datoBoton6=5;
      i=0;
      Serial.println('A');
    }
  }
  
  if(datoBoton6==0){
    myServo.write(179-i);
    delay(100);
    i++;
    if(i==179){
      datoBoton6=5;
      i=0;
      Serial.println('B');
    }
  }
  
  delay(100);
}

