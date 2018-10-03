//project includes
#include "Player.h"
#include "AssetManager.h"

//constants
#define JUMP_SPEED -1500.0f
#define GRAVITY 2000.0f
#define STARTX 0
#define STARTY 0
#define RUN_SPEED_INITIAL 500

//Constructor
Player::Player()
	:m_sprite()
	,m_jumpSound()
    ,m_deathSound()
    ,m_landSound()
    ,m_animation()
	,m_velocity(0.0f,0.0f)
{
	//things that are only set once

	//sprite set up
	m_sprite.setTexture(AssetManager::GetTexture("graphics/playerJump.png"));

	//set up sounds
	m_jumpSound.setBuffer(AssetManager::GetSoundBuffer("audio/jump.wav"));
	m_deathSound.setBuffer(AssetManager::GetSoundBuffer("audio/death.wav"));
	m_landSound.setBuffer(AssetManager::GetSoundBuffer("audio/landing.wav"));

	//set up animation
	m_animation.SetSprite(m_sprite);
	
	Animation& runAnimation = m_animation.CreateAnimation("Run");
	runAnimation.AddFrame(AssetManager::GetTexture("graphics/playerRun1.png"));
	runAnimation.AddFrame(AssetManager::GetTexture("graphics/playerRun2.png"));
	runAnimation.SetLoop(true);
	runAnimation.SetPlaybackSpeed(10.0f);

	Animation& jumpAnimation = m_animation.CreateAnimation("Jump");
	jumpAnimation.AddFrame(AssetManager::GetTexture("graphics/playerJump.png"));

	m_animation.Play("Jump");
}

void Player::Input(sf::Event _gameEvent)
{
	// check if player has pessed "jump" button
	if (_gameEvent.type == sf::Event::KeyPressed)
	{
		//check if the desired button was pressed
		if (_gameEvent.key.code == sf::Keyboard::Space)
		{
			//player has tried to jump

			//play jump sound effect
			m_jumpSound.play();

			//set the players upwards velocity
			m_velocity.y = JUMP_SPEED;
		}
	}
}

void Player::Update(sf::Time _frameTime)
{
	//process the animation
	m_animation.Update(_frameTime);

	//apply gravity to our velocity
	float velocityChange = GRAVITY * _frameTime.asSeconds();
	m_velocity.y += velocityChange;

	//move sprite based on velocity
	sf::Vector2f currentPosition = m_sprite.getPosition();
	sf::Vector2f positionChange = m_velocity * _frameTime.asSeconds();
	m_sprite.setPosition(currentPosition + positionChange);
}

void Player::Draw(sf::RenderTarget& _target)
{
	//draw everything
	_target.draw(m_sprite);
}

void Player::Spawn()
{
	m_sprite.setPosition(STARTX,STARTY);
	m_animation.Play("Jump");
	m_velocity.y = 0;
	m_velocity.x = RUN_SPEED_INITIAL;
}

sf::Vector2f Player::GetPosition()
{
	return m_sprite.getPosition();
}