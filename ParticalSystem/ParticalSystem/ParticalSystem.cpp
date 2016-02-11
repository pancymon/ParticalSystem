#include"ParticalSystem.h"
#include"PSManager.h"


ParticleSystem::ParticleSystem(unsigned int count, PrimitiveType type, float lifeTime, Vector2f pos) :
	m_lifetime(sf::seconds(lifeTime)),
	m_emitter(pos.x, pos.y),
	m_particles(count),
	m_type(type)
{
	if (type == Points)
		m_vertices = VertexArray(type, count);
	else if (type == Quads)
	{
		m_vertices = VertexArray(type, count * 4);
		//Texture texture;
		m_Texture.loadFromFile("C:/Users/Pancy/Pictures/snowflake.png");
		m_RenderState.texture = &m_Texture;
	}
	setup();

}

int ParticleSystem::AddNumber()
{
	int num = m_particles.size() * 2;
	vector<Particle> particles(num);
	int i = m_type == Quads ? 4 : 1;
	VertexArray vertices(m_type, num*i);
	m_particles = particles;
	m_vertices = vertices;
	setup();
	return num;
}

int ParticleSystem::SubNumber()
{
	int num = m_particles.size() / 2 + 1;
	vector<Particle> particles(num);
	int i = m_type == Quads ? 4 : 1;
	VertexArray vertices(m_type, num*i);
	m_particles = particles;
	m_vertices = vertices;
	setup();
	return num;
}

void ParticleSystem::setEmitter (sf::Vector2f position)
{
	m_emitter = position;
}

void ParticleSystem::setup()
{
	for (std::size_t i = 0; i < m_particles.size(); ++i)
	{
		m_particles[i].m_LifeTime = sf::milliseconds((std::rand() % 2000) + 1000);
		if( m_type==Points )
			m_vertices[i].color = Color(128, 255, 255);
		else if (m_type == Quads)
		{
			float length = 512;
			m_vertices[i * 4].texCoords = Vector2f(0, 0);
			m_vertices[i * 4 + 1].texCoords = Vector2f(length, 0);
			m_vertices[i * 4 + 2].texCoords = Vector2f(length, length);
			m_vertices[i * 4 + 3].texCoords = Vector2f(0, length);
		}
	}
}



void ParticleSystem::update(sf::Time elapsed)
{
	//cout << "hello" << endl;
	Vector2f repellerPos = PSManager::Instance()->m_Repellers[0].location;

	m_WholeLife -= elapsed.asSeconds();

	for (std::size_t i = 0; i < m_particles.size(); ++i)
	{
		Particle& p = m_particles[i];
		p.m_LifeTime -= elapsed;

		if (p.m_LifeTime <= sf::Time::Zero)
			resetParticle(i);

		// update the position of the corresponding vertex
		//p.m_Vertex->position += p.velocity * elapsed.asSeconds();

		Vector2f direction;
		if (m_type == Quads)
		{
			m_vertices[i * 4].position += p.velocity * elapsed.asSeconds();
			float length = 4;
			m_vertices[4 * i + 1].position = m_vertices[4 * i].position + Vector2f(length, 0);
			m_vertices[4 * i + 2].position = m_vertices[4 * i].position + Vector2f(length, length);
			m_vertices[4 * i + 3].position = m_vertices[4 * i].position + Vector2f(0, length);
			direction = m_vertices[4*i].position - repellerPos;
		}
		else
		{
			m_vertices[i].position += p.velocity * elapsed.asSeconds();
			direction = m_vertices[i].position - repellerPos;
		}

		p.velocity += m_particles[i].acceleration*elapsed.asSeconds();
		//Vector2f direction = p.m_Vertex->position - repellerPos;

		
		float magnitude = sqrt(direction.x*direction.x+ direction.y*direction.y);
		
		//Vector2f force = direction / magnitude / (direction.x*direction.x + direction.y*direction.y);
		Vector2f force = direction / magnitude;

		float mass = 5;

		force /= mass;

		p.velocity += force;

		float ratio = p.m_LifeTime.asSeconds() / m_lifetime.asSeconds();
		//m_vertices[i].color.a = 0;
		m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);

	}
}



void ParticleSystem::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the transform
	states.transform *= getTransform();

	//states.texture = NULL;

	// draw the vertex array
	target.draw(m_vertices, states);
}

void ParticleSystem::resetParticle(std::size_t index)
{
	// give a random velocity and lifetime to the particle
	float angle = (std::rand() % 60 + 240) * 3.14f / 180.f;
	float speed = (std::rand() % 30) + 30.f;
	m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
	int half_Life = m_lifetime.asMilliseconds()/2;
	m_particles[index].m_LifeTime = sf::milliseconds((std::rand() % half_Life) + half_Life);

	// reset the position of the corresponding vertex
	//m_particles[index].m_Vertex->position = m_emitter;
	if (m_type == Quads)
		m_vertices[index * 4].position = m_emitter;
	else
		m_vertices[index].position = m_emitter;
}