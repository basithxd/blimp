#include <Servo.h>
#include <String.h>


int MOTOR_INPUT = 9;// Initializing pin number 
int SERVO_INPUT = 10;
char dataStore[2];
int datastoren;
  int srCount = 0;
Servo myservo;

int STD = 1;

int chartoint(char a)
{
  int r;

  r = a - '0';
  return r;
}


void setup() //The setup function will only run once, after each powerup.It initializes and sets the initial values
{
  Serial.begin(9600);   //Sets the baud for serial data transmission (Bits Per Second)
  pinMode(MOTOR_INPUT,OUTPUT); //Specify behaviour of pin to work either as an input or an output
  myservo.attach(SERVO_INPUT);
   myservo.write(80);
}

void loop() 
  
{
  int dataNumber;//Recived data will get stored in this variable
  char data = 'm';
  
  
  

  if(Serial.available()) //Here We're checking whether data is available or not
  { 
      
    data = Serial.read();
    if(data=='l' || data =='m' || data =='r' || data =='s')
    {srCount = 0;
     dataStore[0] = data;
     
    }

    if(data =='f' || data =='b')
    {srCount = 1;
     dataStore[1] = data;
     
      
      }

     if(data =='0' || data =='1' || data =='2' || data =='3' || data =='4' || data =='5' || data =='6' || data =='7' || data =='8' || data =='9' )
     {srCount =2;
      
      datastoren = chartoint(data);
      
     }
    
    Serial.print(dataStore);
    //Data received printed
    
     if(dataStore[0]=='l')//Left
    {
     
      myservo.write(45);
    }
    else if(dataStore[0]=='m') //LeftStop
    {
     
      myservo.write(80);
    }
     else if(dataStore[0]=='r')                  //Right
    {
     
      myservo.write(110);
    }
    else if(dataStore[0]=='s')//RightStop
    {
      
      myservo.write(80);
    }
    
    if(dataStore[1]=='b')//LED OFF
    {
     
      digitalWrite(MOTOR_INPUT,LOW);
    }
    
     if(dataStore[1]=='f')//LED ON
    { 
      //while(Serial.available()!){
      digitalWrite(MOTOR_INPUT,HIGH);  
      delay(STD*datastoren);
      digitalWrite(MOTOR_INPUT,LOW);
      delay(STD*datastoren);
      digitalWrite(MOTOR_INPUT,HIGH);
     //}
      
      // Write a HIGH or a LOW value to a digital pin
    }
     
    
      
 //  dataNumber = data.toInt();
    
 //  if(dataNumber>=0 && dataNumber<=180) //servo 
  // myservo.write(dataNumber);

    
   // }
   
    

    
    
    } 

 
    
    
    
    }
 
