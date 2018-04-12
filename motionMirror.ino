#define REDPIN 5 
#define GREENPIN 6
#define BLUEPIN 3
#define pirPin 12

#define FADESPEED 5     // make this higher to slow down


int motionDetect = 0; 
int r, g, b, a, flash;


void setup() {
    
    pinMode(REDPIN, OUTPUT);
    pinMode(GREENPIN, OUTPUT);
    pinMode(BLUEPIN, OUTPUT);
    pinMode(pirPin, INPUT);

} 
 

void loop(){  
    
    motionDetect = digitalRead(pirPin);
    
  if (motionDetect == HIGH){
      delay(500);
      if (motionDetect == HIGH){
        for (r = 0; r < 256; r++) { 
          analogWrite(REDPIN, r);
          delay(FADESPEED);
        }
        delay(1000);
        for (a = 0; a < 256; a++) { 
          analogWrite(GREENPIN, a);
          analogWrite(BLUEPIN, a);
          delay(FADESPEED);
        }
        delay(5000);
        

        }
      else if (motionDetect == LOW){
          analogWrite(GREENPIN, 0);
          analogWrite(BLUEPIN, 0);
          analogWrite(REDPIN, 0);
      }
  }else if (motionDetect == LOW){
  analogWrite(GREENPIN, 0);
  analogWrite(BLUEPIN, 0);
  analogWrite(REDPIN, 0);
  }

} //end Loop()              

