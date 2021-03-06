#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <SDL.h>
namespace roy{


class Screen{
private:
	SDL_Window   *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture  *m_texture;
	Uint32       *m_buffer;
	Uint32 setColor(Uint8 red, Uint8 green, Uint8 blue);


	// const static short RED_SHIFT = 24;
	// const static short GREEN_SHIFT = 16; 
	// const static short BLUE_SHIFT = 8;

public:	
	const static int SCRN_WIDTH = 1204;
	const static int SCRN_HEIGHT = 768;
	Screen();
	//virtual ~Screen();

	bool init();
	bool processEvent();
	void update();
	void close();
	void clear(int zeroTo255); //clear screen, 0 black, 255 white

	
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	
	
	void testPattern(); //draw test pattern
};



} //namespace roy
#endif //_SCREEN_H_