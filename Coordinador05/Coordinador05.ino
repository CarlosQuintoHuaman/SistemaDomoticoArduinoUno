#include <SoftwareSerial.h>

SoftwareSerial bt(2,3);  //Simular puerto serie por software

char c, z, c1, z1;  //Variables para almacenar los caracteres que recibinos a traves del puerto serie con XBee (c) y el puerto serie simulado con bluetooth (z)
int t=0, n, m, tt=0, t1=0, tt2=0, t2=0;  //Variables para almacenar el numero que recibimos a traves del puerto serie, XBee(n), bluetooth (m). Las "t" para crear los timers
int boton1=6, boton2=7, boton3=8, boton4=9, boton5=10, boton6=11;  //Variables para configurar los pines de cada boton
int datoBoton1=0, datoBoton2=0, datoBoton3=0, datoBoton4=0, datoBoton5=0, datoBoton6=0, dato1=0, dato2=0;  //Variables para almacenar el modo de cada boton: ON=1, OFF=0
int estado1, estado2, estado3, estado4, estado5, estado6;  //Variable para almacenar la lectura de cada una de las patillas de los botones


void setup(){
  Serial.begin(9600);  //Inicializamos el puerto serie (físico)
  bt.begin(9600);  //Iniciamos puerto serie simulado
  //Iniciamos pines como entrada
  pinMode(boton1,INPUT);
  pinMode(boton2,INPUT);
  pinMode(boton3,INPUT);
  pinMode(boton4,INPUT);
  pinMode(boton5,INPUT);
  pinMode(boton6,INPUT);
  z=' ';
  tt=millis()/1000;
  //tt2=millis()/1000;
}

void loop(){
  //Si hay datos en el buffer del bluetooth se cargan, letra en c, y numero en n
  if(bt.available()>0){
    c=bt.read();
    n=bt.parseInt();
  }
  
  if(c=='a') enviar();  //Si recibe "a" del bluetooth, Ardcuino devuelve el estado de los botones
  
  delay(20);
  
  if(Serial.available()>0){
    z=Serial.read();
  }
  
  if(z=='k'){
    dato1=1;
    z=' ';
  }
  
  //delay(20);
  
  if(z=='s' || m==2){
    dato2=1;
    z=' ';
  }
  
  if(z=='A'){
    datoBoton6=3;
    z=' ';
  }
  
  if(z=='B'){
    datoBoton6=0;
    z=' ';
  }
  
  
  //Bucle para comprobar si los esclavos están activos
  t1=millis()/1000;
  //t2=millis()/1000;
  if((t1-tt)>=4){
    //delay(100);
    z=' ';
    Serial.println('a');  //Preguntamos a S1 si esta activo
    if(Serial.available()>0){
      z=Serial.read();
    }
    
    if(z=='k'){  //Si esta activo
      dato1=1;
      Serial.println('q');  //Manda la orden a S2 de que no esta solo
      //z=' ';
    }else{
      dato1=0;
      Serial.println('r');  //De lo contrario manda a S2 que esta solo
    }
    
    z=' ';
    delay(10);
    Serial.println('b');  //Preguntamos a S2
    if(Serial.available()>0){
      z=Serial.read();
      m=Serial.parseInt();
    }
    
    while(Serial.available()>0){
      z=Serial.read();
      m=Serial.parseInt();
      if(z=='\n') break;
    }
    
    if(z=='s'|| m==2){
      dato2=1;
      Serial.println('k');
      //z=' ';
    }else{
      dato2=0;
      Serial.println('l');
    }
    delay(40);

    tt=millis()/1000;
    z=' ';
  }
  
  
  
  estado1=digitalRead(boton1);  //Lee si el boton esta pulsado
  if(estado1 || c=='c'){
    if(datoBoton1==0 || n==1){
      datoBoton1=1;
      Serial.println('c');
    }else{
      datoBoton1=0;
      Serial.println('d');
    }
    c=' ';
    delay(500);
  }
  
  estado2=digitalRead(boton2);
  if(estado2 || c=='d'){
    if(datoBoton2==0 || n==1){
      datoBoton2=1;
      Serial.println('e');
    }else{
      datoBoton2=0;
      Serial.println('f');
    }
    c=' ';
    delay(500);
  }
  
  estado3=digitalRead(boton3);
  if(estado3 || c=='e'){
    if(datoBoton3==0 || n==1){
      datoBoton3=1;
      Serial.println('g');
    }else{
      datoBoton3=0;
      Serial.println('h');
    }
    c=' ';
    delay(500);
  }
  
  estado4=digitalRead(boton4);
  if(estado4 || c=='f'){
    if(datoBoton4==0 || n==1){
      datoBoton4=1;
      Serial.println('i');
    }else{
      datoBoton4=0;
      Serial.println('j');
    }
    c=' ';
    delay(500);
  }
  
  estado5=digitalRead(boton5);
  if(estado5 || c=='g'){
    if(datoBoton5==0 || n==1){
      datoBoton5=1;
      Serial.println('m');
    }else{
      datoBoton5=0;
      Serial.println('n');
    }
    c=' ';
    delay(500);
  }
  
  estado6=digitalRead(boton6);
  if(estado6 || c=='h'){
    if(datoBoton6==0 || n==1){
      datoBoton6=1;
      Serial.println('o');
    }else{
      datoBoton6=2;
      Serial.println('p');
    }
    c=' ';
    delay(500);
  }
  
  /*if(z=='t'){
    datoBoton6=3;
    z=' ';
  }
  if(z=='u'){
    datoBoton6=0;
    z=' ';
  }*/
  delay(100);
}

void enviar(){
 //delay(20);
  bt.print(0);
  bt.println(datoBoton1);
  bt.print(0);
  bt.println(datoBoton2);
  bt.print(0);
  bt.println(datoBoton3);
  bt.print(0);
  bt.println(datoBoton4);
  bt.print(0);
  bt.println(datoBoton5);
  bt.print(0);
  bt.println(datoBoton6);
  c=' ';
}
