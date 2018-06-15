#include <stdlib.h>
#include <math.h> //M_PI
#include "particle.h"

#include <iostream>
using std::cout;
using std::endl;

namespace roy{

Particle::Particle(){
	//rand()/RAND_MAX will return a double between 0 and 1
	//initializing the particle positions at a random value
	m_x = ( (2.0*rand())/RAND_MAX )-1; //range from -1 to 1
	m_y = ( (2.0*rand())/RAND_MAX )-1;  


	// //initialize the particle at the center of the screen
	// m_x=0;
	// m_y=0;

	//Rectangle method
	double spd_gain = 0.005;
	m_xspeed = spd_gain*( (2.0*rand())/RAND_MAX -1);  //-1 to 1
	m_yspeed = spd_gain*( (2.0*rand())/RAND_MAX -1);
		
}

Particle::~Particle(){

}


void Particle::update(){
	m_x += m_xspeed; //updating m_x with m_xspeed
	m_y += m_yspeed;

	/*m_x amd m_y ranges from -1 and 1
	if the particle is at the screen edge, inverse its speed
	so it will head back*/
	if (m_x<=-1 || m_x>=1) {  
		m_xspeed = -m_xspeed;
	} 

	if (m_y<=-1 || m_y>=1) {
		m_yspeed = -m_yspeed;
	} 

}






} //namespace roy