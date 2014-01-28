/*
	Home of main() (and only main()!).
*/
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window.hpp>
#include "Debug.h"
#include <ResourceManager\Resources.h>
#include <ResourceManager\SSprite.h>
#include <SFML/Graphics.hpp>
int main() {
	// Create a window with resolution 640x360 and set title to "Workshop". Note that this resolution is independent of view-resolution. You can change this and the view will scale up to fit the window. Very handy!
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Test", sf::Style::Fullscreen);
	window.setFramerateLimit(160);
	
	// A view is a simple camera, a "rectangle" which you see through into the world.
	sf::View view;
	view.setSize(1920, 1080);
	// An event can be polled against window. If an event occurs, it will be fille with the event data.
	sf::Event evt;
	Debug::getS().setRenderTarget(window);
	
	res::addResource("Test.png");
	
	
	SSprite test(res::getTexture("Test.png"));
	res::loadResource("Test.png");
	while(window.isOpen())
	{
		// Loop runs through all new events
		while(window.pollEvent(evt))
		{
			// Switch-statements can be used instead of if-statements, good in case we have many eventtypes to handle.
			if(evt.type == sf::Event::Closed)
			{
				window.close();
			}else if(evt.type == sf::Event::KeyPressed) {
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					
					window.close();
				}
			}
		}
		window.clear();
		// Flip buffers
		test.draw(window);
		window.display();
	}
	return 0;
}	 