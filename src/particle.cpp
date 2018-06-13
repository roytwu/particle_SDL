#include <stdlib.h>
#include "particle.h"

namespace roy{

Particle::Particle(){
	//rand()/RAND_MAX will return a double between 0 and 1
	m_x = ( (2.0*rand())/RAND_MAX )-1; //range from -1 to 1
	m_y = ( (2.0*rand())/RAND_MAX )-1;  
}

Particle::~Particle(){

}

} //namespace roy