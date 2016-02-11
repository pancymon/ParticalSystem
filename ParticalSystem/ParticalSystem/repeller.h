#ifndef REPELLER_H
#define REPELLER_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Repeller
{
public:
	Repeller();
	Repeller(Vector2f pos);

	void SetLocation(Vector2f pos);

	Vector2f location;

};

#endif
