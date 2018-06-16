#include "swarm.h"
namespace roy{

Swarm::Swarm(){
	mp_particle = new Particle[NUM_PTCL];
	m_lastTime = 0;
}

Swarm::~Swarm(){
	delete [] mp_particle;

}

const Particle * const Swarm::getParticle() { 
	return mp_particle; 
}

void Swarm::swm_update(int elapased_msec){

	int interval = elapased_msec - m_lastTime;

	for(int i=0; i<Swarm::NUM_PTCL; i++){
		mp_particle[i].ptcl_update(interval);
	}
	m_lastTime = elapased_msec;
}	


} //namespace roy