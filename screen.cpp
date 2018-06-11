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

	// create a window
	m_window = SDL_CreateWindow("particle_movement", 
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCRN_WIDTH, SCRN_HEIGHT,
		SDL_WINDOW_SHOWN);
	
	if(m_window == NULL){
		SDL_Quit();
		return false;
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
    m_texture =  SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888,
    	SDL_TEXTUREACCESS_STATIC, SCRN_WIDTH, SCRN_HEIGHT);

    if(m_renderer == NULL || m_texture == NULL){ 
    	SDL_DestroyRenderer(m_renderer);
    	SDL_DestroyWindow(m_window);
    	SDL_Quit();
    	return false; 
    }

    //allocating memory for all the pixels on the screen, each pixel requires 32 bit
    m_buffer = new Uint32[SCRN_WIDTH * SCRN_HEIGHT];
    
    //memset(ptr_buffer, 255, SCRN_WIDTH*SCRN_HEIGHT*sizeof(Uint32));
    memset(m_buffer, 0x00, SCRN_WIDTH*SCRN_HEIGHT*sizeof(Uint32));

	return true;
}


Uint32 Screen::setColor(Uint8 red, Uint8 green, Uint8 blue){
	Uint32 color = 0;

	color += red;
	color <<= 8;

	color += green;
	color <<= 8; 

	color += blue;
	color <<= 8; 

	color += 0xFF;
	return(color);
}

void Screen::paintScreenBackground(int blackOrWhite){
	memset(m_buffer, blackOrWhite, SCRN_WIDTH*SCRN_HEIGHT*sizeof(Uint32));
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){
    // don't plot on the edge of the screen
	if(x<0 || x>=SCRN_WIDTH || y<0 || y>=SCRN_HEIGHT){
		return;
	}

	Uint32 color = 0;
	color += red;
	color <<= 8;

	color += green;
	color <<= 8; 

	color += blue;
	color <<= 8; 

	color += 0xFF;

	m_buffer[(y * SCRN_WIDTH) + x] = color;
}


void Screen::update(){
	SDL_UpdateTexture(m_texture, NULL, m_buffer, SCRN_WIDTH*sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
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


void Screen::close(){
	delete [] m_buffer;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}


void Screen::testPattern(){
	const long int hexCode[] = {
    	setColor(255, 255, 255),  //0xFFFFFFFF
    	setColor(255, 255, 0),    //0xFFFF00FF
    	setColor(0, 255, 255),    //0x00FFFFFF
    	setColor(0, 255, 0),      //0x00FF00FF
    	setColor(255, 0, 255),    //0xFF00FFFF
    	setColor(255, 0, 0),      //0xFF0000FF
    	setColor(0, 0, 255),      //0x0000FFFF
    	setColor(0, 0, 0),        //0x000000FF  
    };
    for(int k=0; k<8; k++){	
    	for(int i=(SCRN_WIDTH/8)*k; i<SCRN_WIDTH*SCRN_HEIGHT; i=i+SCRN_WIDTH){
    		for (int j=0; j<(SCRN_WIDTH/8); j++){		
    			m_buffer[i+j] = hexCode[k];
    		}
    	}	
    }	
}

} //namespace roy