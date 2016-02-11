#ifndef PARTICAL_H
#define PARTICAL_H

#include<iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Particle {
public:
	//Vertex* m_Vertex;
	Vector2f velocity;
	Vector2f acceleration;
	Time m_LifeTime;
	

	Particle();



	//void update(Time elapsed) {
	//	m_LifeTime -= elapsed;

	//	//if (m_LifeTime <= sf::Time::Zero)
	//		//m_PSystem


	//	m_Vertex->position += velocity * elapsed.asSeconds();

	//	velocity += acceleration*elapsed.asSeconds();


	//	// update the alpha (transparency) of the particle according to its lifetime
	//	float ratio = m_LifeTime.asSeconds() / m_LifeTime.asSeconds();
	//	m_Vertex->color.a = static_cast<sf::Uint8>(ratio * 255);
	//}



};

#endif