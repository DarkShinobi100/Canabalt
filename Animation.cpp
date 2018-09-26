//project includes
#include "Animation.h"

Animation::Animation()
	: m_frames ()
	, m_sprite (nullptr)
	, m_playbackSpeed(15)
	, m_loop(false)
	, m_playing(false)
	, m_nextFrameChange()
	, m_currentFrame(0)

{

}

void Animation::Update(sf::Time _frameTime)
{
	//Is it time to change to a new frame?
	m_nextFrameChange -= _frameTime;

	if (m_nextFrameChange.asSeconds() <= 0)
	{
		//it's time to change the frame

		//change to the next frame
		++m_currentFrame;

		//Did we reach the end?
		if (m_currentFrame >= m_frames.size())
		{
			//we did reach the end

			//TODO: loop = false?

			//wrap around to the begining
			m_currentFrame = 0;
		}

		//update sprite's texture
		//check if m_sprite isn't = null/zero/nullpointer
		if (m_sprite)
		{
			m_sprite->setTexture(*m_frames[m_currentFrame]);
		}

		//determine time for next frame change
		//convert frames per second to seconds per frame
		float timeToChange = 1.0f / m_playbackSpeed;
		m_nextFrameChange = sf::seconds(timeToChange);
	}
}
void Animation::AddFrame(sf::Texture& _newFrame)
{
	m_frames.push_back(&_newFrame);
}

void Animation::SetSprite(sf::Sprite& _sprite)
{
	m_sprite = &_sprite;
}
