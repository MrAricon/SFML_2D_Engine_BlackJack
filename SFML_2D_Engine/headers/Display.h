#pragma once

class Display
{
public:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::RectangleShape bckgrn;

	sf::RectangleShape rect;
	sf::Texture rTexture;
	sf::Texture cards;
	sf::Texture chips;
	sf::Texture greenNums;
	sf::Texture brownNums;

	void initDisplay();
	sf::VertexArray cardArray(sf::Vector2f position, sf::Vector2f size, int suit, int number);
	sf::VertexArray chipArray(sf::Vector2f position, sf::Vector2f size, int chip);
	sf::VertexArray numArray(sf::Vector2f position, sf::Vector2f size, int number[], int digits);
};