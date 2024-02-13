#include "../headers/Game.h"
#include "../headers/Display.h"

void Display::initDisplay()
{
	texture.loadFromFile("assets/background3.png");
	bckgrn.setSize(sf::Vector2f(720.f, 480.f));
	bckgrn.setTexture(&texture);
	cards.loadFromFile("assets/cards.png");
	chips.loadFromFile("assets/chips.png");
	greenNums.loadFromFile("assets/green-nums.png");
	brownNums.loadFromFile("assets/brown-nums.png");
}

sf::VertexArray Display::cardArray(sf::Vector2f position, sf::Vector2f size, int suit, int number)
{
	sf::VertexArray triangleStrip(sf::Quads, 4);

	triangleStrip[0].position = position;
	triangleStrip[1].position = sf::Vector2f(position.x + size.x, position.y);
	triangleStrip[2].position = sf::Vector2f(position.x + size.x, position.y + size.y);
	triangleStrip[3].position = sf::Vector2f(position.x, position.y + size.y);

	triangleStrip[0].texCoords = sf::Vector2f((0 + number) * 19, (0 + suit) * 28);
	triangleStrip[1].texCoords = sf::Vector2f(19 * number + 19, (0 + suit) * 28);
	triangleStrip[2].texCoords = sf::Vector2f(19 * number + 19, 28 * suit + 28);
	triangleStrip[3].texCoords = sf::Vector2f((0 + number) * 19, 28 * suit + 28);

	return triangleStrip;
}

sf::VertexArray Display::chipArray(sf::Vector2f position, sf::Vector2f size, int chip)
{
	sf::VertexArray triangleStrip(sf::Quads, 4);

	triangleStrip[0].position = position;
	triangleStrip[1].position = sf::Vector2f(position.x + size.x, position.y);
	triangleStrip[2].position = sf::Vector2f(position.x + size.x, position.y + size.y);
	triangleStrip[3].position = sf::Vector2f(position.x, position.y + size.y);

	triangleStrip[0].texCoords = sf::Vector2f(chip * 9, 0);
	triangleStrip[1].texCoords = sf::Vector2f((chip * 9) + 9, 0);
	triangleStrip[2].texCoords = sf::Vector2f((chip * 9) + 9, 10);
	triangleStrip[3].texCoords = sf::Vector2f(chip * 9, 10);

	return triangleStrip;
}

sf::VertexArray Display::numArray(sf::Vector2f position, sf::Vector2f size, int number[], int digits)
{
	sf::VertexArray triangleStrip(sf::Quads, 4 * digits);

	triangleStrip[0].position = position;
	triangleStrip[1].position = sf::Vector2f(position.x + size.x, position.y);
	triangleStrip[2].position = sf::Vector2f(position.x + size.x, position.y + size.y);
	triangleStrip[3].position = sf::Vector2f(position.x, position.y + size.y);

	if (digits >= 2)
	{
		triangleStrip[4].position = sf::Vector2f(position.x + 16.0f, position.y);
		triangleStrip[5].position = sf::Vector2f(position.x + size.x + 16.0f, position.y);
		triangleStrip[6].position = sf::Vector2f(position.x + size.x + 16.0f, position.y + size.y);
		triangleStrip[7].position = sf::Vector2f(position.x + 16.0f, position.y + size.y);
	}

	if (digits >= 3)
	{
		triangleStrip[8].position = sf::Vector2f(position.x + 32.0f, position.y);
		triangleStrip[9].position = sf::Vector2f(position.x + size.x + 32.0f, position.y);
		triangleStrip[10].position = sf::Vector2f(position.x + size.x + 32.0f, position.y + size.y);
		triangleStrip[11].position = sf::Vector2f(position.x + 32.0f, position.y + size.y);
	}

	if (digits >= 4)
	{
		triangleStrip[12].position = sf::Vector2f(position.x + 48.0f, position.y);
		triangleStrip[13].position = sf::Vector2f(position.x + size.x + 48.0f, position.y);
		triangleStrip[14].position = sf::Vector2f(position.x + size.x + 48.0f, position.y + size.y);
		triangleStrip[15].position = sf::Vector2f(position.x + 48.0f, position.y + size.y);
	}

	triangleStrip[0].texCoords = sf::Vector2f(number[0] * 4, 0);
	triangleStrip[1].texCoords = sf::Vector2f(number[0] * 4 + 4, 0);
	triangleStrip[2].texCoords = sf::Vector2f(number[0] * 4 + 4, 6);
	triangleStrip[3].texCoords = sf::Vector2f(number[0] * 4, 6);

	if (digits >= 2)
	{
		triangleStrip[4].texCoords = sf::Vector2f(number[1] * 4, 0);
		triangleStrip[5].texCoords = sf::Vector2f(number[1] * 4 + 4, 0);
		triangleStrip[6].texCoords = sf::Vector2f(number[1] * 4 + 4, 6);
		triangleStrip[7].texCoords = sf::Vector2f(number[1] * 4, 6);
	}

	if (digits >= 3)
	{
		triangleStrip[8].texCoords = sf::Vector2f(number[2] * 4, 0);
		triangleStrip[9].texCoords = sf::Vector2f(number[2] * 4 + 4, 0);
		triangleStrip[10].texCoords = sf::Vector2f(number[2] * 4 + 4, 6);
		triangleStrip[11].texCoords = sf::Vector2f(number[2] * 4, 6);
	}

	if (digits >= 4)
	{
		triangleStrip[12].texCoords = sf::Vector2f(number[3] * 4, 0);
		triangleStrip[13].texCoords = sf::Vector2f(number[3] * 4 + 4, 0);
		triangleStrip[14].texCoords = sf::Vector2f(number[3] * 4 + 4, 6);
		triangleStrip[15].texCoords = sf::Vector2f(number[3] * 4, 6);
	}

	return triangleStrip;
}