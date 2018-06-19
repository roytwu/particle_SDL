#include "screen.h"
namespace roy{

Screen::Screen():
	m_window(NULL), m_renderer(NULL), m_texture(NULL), 
	m_buffer1(NULL), m_buffer2(NULL){

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
	m_window = SDL_CreateWindow("explosion", 
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
    m_buffer1 = new Uint32[SCRN_WIDTH * SCRN_HEIGHT];
    m_buffer2 = new Uint32[SCRN_WIDTH * SCRN_HEIGHT];
    
    //memset(ptr_buffer, 255, SCRN_WIDTH*SCRN_HEIGHT*sizeof(Uint32));
    memset(m_buffer1, 0x00, SCRN_WIDTH*SCRN_HEIGHT*sizeof(Uint32));
    memset(m_buffer2, 0, SCRN_WIDTH*SCRN_HEIGHT*sizeof(Uint32));

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


void Screen::update(){
	SDL_UpdateTexture(m_texture, NULL, m_buffer1, SCRN_WIDTH*sizeof(Uint32));
    SDL_RenderClear(m_renderer);
    SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
    SDL_RenderPresent(m_renderer);
}


void Screen::close(){
	delete [] m_buffer1;
	delete [] m_buffer2;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}


void Screen::clear(int zeroTo255){
	memset(m_buffer1, zeroTo255, SCRN_WIDTH*SCRN_HEIGHT*sizeof(Uint32));
	memset(m_buffer2, zeroTo255, SCRN_WIDTH*SCRN_HEIGHT*sizeof(Uint32));
}


void Screen::boxBlur(){
	//swap buffers, so pixel info is in buffer2 and we're drawing to buffer11
	Uint32 *temp = m_buffer1; //store the location where buffer1 is pointing at
	m_buffer1 = m_buffer2;
	m_buffer2 = temp;

	for(int y =0; y<SCRN_HEIGHT; y++){
		for(int x=0; x<SCRN_WIDTH; x++){
			int redTotal =0;
			int greenTotal=0; 
			int blueTotal=0;
			
			// manipulating 3 by 3 grid		
			for(int row=-1; row<=1; row++){
				for(int col=-1; col<=1; col++){
					int currentX = x+col;
					int currentY = y+row;

					//ignoring pixels at the edge of the screen
					if(currentX>=0 && currentX<SCRN_WIDTH && currentY>=0 && currentY<SCRN_HEIGHT)
					{
						Uint32 color = m_buffer2[currentY*SCRN_WIDTH + currentX];
						Uint8 red = color >> 24;
						Uint8 green = color >> 16;
						Uint8 blue = color >> 8;
						redTotal += red;
						greenTotal += green;
						blueTotal += blue;
					}

				}
			}
			Uint8 red = redTotal/9;
			Uint8 green = greenTotal/9;
			Uint8 blue = blueTotal/9;

			setPixel(x, y, red, green, blue);
		}
	}
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

	m_buffer1[(y * SCRN_WIDTH) + x] = color;
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
    			m_buffer1[i+j] = hexCode[k];
    		}
    	}	
    }	
}

} //namespace roy