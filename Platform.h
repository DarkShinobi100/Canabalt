#pragma once

// Library includes
#include <SFML/Graphics.hpp>


class Platform
{
public:
	 
	Platform();

	void Spawn();

	void Draw(sf::RenderTarget& _target);

	sf::FloatRect GetCollider();

private:

	//assets
	sf::Sprite m_sprite;
	
	//platform shared data
	static float s_furthestPoint;

};