#ifndef PARTICALSYSTEM_H
#define PARTICALSYSTEM_H

#include"partical.h"

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:

	ParticleSystem(unsigned int count, PrimitiveType type, float lifeTime, Vector2f pos = Vector2f());

	void setEmitter(sf::Vector2f position);

	virtual void update(sf::Time elapsed);

	int AddNumber();
	int SubNumber();


	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	virtual void resetParticle(std::size_t index);
	//{
	//	// give a random velocity and lifetime to the particle
	//	float angle = (std::rand() % 60 + 240) * 3.14f / 180.f;
	//	float speed = (std::rand() % 50) + 50.f;
	//	m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
	//	int half_Life = m_lifetime.asMilliseconds() / 2;
	//	m_particles[index].m_LifeTime = sf::milliseconds((std::rand() % half_Life) + half_Life);

	//	// reset the position of the corresponding vertex
	//	//m_particles[index].m_Vertex->position = m_emitter;
	//	if (m_type == Quads)
	//		m_vertices[index * 4].position = m_emitter;
	//	else
	//		m_vertices[index].position = m_emitter;
	//}

	virtual void setup();

	std::vector<Particle> m_particles;
	sf::VertexArray m_vertices;
	sf::Time m_lifetime;
	sf::Vector2f m_emitter;
	PrimitiveType m_type;

	float m_WholeLife = 10;

	RenderStates m_RenderState;
	Texture m_Texture;
};

#endif
