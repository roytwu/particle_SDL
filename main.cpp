#include <iostream>
#include <string>
#include <SDL.h>
#include <math.h>
#include "screen.h"
using std::cout;
using std::endl;
using std::string;

using namespace roy;

int main(){
	Screen c_scrn;
	if(c_scrn.init() == false){
		cout << "Error initializing SDL." << endl;
	}

	double max_RGB = 0; 
	while(true)  //while quit is false, run the loop
	{
		
		int elapased_msec = SDL_GetTicks();     //get milli-seconds
		double elapased_sec = 0.001*elapased_msec; //in term of second
		
		double red = (1+cos(elapased_sec))*(255/2);
		double green = (1+sin(elapased_sec))*(255/2);
		if(green>max_RGB) {max_RGB = green;}

		//Draw screen
		for(int y=0; y<Screen::SCRN_HEIGHT; y++){
			for(int x=0; x<Screen::SCRN_WIDTH; x++){
				c_scrn.setPixel(x, y, red, green, 0);
			}
		}

		c_scrn.update(); //update the screen		
		if(c_scrn.processEvent() == false){break;} //Check for message/events
	}

	cout << "Max_RGB: " << max_RGB << endl; //RGB value range from 0 to 255
	c_scrn.close();
	return 0; 
}