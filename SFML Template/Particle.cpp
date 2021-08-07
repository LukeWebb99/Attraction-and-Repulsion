#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Particle.h"
#include "VectorMath.h"

using namespace std;
using namespace sf;


void Particle::display(sf::RenderWindow &MainWindow)
{
	// S I N G L E - V E R T E X //
	/*
	sf::Vertex dots;
	dots.color = Color(50, 50, 255, 25);
	dots.position = pos;
	MainWindow.draw(&dots, 1, sf::Points);
	*/
	
	// L I N E - V E R T E X //
	
	sf::VertexArray line(sf::LineStrip, 2);
	line[0].position = (pos);
	line[1].position = (prev);
	line[1].color = (Color(255, 192, 203, 50));
	line[0].color = (Color(255, 105, 180, 10));
	prev = pos;
	MainWindow.draw(line);


	// C I R C L E //
	/*
	CircleShape circ(2);
	circ.setPosition(pos);
	circ.setOrigin(2, 2);
	circ.setFillColor(Color(60, 60, 180, 255));
	MainWindow.draw(circ);
	*/

}

void Particle::update()
{
	acc = mult(acc, 1);
	vel += acc;
	vel = limit(vel, 10);
	pos += vel;
}

void Particle::attracted(Vector2f* Target)
{
	 Vector2f Force = (*Target - pos);
	 float dsquared = magSq(Force);
	 dsquared = constrain(dsquared, 30, 100);
	 float G = 22;
	 float Strength = G / dsquared;
	 Force = setMag(Force, Strength);
	 if (dsquared < 20) {
		 Force = mult(Force, -10);
	 }
	 acc = Force;


}
