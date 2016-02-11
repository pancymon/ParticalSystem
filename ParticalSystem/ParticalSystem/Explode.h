#ifndef EXPLODE_H
#define EXPLODE_H

#include"ParticalSystem.h"

class Explode : public ParticleSystem
{
public:

	Time m_CurrentLifeTime;

	Explode(unsigned int count, PrimitiveType type, float lifeTime, Vector2f pos);

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void resetParticle(std::size_t index);

	virtual void setup();

	virtual void update(sf::Time elapsed);
};

#endif
