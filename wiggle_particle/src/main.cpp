#include <iostream>
#include <string>
#include <SDL.h>
#include <math.h>
#include <stdlib.h> //srand
#include <time.h>  //time
#include "screen.h"
#include "particle.h"
#include "swarm.h"

using std::cout;
using std::endl;
using std::string;

using namespace roy;

int main(){

	srand(time(NULL)); //random number generator

	Screen scrn_o;  //Initiate the Screen class
	if(scrn_o.init() == false){ 
		cout << "Error initializing SDL." << endl;
	}

	Swarm swarm_o;
	double max_R = 0, max_G =0; 


	while(true)  
	{
		int elapased_msec = SDL_GetTicks();     //get milli-seconds
		double elapased_sec = 0.001*elapased_msec; //in term of second
		
		scrn_o.clear(0); //clear the screen
		swarm_o.update();

		double red = (1+cos(elapased_sec))*(255/2);
		double green = (1+sin(elapased_sec))*(255/2);
		if(red>max_R) {max_R = red;}
		if(green>max_G) {max_G = green;}


		// if(elapased_sec < 2){
		// 	scrn_o.testPattern();
		// } else{
			// scrn_o.clear(0); //paint screen with black

			const Particle * const p_constPtcl = swarm_o.getParticle();
			for(int i=0; i<Swarm::NUM_PTCL; i++){
				Particle ptcl_o = p_constPtcl[i];  //ptcl:=particle 

				int x = (ptcl_o.m_x+1) * Screen::SCRN_WIDTH/2;  //0 to scrn width
				int y = (ptcl_o.m_y+1) * Screen::SCRN_HEIGHT/2; //0 to scrn height
				//scrn_o.setPixel(x, y, red, green, 0);
				scrn_o.setPixel(x, y, 200, 250, 150);

			}
		
		// }

		// //Draw the entire screen
		// for(int y=0; y<Screen::SCRN_HEIGHT; y++){
		// 	for(int x=0; x<Screen::SCRN_WIDTH; x++){
		// 		scrn_o.setPixel(x, y, red, green, 0);
		// 	}
		// }

		scrn_o.update(); //update the screen		
		if(scrn_o.processEvent() == false){break;} //Check for message/events
	}

	cout << "Max_RGB: " << max_R << " " << max_G << endl; //RGB value range from 0 to 255
	scrn_o.close();
	return 0; 
}