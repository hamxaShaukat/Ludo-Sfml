#include "Global.h"
#include"SFML/Graphics.hpp"
 


sf::Vector2f Global::dimSqr = sf::Vector2f(0, 0);
sf::Texture* Global::Ts =nullptr;
sf::Font Global::f;

void Global::getRowColbyLeftClick(float& rpos, float& cpos, sf::RenderWindow& window)
{
	sf::Event event;
	while (window.waitEvent(event))
	{
		if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
			sf::Vector2f p = sf::Vector2f(sf::Mouse::getPosition(window));
			rpos = p.y;
			cpos = p.x;
			rpos = rpos / Global::dimSqr.y;
			cpos = cpos / Global::dimSqr.x;
			break;
		}
	}
}