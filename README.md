```
+------------------------------------------------------------------------------+

        +---------------------------------------------------------------+
        | Title:        Motion Mirror                                   |
        | Author:       deez79                                          |
        | Date:         04/12/2018                                      |
        +---------------------------------------------------------------+

+------------------------------------------------------------------------------+
```

# Motion Mirror:

## Info

	This project is for creating a motion activated light, that back lights a mirror frame.
	It uses a multi-color LED strip.
	
	Originally based on Adafruits code:
	https://learn.adafruit.com/rgb-led-strips/example-code
	
	
 
## Schematic

```

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


```

* Wiring examples taken from:
  * https://learn.adafruit.com/assets/2692      LED Strip
  * https://learn.adafruit.com/assets/543       PIR Sensor
