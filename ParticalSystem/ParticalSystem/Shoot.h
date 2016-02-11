#ifndef SHOOT_H
#define SHOOT_H

#include"ParticalSystem.h"

class Shoot : public ParticleSystem
{
public:

	Time m_CurrentLifeTime;

	Shoot(unsigned int count, PrimitiveType type, float lifeTime, Vector2f pos);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void resetParticle(std::size_t index);

	virtual void setup();

	virtual void update(sf::Time elapsed);
};

#endif
