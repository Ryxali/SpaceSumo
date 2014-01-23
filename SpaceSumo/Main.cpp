/*
	Home of main() (and only main()!).
*/
#include <ResourceManager\Temp.h>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window.hpp>
#include "SpaceMan.h"
#include <SFML\Audio\Listener.hpp>
#include "Collisions.h"
#include "Debug.h"

int main() {
	// Create a window with resolution 640x360 and set title to "Workshop". Note that this resolution is independent of view-resolution. You can change this and the view will scale up to fit the window. Very handy!
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Test", sf::Style::Fullscreen);
	window.setFramerateLimit(60);
	
	// A view is a simple camera, a "rectangle" which you see through into the world.
	sf::View view;
	view.setSize(1920, 1080);
	SpaceMan player(sf::Keyboard::W, sf::Keyboard::S, sf::Keyboard::D, sf::Keyboard::A);
	SpaceMan player2(sf::Keyboard::Up, sf::Keyboard::Down, sf::Keyboard::Right, sf::Keyboard::Left);
	Collisions collisions(player, player2);
	// An event can be polled against window. If an event occurs, it will be fille with the event data.
	sf::Event evt;
	sf::Listener::setPosition(sf::Vector3f(1000, 500, 0));
	Debug::getS().setRenderTarget(window);
	
	while(window.isOpen())
	{
		// Loop runs through all new events
		while(window.pollEvent(evt))
		{
			// Switch-statements can be used instead of if-statements, good in case we have many eventtypes to handle.
			if(evt.type == sf::Event::Closed)
			{
				window.close();
			}else if(evt.type = sf::Event::KeyPressed) {
				if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
					window.close();
				}
			}
		}
		window.clear();
		player.render(window);
		player2.render(window);
		collisions.testPlayerCollisions();
		// Flip buffers
		window.display();
	}
	return 0;
}