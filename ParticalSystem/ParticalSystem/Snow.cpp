#include"Snow.h"
#include<cmath>

Snow::Snow(unsigned int count, PrimitiveType type, float lifeTime, Vector2f pos) : ParticleSystem(count, type, lifeTime), m_CurrentLifeTime(seconds(lifeTime))
{
	//if (type == Points)
	//	m_vertices = VertexArray(type, count);
	//else if (type == Quads)
	//{
	//	m_vertices = VertexArray(type, count * 4);
	//	//Texture texture;
	//	m_Texture.loadFromFile("C:/Users/Pancy/Pictures/snowflake.png");
	//	m_RenderState.texture = &m_Texture;
	//}
	setEmitter(pos);
	setup();

}

void Snow::resetParticle(std::size_t index)
{
	// give a random velocity and lifetime to the particle
	//float angle = (std::rand() % 360) * 3.14f / 180.f;
	//float speed = (std::rand() % 50) + 50.f;
	//m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
	m_particles[index].velocity = Vector2f(0,0);
	int half_Life = m_lifetime.asMilliseconds() / 2;
	m_particles[index].m_LifeTime = sf::milliseconds((std::rand() % half_Life) + half_Life);

	// reset the position of the corresponding vertex
	//m_particles[index].m_Vertex->position = m_emitter;
	if (m_type == Quads)
		m_vertices[index * 4].position = m_emitter;
	else
	{
		m_vertices[index].position = m_emitter;
		m_vertices[index].position.x = rand() % 1024;
		m_vertices[index].position.y = 0;
	}
	m_vertices[index].color = Color(255, 255, 255);
}

void Snow::setup()
{
	m_lifetime = seconds(10);
	for (std::size_t i = 0; i < m_particles.size(); i++)
		resetParticle(i);
	
	return;
	m_CurrentLifeTime = m_lifetime;
	int signal = rand() % 2;
	if (signal == 0)
		signal = -1;
	for (size_t i = 0; i < m_particles.size(); i++)
	{
		float angle = (std::rand() % 30 + 255) * 3.14f / 180.f;
		float speed = (std::rand() % 100 + 20);
		m_particles[i].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);

		m_particles[i].velocity.x = abs(m_particles[i].velocity.x) * 3 * signal;
		int half_Life = m_lifetime.asMilliseconds() / 2;
		m_particles[i].m_LifeTime = sf::milliseconds((std::rand() % half_Life) + half_Life);

		// reset the position of the corresponding vertex
		//m_particles[index].m_Vertex->position = m_emitter;
		if (m_type == Quads)
			m_vertices[i * 4].position = m_emitter;
		else
			m_vertices[i].position = m_emitter;
	}
}

void Snow::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	ParticleSystem::draw(target, states);
}

void Snow::update(sf::Time elapsed)
{
	m_CurrentLifeTime -= elapsed;
	ParticleSystem::update(elapsed);
	for (std::size_t i = 0; i < m_particles.size(); i++)
	{
		if (m_vertices[i].position.x > 1024)
		{
			m_vertices[i].position.x = 0;
			m_particles[i].velocity = Vector2f(-5,0);
		}
	}
}