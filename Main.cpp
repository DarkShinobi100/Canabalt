//-----------------------------------------------------------------
//---------------------------=Includes=----------------------------
//----------------------------------------------------------------
//libraries
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>

//project includes
#include "AssetManager.h"
#include "Player.h"
#include "Platform.h"

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

	//seed random number generator
	srand(time(NULL));

	//create player
	Player player;
	player.Spawn();
	
	//create game camera
	sf::View camera = gameWindow.getDefaultView();

	//create platforms
	Platform platform;
	platform.Spawn();

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

		//collision detection
		player.HandleCollision(platform.GetCollider());
		//^ calls the handle collision function for the player


		//update camera position
		camera.setCenter(player.GetPosition().x + camera.getSize().x * 0.4f, camera.getCenter().y);

		//-------------------------------------------------
		//--------------=End Update=-----------------------
		//-------------------------------------------------



		//-------------------------------------------------
		//--------------------=Draw=-----------------------
		//-------------------------------------------------

		//clear the window to a single colour
		gameWindow.clear(sf::Color::Black);

		//draw everything
		
		//draw the game world using the camera 
		gameWindow.setView(camera);
		player.Draw(gameWindow);
		platform.Draw(gameWindow);
		
		//draw UI to the window
		gameWindow.setView(gameWindow.getDefaultView());
		//TODO: UI


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