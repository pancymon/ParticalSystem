#include"repeller.h"

Repeller::Repeller() 
{
	location = Vector2f(0,-100);
}
Repeller::Repeller(Vector2f pos)
{
	location = pos;
}

void Repeller::SetLocation(Vector2f pos)
{
	location = pos;
}