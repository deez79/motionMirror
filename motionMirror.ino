//**************************************************************************************
//
//  TITLE:      Motion Mirror 
//  AUTHOR:     deez79 
//  DATE:       04/09/2018 (refactor) 
//
//**************************************************************************************



//**************************************************************************************
// Info
//**************************************************************************************

/*

    This project uses a PIR sensor to trigger LED strip lights.
    

 */
 
//***************************************************************************************
// Schematic
//***************************************************************************************

/*

Teensy 3.0
____________                                           _______                                                    
|          |                                          /       \
|          |                                        +-----------+
|     12   |----------------------------------------|   PIR     |
|          |                                        +-----------+
|          |                                            |   |          
|     6    |-------/\/\/\/\------->|G---------------+   |   |
|          |                                        |   |   | 
|     5    |-------/\/\/\/\------->|R---------------+   |   |
|          |                                        |   |   |                       
|     3    |------/\/\/\/\-------->|B---------------+   |   |
|          |                                        |   |   |
|          |                                        |   |   |
|          |                                        |   |   |
|     gnd  |----------------------------------------+---+   |
|          |                                                |
|     5v   |------------------------------------------------+
|          |
------------

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

#define FADESPEED 6     // make this higher to slow down

//*****************************************
// Variables
//*****************************************

int motionDetect = 0; 
int r, g, b, a, flash;
int control_var = 0;
int control_var_prev_state = 0;

//*****************************************
// Functions
//*****************************************

void SM_mm () {
    switch (control_var) {
        case 0: // Reset!
            control_var = 1;
            break;
            
        case 1: // Start 
            
            break;
            
        case 2: // 
            
            break;
    }
}

//*****************************************
// Setup
//*****************************************
void setup() {
    
    pinMode(REDPIN, OUTPUT);
    pinMode(GREENPIN, OUTPUT);
    pinMode(BLUEPIN, OUTPUT);
    pinMode(pirPin, INPUT);

}	//end setup()
 
//*****************************************
// Loop
//*****************************************
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

}	//end Loop()              

