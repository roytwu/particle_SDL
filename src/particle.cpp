#include <stdlib.h>
#include <math.h> //M_PI
#include "particle.h"

#include <iostream>
using std::cout;
using std::endl;

namespace roy{

Particle::Particle(){
	// //rand()/RAND_MAX will return a double between 0 and 1
	// //initializing the particle positions at a random value
	// m_x = ( (2.0*rand())/RAND_MAX )-1; //range from -1 to 1
	// m_y = ( (2.0*rand())/RAND_MAX )-1;  


	//initialize the particle at the center of the screen
	m_x=0;
	m_y=0;

	//Rectangle method
	double spd_gain = 0.0003;
	// m_xspeed = spd_gain*( (2.0*rand())/RAND_MAX -1);  //-1 to 1
	// m_yspeed = spd_gain*( (2.0*rand())/RAND_MAX -1);
	
	//polar coordinate method
	m_direction = ( 2* M_PI*rand() )/RAND_MAX; //radian
	m_speed = spd_gain*rand()/RAND_MAX;
	m_xspeed = m_speed * cos(m_direction);
	m_yspeed = m_speed * sin(m_direction);
}

Particle::~Particle(){

}

// //upadat() for rectangle method
// void Particle::update(){
// 	m_x += m_xspeed; //updating m_x with m_xspeed
// 	m_y += m_yspeed;

// 	//m_x amd m_y ranges from -1 and 1
// 	//if the particle is at the screen edge, inverse its speed
// 	//so it will head back
	
// 	if (m_x<=-1 || m_x>=1) {  
// 		m_xspeed = -m_xspeed;
// 	} 

// 	if (m_y<=-1 || m_y>=1) {
// 		m_yspeed = -m_yspeed;
// 	} 

// }

void Particle::ptcl_update(int interval){

	m_x += m_xspeed * interval; 
	m_y += m_yspeed * interval;

}





} //namespace roy