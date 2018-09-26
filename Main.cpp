//-----------------------------------------------------------------
//---------------------------=Includes=----------------------------
//----------------------------------------------------------------
//libraries
#include <SFML/Graphics.hpp>

//project includes
#include "AssetManager.h"
#include "Animation.h"

int main()
{
	//-------------------------------------------------------------
	//---------------------=Game setup=----------------------------
	//--------------------------------------------------------------


	//Rendom Window creation
	sf::RenderWindow gameWindow; //Makes a variable called gameWindow of the type renderwindow
	gameWindow.create(sf::VideoMode::getDesktopMode(), "Canabalt!",
		sf::Style::Titlebar | sf::Style::Close);
	
	//Timer functionality
	sf::Clock gameClock; //game clock

	//create AssetManager
	AssetManager assets;

	//testing AssetManager
	//test sprite
		sf::Sprite testsprite;
		testsprite.setTexture(AssetManager::GetTexture("graphics/playerjump.png"));
		testsprite.setPosition(gameWindow.getSize().x / 2 ,gameWindow.getSize().y / 2);
		testsprite.setScale(3, 3);

	//test music
		sf::Sound testmusic;
		testmusic.setBuffer(AssetManager::GetSoundBuffer("audio/Persona5OST.ogg"));
		testmusic.play();
		testmusic.setLoop(true);
	
	//test font

		//create Title
		sf::Text testText;
		testText.setFont(AssetManager::GetFont("fonts/mainFont.ttf"));
		testText.setString("Canabalt Persona 5 style");
		testText.setCharacterSize(100);
		testText.setFillColor(sf::Color::Red);
		testText.setStyle(sf::Text::Bold | sf::Text::Italic);
		testText.setPosition(gameWindow.getSize().x / 2 - testText.getLocalBounds().width / 2, 30);

	//test animation
		Animation testAnimation;
		testAnimation.SetSprite(testsprite);
		testAnimation.AddFrame(AssetManager::GetTexture("graphics/playerRun1.png"));
		testAnimation.AddFrame(AssetManager::GetTexture("graphics/playerRun2.png"));
		testAnimation.Play();
		testAnimation.SetLoop(true);

	//----------------------------------------------------
	//---------------=End game setup=---------------------
	//----------------------------------------------------


	//----------------------------------------------
	//----------------=Game loop=-------------------
	//----------------------------------------------
	//Runs every frame untile the game is closed
	while (gameWindow.isOpen()) // while continues to loop while the (condition) is true
	{

		//------------------------------------------------
		//------------------=Input=-----------------------
		//------------------------------------------------

		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				gameWindow.close();
		}//end while(event polling loop)


		//-------------------------------------------------
		//-------------=End Input=-------------------------
		//-------------------------------------------------


		//-------------------------------------------------
		//---------------------=Update=--------------------
		//-------------------------------------------------

		//update time
		sf::Time frameTime = gameClock.restart();

		//update Animation
		testAnimation.Update(frameTime);

		//-------------------------------------------------
		//--------------=End Update=-----------------------
		//-------------------------------------------------



		//-------------------------------------------------
		//--------------------=Draw=-----------------------
		//-------------------------------------------------

		//clear the window to a single colour
		gameWindow.clear(sf::Color::Black);

		//draw everything
		gameWindow.draw(testsprite);
		gameWindow.draw(testText);

		//display the window contents to the screen
		gameWindow.display();

		//--------------------------------------------------
		//--------------=End draw=--------------------------
		//--------------------------------------------------

	}//end of game while loop

	//------------------------------------------------------
	//----------------=end game loop=-----------------------
	//------------------------------------------------------

	//exit point for the program
	return 0;

} //end of the main() function