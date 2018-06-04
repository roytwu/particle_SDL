#include <iostream>
#include <string>
#include <SDL.h>
using std::cout;
using std::endl;
using std::string;


int main(){

	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Init failed." << endl;
		return 1;
	}

	cout << endl << "SDL Init succeedeed!" << endl;
	
	SDL_Quit();


	return 0; 
}