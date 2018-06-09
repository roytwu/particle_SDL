#include "screen.h"
namespace roy{

Screen::Screen():
	m_window(NULL), m_renderer(NULL), m_texture(NULL), m_buffer(NULL){

}


// bool Screen::init(){
// 	m_window = NULL;

// 	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);

// 	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA888,
// 		SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

// 	m_buffer1 = new Unit32[SCREEN_WIDTH * SCREEN_HEIGHT];
// 	m_buffer2 = new Unit32[SCREEN_WIDTH * SCREEN_HEIGHT];
// }


bool Screen::init(){
	//Test to see if SDL work
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {return false;}

	
	// create a 800x600 window
	m_window = SDL_CreateWindow("test_pattern", 
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCRN_WIDTH, SCRN_HEIGHT,
		SDL_WINDOW_SHOWN);
	
	if(m_window == NULL){
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    m_texture =  SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
    	SDL_TEXTUREACCESS_STATIC, SCRN_WIDTH, SCRN_HEIGHT);

    if(m_renderer == NULL){ 
    	SDL_DestroyRenderer(m_renderer);
    	SDL_DestroyWindow(m_window);
    	SDL_Quit();
    	return false; 
    }

    //allocating memory for all the pixels on the screen, each pixel requires 32 bit
    m_buffer = new Uint32[SCRN_WIDTH * SCRN_HEIGHT];
    
    //memset(ptr_buffer, 255, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));
    memset(m_buffer, 0xFF, SCRN_WIDTH*SCRN_HEIGHT*sizeof(Uint32));

    
    //Creating Test Pattern, hex code: 0xRRGGBBAA
    const long int hexCode[] = {
    	0xFFFFFFFF, 0xFFFF00FF, 0x00FFFFFF, 0x00FF00FF,
    	0xFF00FFFF, 0xFF0000FF, 0x0000FFFF, 0x000000FF
    };

    for(int k=0; k<8; k++){	
    	for(int i=(SCRN_WIDTH/8)*k; i<SCRN_WIDTH*SCRN_HEIGHT; i=i+SCRN_WIDTH){
    		for (int j=0; j<(SCRN_WIDTH/8); j++){		
    			m_buffer[i+j] = hexCode[k];
    		}
    	}	
    }


    SDL_UpdateTexture(m_texture, NULL, m_buffer, SCRN_WIDTH*sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);


	return true;
}

bool Screen::processEvent(){
	SDL_Event event;
	while(SDL_PollEvent(&event)) //process event queue
		{
			if(event.type == SDL_QUIT){ 
				return false;  //terminate the outer while loop
			}  
		}	
	return true;
}


// void Screen::update(){
// 	SDL_UpdateTexture(m_texture, NULL, m_frontBuffer, SCREEN_WIDTH * sizeof(Uint32));
// 	SDL_RenderClear(m_renderer);
// 	SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
// 	SDL_RenderPresent(m_renderer);
// }
//
// void Screen::close(){
// 	delete[] m_buffer1;
// 	delete[] m_buffer2;
// 	SDL_DestroyTexture(m_texture);
// 	SDL_DestroyRenderer(m_renderer);
// 	SDL_DestroyWindow(m_window);
// 	SDL_QUit();
// }

void Screen::close(){
	delete [] m_buffer;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

} //namespace roy