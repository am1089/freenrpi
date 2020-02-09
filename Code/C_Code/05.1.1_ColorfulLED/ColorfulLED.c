/**********************************************************************
* Filename    : ColorfulLED.c
* Description : Random color change ColorfulLED
* Author      : www.freenove.com
* modification: 2019/12/27
**********************************************************************/
#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>
#include <stdlib.h>

#define ledPinRed    0
#define ledPinGreen  1
#define ledPinBlue   2

#define ORIGCODE 0

int ledArray[][3] = {
		     {0, 100, 100},
		     {100, 0, 100},
		     {100, 100, 0},
		     {0, 0, 100},
		     {0, 100, 0},
		     {100, 0, 0},
		     {50, 60, 75}
};

const int ledArrSize = sizeof(ledArray)/sizeof(ledArray[0]);

void setupLedPin(void)
{
	softPwmCreate(ledPinRed,  0, 100);	//Creat SoftPWM pin for red
	softPwmCreate(ledPinGreen,0, 100);  //Creat SoftPWM pin for green
	softPwmCreate(ledPinBlue, 0, 100);  //Creat SoftPWM pin for blue
}

void setLedColor(int r, int g, int b)
{
	softPwmWrite(ledPinRed,   r);	//Set the duty cycle 
	softPwmWrite(ledPinGreen, g);   //Set the duty cycle 
	softPwmWrite(ledPinBlue,  b);   //Set the duty cycle 
}

int main(void)
{
  int i;
	int r,g,b;
	
	printf("Program is starting ...\n");
	
	wiringPiSetup();	//Initialize wiringPi.
	
	setupLedPin();
	while(1){
#if ORIGCODE
		r=random()%100;  //get a random in (0,100)
		g=random()%100;  //get a random in (0,100)
		b=random()%100;  //get a random in (0,100)
		setLedColor(r,g,b);//set random as the duty cycle value 
		printf("r=%d,  g=%d,  b=%d \n",r,g,b);
		delay(1000);
#else
#if 0
		for (r = 99; r >= 0; r--) {
		  for (g = 99; g >= 0; g--) {
		    for (b = 99; b >= 0; b--) {
		      setLedColor(r,g,b);
		      printf("r=%d,  g=%d,  b=%d \n",r,g,b);
		      delay(100);
		    }
		  }
		}
#else
		for (i = 0; i < ledArrSize; i++) {
		  r = ledArray[i][0];
		  g = ledArray[i][1];
		  b = ledArray[i][2];
		  setLedColor(r,g,b);
		  printf("r=%d,  g=%d,  b=%d \n",r,g,b);
		  delay(1000);
		}
#endif
#endif
	}
	return 0;
}
