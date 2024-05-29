#include <Arduino.h>


#define echoPin 12 
#define trigPin 13 
int enA=9;
int in1=8;
int in2=7; 
int enB=3; 
int in3=4; 
int in4=5;
long time, distance;
void setup() {

    pinMode(echoPin, INPUT);
    pinMode(trigPin, OUTPUT); 
    Serial.begin(115200);
    

    pinMode(enA, OUTPUT);   
    pinMode(in1, OUTPUT);   
    pinMode(in2, OUTPUT);    
  
    pinMode(enB, OUTPUT);   
    pinMode(in3, OUTPUT);   
    pinMode(in4,OUTPUT);
}

void loop() {
   analogWrite(enA ,255);
   analogWrite(enB ,255);

  digitalWrite(trigPin, LOW);    //sensor deactivated
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);   //Sensore was ordered to generate the sound wave
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);    //The trig pin is set to LOW to prevent new waves from being generate
  time = pulseIn(echoPin, HIGH); //measuring the time it takes for the sound wave to return 
                                
  Serial.println("distance");
  Serial.println(distance);



 



      if (distance < 45 && distance > 1) 
  { stop();
    delay(500);
    back();  
    delay(2000);
    right();  
    delay(1000);
    stop();
  }
  else {  
    forward(); 
    
   
  }
}


void forward(){
    
  digitalWrite (in4 , LOW ) ;
  digitalWrite (in3,HIGH ) ;  
  digitalWrite(in1,HIGH);  
  digitalWrite(in2 ,LOW ); 
  Serial.println("forward ") ;  
 
}

void stop(){
    
  digitalWrite (in4,LOW ); 
  digitalWrite (in3 , LOW ); 
  digitalWrite(in1 ,LOW );
  digitalWrite(in2 ,LOW );
  Serial.println ("stop"); 

}

void back(){
  digitalWrite (in3 , LOW ) ;
  digitalWrite (in4,HIGH ) ;  
  digitalWrite(in2,HIGH);  
  digitalWrite(in1 ,LOW ); 
  Serial.println("back ");
  
}

void right(){
  digitalWrite (in4 , LOW ) ;
  digitalWrite (in3,HIGH ) ;  
  digitalWrite(in2,HIGH);  
  digitalWrite(in1 ,LOW );   
  Serial.println(" right ");
  
}
void left(){
    
  digitalWrite (in3 , LOW ) ;
  digitalWrite (in4,HIGH ) ;  
  digitalWrite(in1,HIGH);  
  digitalWrite(in2 ,LOW );   
  Serial.println(" left ");
  
}

