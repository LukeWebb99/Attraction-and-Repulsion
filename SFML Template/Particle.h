#pragma once
#include <SFML/Graphics.hpp>
#include "VectorMath.h"

using namespace sf;

class Particle {

public:
	Particle(int x, int y)
	{
		pos = Vector2f(x, y);
		prev = Vector2f(x, y);
		vel = Vector2f(x, y);
		vel = setMag(vel, rand() % 5);
		acc = Vector2f(0, 0);
	}

	void attracted(Vector2f* Target);
	void update();
	void display(sf::RenderWindow &MainWindow);

	Vector2f pos;
	Vector2f vel;
	Vector2f acc;
	Vector2f prev;

};



