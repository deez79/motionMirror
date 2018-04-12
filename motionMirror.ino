// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!
 
#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3
#define FADESPEED 5     // make this higher to slow down


//mix in PIR Code
int pirPin = 12;
int motionDetect= 0; 

 
void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  pinMode(pirPin, INPUT);
}
 
 
void loop() {
int r, g, b;
motionDetect = digitalRead(pirPin);
	if (motionDetect == HIGH){
     
		  // fade from blue to violet
		  for (r = 0; r < 256; r++) { 
			analogWrite(REDPIN, r);
			delay(FADESPEED);
		  } 
		  // fade from violet to red
		  for (b = 255; b > 0; b--) { 
			analogWrite(BLUEPIN, b);
			delay(FADESPEED);
		  } 
		  // fade from red to yellow
		  for (g = 0; g < 256; g++) { 
			analogWrite(GREENPIN, g);
			delay(FADESPEED);
		  } 
		  // fade from yellow to green
		  for (r = 255; r > 0; r--) { 
			analogWrite(REDPIN, r);
			delay(FADESPEED);
		  } 
		  // fade from green to teal
		  for (b = 0; b < 256; b++) { 
			analogWrite(BLUEPIN, b);
			delay(FADESPEED);
		  } 
		  // fade from teal to blue
		  for (g = 255; g > 0; g--) { 
			analogWrite(GREENPIN, g);
			delay(FADESPEED*2);
		  } 
	}else if (motionDetect == LOW){
	analogWrite(GREENPIN, 0);
	analogWrite(BLUEPIN, 0);
	analogWrite(REDPIN, 0);
	}
	
}