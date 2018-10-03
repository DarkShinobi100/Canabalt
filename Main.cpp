//-----------------------------------------------------------------
//---------------------------=Includes=----------------------------
//----------------------------------------------------------------
//libraries
#include <SFML/Graphics.hpp>

//project includes
#include "AssetManager.h"
#include "Player.h"

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

	//create player
	Player player;
	player.Spawn();

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
			//pass input to game objects
			player.Input(event);


			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();
			}
		}//end while(event polling loop)


		//-------------------------------------------------
		//-------------=End Input=-------------------------
		//-------------------------------------------------


		//-------------------------------------------------
		//---------------------=Update=--------------------
		//-------------------------------------------------

		//update time
		sf::Time frameTime = gameClock.restart();

		//process all game objects
		player.Update(frameTime);

		//-------------------------------------------------
		//--------------=End Update=-----------------------
		//-------------------------------------------------



		//-------------------------------------------------
		//--------------------=Draw=-----------------------
		//-------------------------------------------------

		//clear the window to a single colour
		gameWindow.clear(sf::Color::Black);

		//draw everything
		player.Draw(gameWindow);

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