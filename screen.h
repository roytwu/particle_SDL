#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <SDL.h>
namespace roy{
// 


class Screen{
private:
	SDL_Window   *m_window;
	SDL_Renderer *m_renderer;
	SDL_Texture  *m_texture;
	Uint32       *m_buffer;

	// const static short RED_SHIFT = 24;
	// const static short GREEN_SHIFT = 16; 
	// const static short BLUE_SHIFT = 8;

public:	
	const static int SCRN_WIDTH = 800;
	const static int SCRN_HEIGHT = 600;
	Screen();
	//virtual ~Screen();

	bool init();
	bool processEvent();
	void close();
};



} //namespace roy
#endif //_SCREEN_H_