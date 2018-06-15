#ifndef _PARTICLE_H_
#define _PARTICLE_H_
namespace roy{

class Particle{
private:

public:	
	double m_x;
	double m_y;

	double m_xspeed;
	double m_yspeed; 
	
	Particle();
	virtual ~Particle();

	void update();

};




}  //namespace roy


#endif //_PARTICLE_H_