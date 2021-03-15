#include <SFML/Graphics.hpp>
#include <iostream>
#include "Particle.h"

using namespace std;
using namespace sf;

float R_Float(float a, float b)
{
	srand(time(NULL));
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;

}

Vector2f attarctor(300, 300);

int main() {

	// sfml window settings;
	sf::ContextSettings config;
	config.antialiasingLevel = 2;

	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML works!", 0, config);
	window.setFramerateLimit(144);

	vector<Particle> Particles;

	CircleShape circ(1);
	
	circ.setOrigin(0.5, 0.5);
	circ.setFillColor(Color(255, 255, 255));

	for (int i = 0; i < 5000; i++) {
	Particles.push_back(Particle(rand() % 600, rand() % 600));
	}

	window.setFramerateLimit(60);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		attarctor.x = sf::Mouse::getPosition(window).x;
		attarctor.y = sf::Mouse::getPosition(window).y;

		window.clear(sf::Color::Transparent);

		for (int i = 0; i < Particles.size(); i++) {
		    Particles[i].attracted(attarctor);
		    Particles[i].update();
	     	Particles[i].display(window);
		}

		window.display();

	}

	return NULL;
}