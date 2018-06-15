#include "swarm.h"
namespace roy{

Swarm::Swarm(){
	mp_particle = new Particle[NUM_PTCL];
}

Swarm::~Swarm(){
	delete [] mp_particle;

}

const Particle * const Swarm::getParticle() { 
	return mp_particle; 
}

void Swarm::update(){
	for(int i=0; i<Swarm::NUM_PTCL; i++){
		mp_particle[i].update();
	}
}	


} //namespace roy