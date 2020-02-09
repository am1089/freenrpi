/**********************************************************************
* Filename    : LightWater.c
* Description : Use LEDBar Graph(10 LED) 
* Author      : www.freenove.com
* modification: 2019/12/27
**********************************************************************/
#include <wiringPi.h>
#include <stdio.h>

#define ledCounts 10
int pins[ledCounts] = {0,1,2,3,4,5,6,8,9,10};

int lightArray[][ledCounts] = {
			       [0] = {1,0,0,0,0,0,0,0,0,0},
			       [1] = {1,1,0,0,0,0,0,0,0,0},
			       [2] = {1,1,1,0,0,0,0,0,0,0},
			       [3] = {1,1,1,1,0,0,0,0,0,0},
			       [4] = {1,1,1,1,1,0,0,0,0,0},
			       [5] = {1,1,1,1,1,1,0,0,0,0},
			       [6] = {1,1,1,1,1,1,1,0,0,0},
			       [7] = {1,1,1,1,1,1,1,1,0,0},
			       [8] = {1,1,1,1,1,1,1,1,1,0},
			       [9] = {1,1,1,1,1,1,1,1,1,1},
			       [10] = {1,1,1,1,1,1,1,1,1,0},
			       [11] = {1,1,1,1,1,1,1,1,0,0},
			       [12] = {1,1,1,1,1,1,1,0,0,0}, 
			       [13] = {1,1,1,1,1,1,0,0,0,0},
			       [14] = {1,1,1,1,1,0,0,0,0,0},
			       [15] = {1,1,1,1,0,0,0,0,0,0},
			       [16] = {1,1,1,0,0,0,0,0,0,0},
			       [17] = {1,1,0,0,0,0,0,0,0,0},
			       [18] = {1,0,0,0,0,0,0,0,0,0},
			       [19] = {0,0,0,0,0,0,0,0,0,0},
};

const int lightArrSize = sizeof(lightArray)/sizeof(lightArray[0]);

/*
 * Write digital values from pinVals to pins array.
 * pinCount is the size of the arrays.
 */
void writeAllPins(int pins[], int pinVals[], int pinCount) {
  int i;
  int val;

  for (i=0; i < pinCount; i++) {
    val = pinVals[i] ? HIGH : LOW;
    digitalWrite(pins[i], val);
  }
}


void main(void)
{
	int i;
	printf("Program is starting ... \n");
	
	wiringPiSetup(); //Initialize wiringPi.
	
	for(i=0;i<ledCounts;i++){       //Set pinMode for all led pins to output
		pinMode(pins[i], OUTPUT);		
	}
	while(1){
	  for (i=0; i < lightArrSize; i++) {
	    writeAllPins(pins, lightArray[i], ledCounts);
	    delay(150);
	  }
	}
}
