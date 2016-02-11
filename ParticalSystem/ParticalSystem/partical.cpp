#include"partical.h"

Particle::Particle() {
	//m_Vertex = NULL;
	acceleration = Vector2f(0, 30);
	m_LifeTime = seconds(0);
	//velocity = Vector2f(rand() % 3 - 2, rand() % 3 - 3);
}