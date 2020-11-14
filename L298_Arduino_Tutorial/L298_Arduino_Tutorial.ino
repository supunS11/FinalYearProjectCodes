#include <SoftwareSerial.h>
SoftwareSerial Blue(2, 3);
long int data;
 
int Rwheels_Forward = 7;
int Rwheels_Backward = 8;
int Lwheels_Forward = 12;
int Lwheels_Backward = 13;

long int password1 = 1;//move forward
long int password2 = 2;//turn right
long int password3 = 3;//turn left
long int password3 = 4;//move backward
long int password3 = 5;//stop

 
char state = 0;
 
 
void setup()
{
   
pinMode(Rwheels_Forward, OUTPUT); 
digitalWrite(Rwheels_Forward, LOW);
pinMode(Rwheels_Backward, OUTPUT); 
digitalWrite(Rwheels_Backward, LOW);
pinMode(Lwheels_Forward, OUTPUT); 
digitalWrite(Lwheels_Forward, LOW);
pinMode(Lwheels_Backward, OUTPUT); 
digitalWrite(Lwheels_Backward, LOW);
Serial.begin(9600);
Blue.begin(9600);
 
}
 
void loop()
{
 
 while(Blue.available()==0) ;
 
 if(Blue.available()>0) 
{
data = Blue.parseInt();
 
} 
delay(400);

//Serial.print(data);
 
  if (data == password1)
  {
  
       digitalWrite(Rwheels_Forward,HIGH);
       digitalWrite(Rwheels_Backward,LOW);
       digitalWrite(Lwheels_Forward,HIGH);
       digitalWrite(Lwheels_Backward,LOW);

       Serial.print("moving forward");
  
   }
   
   if( data == password2)
   {
       digitalWrite(Rwheels_Forward,HIGH);
       digitalWrite(Rwheels_Backward,LOW);
       digitalWrite(Lwheels_Forward,LOW);
       digitalWrite(Lwheels_Backward,LOW);
       delay(3000);
       digitalWrite(Rwheels_Forward,LOW);

       Serial.print("turned right");

   }

      if( data == password3)
   {
       digitalWrite(Rwheels_Forward,LOW);
       digitalWrite(Rwheels_Backward,LOW);
       digitalWrite(Lwheels_Forward,HIGH);
       digitalWrite(Lwheels_Backward,LOW);
       delay(3000);
       digitalWrite(Lwheels_Forward,LOW);

       Serial.print("turned left");
       
   }

         if( data == password4)
   {
       digitalWrite(Rwheels_Forward,LOW);
       digitalWrite(Rwheels_Backward,HIGH);
       digitalWrite(Lwheels_Forward,LOW);
       digitalWrite(Lwheels_Backward,HIGH);

       Serial.print("moving backward");
       
       
   }


            if( data == password5)
   {
       digitalWrite(Rwheels_Forward,LOW);
       digitalWrite(Rwheels_Backward,LOW);
       digitalWrite(Lwheels_Forward,LOW);
       digitalWrite(Lwheels_Backward,LOW);

       Serial.print("stopped");
       
       
   }
 
 }
