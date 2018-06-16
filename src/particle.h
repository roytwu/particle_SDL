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
	
	double m_speed;  //polar coordinate
	double m_direction; //polar coordinate

	
	Particle();
	virtual ~Particle();

	void ptcl_update(int interval);

};




}  //namespace roy


#endif //_PARTICLE_H_