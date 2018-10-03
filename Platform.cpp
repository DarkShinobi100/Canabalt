//library includes
#include <cstdlib>

//project files
#include "Platform.h"
#include "AssetManager.h"


//Constants
#define SIZE_MIN_X 10
#define SIZE_MAX_X 30
#define SIZE_MIN_Y 1
#define SIZE_MAX_Y 5
#define POS_Y_MIN 850
#define POS_Y_MAX 1000
#define GAP_SIZE 200

//initialise static data
float Platform::s_furthestPoint = 0;

Platform::Platform()
	: m_sprite()
{
	m_sprite.setTexture(AssetManager::GetTexture("graphics/block.png"));
}

void Platform::Spawn()
{
	//choose a random size for our platform
	sf::Vector2i size;
	size.x = rand() % (SIZE_MAX_X - SIZE_MIN_X) + SIZE_MIN_X;
	size.y = rand() % (SIZE_MAX_Y - SIZE_MIN_Y) + SIZE_MIN_Y;
	m_sprite.setScale(size.x, size.y);

	//choose a random Y position
	sf::Vector2f position;
	position.y = rand() % (POS_Y_MAX - POS_Y_MIN) + POS_Y_MIN;
	position.x = s_furthestPoint + GAP_SIZE;
	m_sprite.setPosition(position);

	//update the furthest point to the right
	//our new platform is now furthest to the right
	s_furthestPoint = m_sprite.getPosition().x + m_sprite.getGlobalBounds().width;
}

void Platform::Draw(sf::RenderTarget& _target)
{
	_target.draw(m_sprite);
}

sf::FloatRect Platform::GetCollider()
{
	return m_sprite.getGlobalBounds();
}