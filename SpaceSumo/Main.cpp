/*
	Home of main() (and only main()!).
*/
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window.hpp>
#include "Debug.h"
#include <ResourceManager\RHandle.h>
#include <ResourceManager\SSprite.h>
#include <ResourceManager\SSound.h>
#include <SFML/Graphics.hpp>
#include <Common/mathH.h>
#include <Common\stringH.h>
#include <Common\error.h>
#include <Common/Config.h>

int main() {
	Config config("config.cfg", true);

	// Create a window with resolution 640x360 and set title to "Workshop". Note that this resolution is independent of view-resolution. You can change this and the view will scale up to fit the window. Very handy!
	sf::RenderWindow window(sf::VideoMode(config.getValue<int>("screenWidth"), config.getValue<int>("screenHeight")), "Test", config.getValue<int>("fullscreen"));
	window.setFramerateLimit(160);

	// A view is a simple camera, a "rectangle" which you see through into the world.
	sf::View view;
	view.setSize(config.getValue<float>("screenWidth"), config.getValue<float>("screenHeight"));
	// An event can be polled against window. If an event occurs, it will be fille with the event data.
	sf::Event evt;
	Debug::getS().setRenderTarget(window);

	/* Don't have test files, OBS! More commented out at the bottom
	res::addResource("Test.png");
	res::addResource("TestSound.ogg");
	
	SSprite test(res::getTexture("Test.png"));
	res::loadResource("Test.png");
	SSound testS(res::getSoundBuffer("TestSound.ogg"));
	res::loadResource("TestSound.ogg");
	testS.play();*/
	while(window.isOpen())
	{
		// Loop runs through all new events
		while(window.pollEvent(evt))
		{
			// Switch-statements can be used instead of if-statements, good in case we have many eventtypes to handle.
			if(evt.type == sf::Event::Closed)
			{
				window.close();
			}
			else if(evt.type == sf::Event::KeyPressed) 
			{
				if(evt.key.code == sf::Keyboard::Escape) 
				{
					config.saveConfigChange();
					window.close();
				}
			}
		}
		window.clear();
		// Flip buffers
		//test.draw(window);		*Don't have test files*
		window.display();
	}
	return 0;
}	 
