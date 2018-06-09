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
	const int SCRN_WIDTH = 800;  //screen width
	const int SCRN_HEIGHT = 600; //screen height
	SDL_Window * window = SDL_CreateWindow("test_pattern", 
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCRN_WIDTH, SCRN_HEIGHT,
		SDL_WINDOW_SHOWN);
	
	if(window == NULL){
		SDL_Quit();
		cout << SDL_GetError() << endl;
		return 2;
	}

	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
    SDL_Texture * texture =  SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888,
    	SDL_TEXTUREACCESS_STATIC, SCRN_WIDTH, SCRN_HEIGHT);

    if(renderer == NULL){ 
    	cout << "Could not return renderer" << endl;
    	SDL_DestroyRenderer(renderer);
    	SDL_DestroyWindow(window);
    	SDL_Quit();
    	return 3; 
    }

    //allocating memory for all the pixels on the screen, each pixel requires 32 bit
    Uint32 * p_buffer = new Uint32[SCRN_WIDTH * SCRN_HEIGHT];
    
    //memset(ptr_buffer, 255, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
    memset(p_buffer, 0xFF, SCRN_WIDTH*SCRN_HEIGHT*sizeof(Uint32));

    
    //Creating Test Pattern, hex code: 0xRRGGBBAA
    const long int hexCode[] = {
    	0xFFFFFFFF, 0xFFFF00FF, 0x00FFFFFF, 0x00FF00FF,
    	0xFF00FFFF, 0xFF0000FF, 0x0000FFFF, 0x000000FF
    };

    for(int k=0; k<8; k++){	
    	for(int i=(SCRN_WIDTH/8)*k; i<SCRN_WIDTH*SCRN_HEIGHT; i=i+SCRN_WIDTH){
    		for (int j=0; j<(SCRN_WIDTH/8); j++){		
    			p_buffer[i+j] = hexCode[k];
    		}
    	}	
    }


    SDL_UpdateTexture(texture, NULL, p_buffer, SCRN_WIDTH*sizeof(Uint32));
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


	delete [] p_buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();


	return 0; 
}