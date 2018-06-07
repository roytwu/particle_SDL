#include <iostream>
#include <string>
#include <SDL.h>
//#include "screen.h"
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
	SDL_Window * window = SDL_CreateWindow("Particle_Fire", 
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);
	
	if(window == NULL){
		SDL_Quit();
		cout << SDL_GetError() << endl;
		return 2;
	}

	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture * texture =  SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
    	SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

    if(renderer == NULL){ 
    	cout << "Could not return renderer" << endl;
    	SDL_DestroyRenderer(renderer);
    	SDL_DestroyWindow(window);
    	SDL_Quit();
    	return 3; 
    }

    Uint32 * buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
    
    //memset(buffer, 255, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
    memset(buffer, 0xFF, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

    SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);

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


	delete [] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();


	return 0; 
}