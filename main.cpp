#include <iostream>
#include <string>
#include <SDL.h>
using std::cout;
using std::endl;
using std::string;


int main(){
	//Test to see if SDL work
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Init failed." << endl;
		cout << SDL_GetError() << endl;
		return 1;
	}
	cout << endl << "SDL Init succeeded!" << endl << endl;
	
	// create a 800x600 window
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;
	SDL_Window *window = SDL_CreateWindow("Particle_Fire", 
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);
	
	if(window == NULL){
		SDL_Quit();
		cout << SDL_GetError() << endl;
		return 2;
	}

	SDL_Event event;
	bool quit = false;  
	while(!quit)  //while quit is false, run the loop
	{
		//Update particles
		//Draw particles
		//Check for message/events

		while(SDL_PollEvent(&event)) //process event queue
		{
			if(event.type == SDL_QUIT){ quit = true; }  //terminate the outer while loop
		}
	}


	SDL_DestroyWindow(window);
	SDL_Quit();


	return 0; 
}