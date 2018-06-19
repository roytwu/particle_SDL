#ifndef _SWARM_H_
#define _SWARM_H_

#include "particle.h"

namespace roy{

class Swarm{
private:
	Particle * mp_particle; 
	int m_lastTime;

public:	
	Swarm();
	virtual ~Swarm();
	const static int NUM_PTCL = 5000;  //number of particle

	//const Particle * const getParticle() {return mp_particle;}; //in-line declaration
	const Particle * const getParticle();

	void swm_update(int elapased_msec);
	// void clear();
};




}  //namespace roy

#endif //_SWARM_H_