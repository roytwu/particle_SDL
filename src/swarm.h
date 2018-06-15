#ifndef _SWARM_H_
#define _SWARM_H_

#include "particle.h"

namespace roy{

class Swarm{
private:
	Particle * mp_particle; 

public:	
	Swarm();
	virtual ~Swarm();
	const static int NUM_PTCL = 1000;  //number of particle

	//const Particle * const getParticle() {return mp_particle;}; //in-line declaration
	const Particle * const getParticle();

	void update();
	// void clear();
};




}  //namespace roy

#endif //_SWARM_H_