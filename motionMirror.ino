//**************************************************************************************
//
//  TITLE:   MotionMirror
//  AUTHOR:  @deez79
//  DATE:    12/22/2015
//
//**************************************************************************************



//**************************************************************************************
// Info
//**************************************************************************************
/*
	This project is for creating a motion activated light, that back lights a mirror frame.
	It uses a multi-color LED strip.
	
	Originally based on Adafruits code:
	https://learn.adafruit.com/rgb-led-strips/example-code
	
	
 */
 
//***************************************************************************************
// Schematic
//***************************************************************************************
/*

Arduino
____________
|          |
|     12   |------------------------------------- PIR Sensor Middle Pin ----------------------------------
|          |                                        
|      6   |-------------------------------------/\/\/\/\ ------ Base pin of mosfet for Green ------------
|          |                                                              
|          |                                                              
|      5   |-------------------------------------/\/\/\/\ ------ Base pin of mosfet for Red --------------
|          |                                          
|          |                                        
|      3   |-------------------------------------/\/\/\/\ ------ Base pin of mosfet for Blue -------------
|          |                                        
|          |                                        
|     5v   |----------------------------------------------------+                       
|          |                                                              
|     gnd  |--------------------------------------------------------------
|          |
|          |
------------


                                        TIP120 Mosfet
                                        _____________
                                        |           |
--------Base (Gate)---------------------|           |
                                        |           |
--------Collector (Drain)---------------|           |
                                        |           |
--------Emitter (Source)----------------|           |
                                        |           |
                                        _____________


                                        TIP120 Mosfet
                                        _____________
                                        |           |
--/\/\/\------Arduino Pin for Color-----|           |
                                        |           |
--------Wire to LED Strip Color Pin-----|           |
                                        |           |
--------Common Ground ------------------|           |
                                        |           |
                                        _____________



                                        PIR Sensor
                                        ______________
                                        |            |
                                        |            |
 ----------- Positive voltage (5v)------|            |
                                        |            |
 ----------- Arduino Pin (12) ----------|            |
                                        |            |
 ----------- Common Ground (Gnd)--------|            |
                                        |            |
                                        |            |
                                        ______________


Wiring examples taken from:
https://learn.adafruit.com/assets/2692      LED Strip

https://learn.adafruit.com/assets/543       PIR Sensor

*/

//***************************************************************************************
// Main Sketch
//***************************************************************************************

//*****************************************
// Constants
//*****************************************

#define REDPIN 5
#define GREENPIN 6
#define BLUEPIN 3

#define pirPin 12       



//*****************************************
// Variables
//*****************************************

int motionDetect = 0; 
int FADESPEED = 5;          // make this higher to slow down
int waitTime = 500;         // wait time used as a base to multiply against.

//*****************************************
// Functions
//*****************************************

void red(){
    int r;
    for (r = 0; r < 256; r++) { 
        analogWrite(REDPIN, r);
        delay(FADESPEED);
  } 
}

void appOff(){
    analogWrite(GREENPIN, 0);
	analogWrite(BLUEPIN, 0);
	analogWrite(REDPIN, 0);
}

//*****************************************
// Setup
//*****************************************
void setup() {

  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
  pinMode(pirPin, INPUT);
  
}
 
//*****************************************
// Loop
//*****************************************
void loop(){  

int r, g, b, a, flash;
motionDetect = digitalRead(pirPin);
	if (motionDetect == HIGH){
			delay(waitTime);
			if (motionDetect == HIGH){
				red();
				delay(waitTime*2);
				for (a = 0; a < 256; a++) { 
					analogWrite(GREENPIN, a);
					analogWrite(BLUEPIN, a);
					delay(FADESPEED);
				}
				delay(waitTime*10);
				

				}
			else if (motionDetect == LOW){
					analogWrite(GREENPIN, 0);
					analogWrite(BLUEPIN, 0);
					analogWrite(REDPIN, 0);
			}
	}else if (motionDetect == LOW){
        appOff();
	}

}	//end Loop()                
