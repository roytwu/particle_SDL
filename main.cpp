#include <iostream>
#include <string>
#include <SDL.h>
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

	while(true)  //while quit is false, run the loop
	{
		//Update particles
		//Draw particles
		//Check for message/events

		if(c_scrn.processEvent() == false){
			break;
		}
	}

	c_scrn.close();
	return 0; 
}