#include <IRremote.h>      // Include the lib

int RECV_PIN = 8;
int ledPin1=13;
int ledPin2=2;
IRrecv irrecv(RECV_PIN);
int c=0;
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(ledPin1,OUTPUT);
  pinMode(ledPin2,OUTPUT);
//  pinMode(RECV_PIN,INPUT);
}

void loop() {
  //int senseValue=digitalRead(RECV_PIN);
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    irrecv.resume(); // Receive the next value
  
  //delay(100);

switch(results.value){

case 16: digitalWrite(ledPin1,HIGH);
          //c=1;
          break;
case 2064: digitalWrite(ledPin2, HIGH);
          //c=1;
          break;
case 2704: digitalWrite(ledPin1, LOW);
           digitalWrite(ledPin2, LOW);
           break;
case 1040: if (digitalRead(ledPin1) == HIGH && digitalRead(ledPin2) == LOW){
                  digitalWrite(ledPin1, LOW);
                  digitalWrite(ledPin2, HIGH);
                //  Serial.println("INSIDE");
                 }
                 else if (digitalRead(ledPin1) == LOW && digitalRead(ledPin2) == HIGH){
                  digitalWrite(ledPin2, LOW);
                  digitalWrite(ledPin1, HIGH);
                 }
                 Serial.println("Case BACK");
                 break;      
}

//case default: 
//              break;
}
 
 /* if(results.value == 16 && c==0)
 
  {
    digitalWrite(ledPin1,HIGH);
    Serial.println("ON");
    
    c=1;
    }
 
  
  
  
   else if(results.value == 2704 && c==1)
  
  {
    digitalWrite(ledPin,LOW);
    Serial.println("OFF");
    c=0; 
  }*/
  
  
 }

  
