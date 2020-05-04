#include<LiquidCrystal.h>
#include <Servo.h> 
#include <SoftwareSerial.h>
SoftwareSerial mySerial(14,15);
LiquidCrystal lcd(4,5,6,7,8,9);
int irPin2 = 3;
int ledPin1 = 12;
int ledPin2 = 13;
 int ldrPin = 10; //digital ldr pin at 2
 /*int relayPin = 11;*/
 int irPin1 = 11; 
 int servoPin = 2; 
// Create a servo object 
Servo Servo1; 

/*int servoPin = 2; */ 
/*Servo Servo1;  * Permission granted to share this code given that this
 * note is kept with the code.
 * Disclaimer: this code is "AS IS" and for educational purpose only.
 * 
 */  void SendMessage()
{
  mySerial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
  delay(1000);  // Delay of 1000 milli seconds or 1 second
  mySerial.println("AT+CMGS=\"+918770301871\"\r"); // Replace x with mobile number
  delay(1000);
  mySerial.println("hello ayush what is your problem");// The SMS text you want to send
  delay(100);
   mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
}


 void RecieveMessage()
{
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
 }
 

void setup() {
  // Light LDR Sensor Code by Robojax.com 20180210
  
Serial.begin(9600);
 mySerial.begin(9600);
  
  lcd.begin(16,2);
  Servo1.attach(servoPin); 

  pinMode(irPin1, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(irPin2,INPUT);



 {
lcd.setCursor(0,0);                         //lcd display the system
  lcd.print("INITILIZING");
  lcd.setCursor(4,1);                         //lcd display the system
  lcd.print("SYSTEM");
  delay(3000);
  lcd.setCursor(0,0);
  lcd.print("SUN TRACKING");
  lcd.setCursor(0,1);
  lcd.print("SOLAR PANEL WITH");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("INTELLIGENT STREET");
  lcd.setCursor(0,1);
  lcd.print("LIGHTING SYSTEM");
  delay(2000);
  lcd.clear();
   lcd.setCursor(3,0);
  lcd.print("DAY MODE");
  lcd.setCursor(3,1);
  lcd.print("ACTIVATED");
}
}

void loop() {

  if (Serial.available()>0)

   switch(Serial.read())
  {
    case 's':
      SendMessage();
      break;
    case 'r':
      RecieveMessage();
      break;
  }

 if (mySerial.available()>0)
   Serial.write(mySerial.read());

{
Servo1.write(0); 
   delay(2000); 
   // Make servo go to 90 degrees 
   Servo1.write(45); 
   delay(2000); 
   // Make servo go to 180 degrees 
   Servo1.write(90); 
   delay(2000); 
   Servo1.write(135); 
   delay(2000); 
   // Make servo go to 90 degrees 
   Servo1.write(180); 
   delay(2000); 
   // Make servo go to 180 degrees 
   Servo1.write(0); 
   delay(900); 
}


  
  // Light LDR Sensor Code by Robojax.com 20180210
  int L =digitalRead(ldrPin);// read the sensor 
 
 
  
      if(L == 1){
    
    digitalWrite(ledPin1,HIGH);// turn the relay ON
    digitalWrite(ledPin2,HIGH);
    lcd.setCursor(0,0);
    lcd.print("NIGHT MODE");
  lcd.setCursor(2,1);
  lcd.print("ACTIVATED");
  delay(10000);
  lcd.clear();
analogWrite(ledPin1,10);
analogWrite(ledPin2,10);
lcd.setCursor(0,0);
lcd.print("POWER SAVING");
  lcd.setCursor(0,1);
  lcd.print("MODE ACTIVATED");
/*delay(9000);*/

delay(5000);
lcd.clear();
  if(digitalRead(irPin1) == HIGH){
       analogWrite(ledPin1, 255); 
       /*digitalWrite(relayPin, HIGH);  //the led visualizes the sensors output pin state*/
    
      
       }
       
     if(digitalRead(irPin2)==HIGH)      //Check the sensor output
     {
analogWrite(ledPin2, 255);   // set the LED on
   
    }
    
if(digitalRead(irPin1)==LOW)  
{
digitalWrite(ledPin1, HIGH);    // set the LED off
}
if(digitalRead(irPin2)==LOW)  
{
digitalWrite(ledPin2, HIGH);    // set the LED off
}

 
  else{

     
     digitalWrite(ledPin1,LOW);// turn the relay OFF
     digitalWrite(ledPin2,LOW);
    
  }
  
  
  
}
} 

