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

	/*polar coordinate*/
	// double spd_gain = 0.0001;  //orignal parameter
	// m_speed = (spd_gain*rand())/RAND_MAX;  //original parameter

	/*to use original parameters, comment out the following 3 lines*/
	double spd_gain = 0.015;                  //gain pair with square m_speed
	m_speed = (spd_gain*rand())/RAND_MAX;                   //square m_speed
	m_speed *= m_speed; //equal to m_speed = m_speed*m_speed, square m_speed
	
	
	m_direction = ( 2* M_PI*rand() )/RAND_MAX; //radian
	m_xspeed = m_speed * cos(m_direction);
	m_yspeed = m_speed * sin(m_direction);
}

Particle::~Particle(){

}


void Particle::ptcl_update(int interval){
	m_x += m_xspeed * interval; 
	m_y += m_yspeed * interval;

}





} //namespace roy