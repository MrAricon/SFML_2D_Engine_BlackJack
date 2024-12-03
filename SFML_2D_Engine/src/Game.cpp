#include "../headers/Game.h"

void Game::initWindow()
{
	videoMode.width = 720;
	videoMode.height = 480;
	window = new sf::RenderWindow(videoMode, "Simple Black Jack", sf::Style::Titlebar | sf::Style::Close);
	window->setPosition(sf::Vector2i(250, 100));
	window->setFramerateLimit(60);
	//window->setPosition(sf::Vector2i(100, -1000));
	ico.loadFromFile("assets/ico.png");
	window->setIcon(ico.getSize().x, ico.getSize().y, ico.getPixelsPtr());
	bet = 0;
	chipCount = -1;
	gamePlaying = false;
	gameEnd = false;
	crupierCardCount = 1;
}

void Game::pollEvents()
{
	while (window->pollEvent(ev))
	{
		switch (ev.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
				window->close();
			break;
		case sf::Event::MouseButtonReleased:
			sf::Vector2i winPos = window->getPosition();
			sf::Vector2i mousePosition = sf::Mouse::getPosition();
			std::cout << mousePosition.x - winPos.x - 9 << " " << mousePosition.y - winPos.y - 31 << "\n";
			if (gamePlaying == true)
			{
				if (mousePos(308, 388, 20, 20, true) == true)
				{
					endGame();
				}
				if (mousePos(392, 388, 20, 20, true) == true && gameEnd == false)
				{
					if (cardCount < 3)
					{
						cardCount++;
						std::cout << cardCount << "\n";
						std::cout << gameEnd << "\n";

					}
				}
			}
			if (gameEnd == true)
			{
				if (mousePos(216, 416, 48, 48, true) == true)
				{
					bet = 0;
					chip = 0;
					chipCount = -1;
					resetGame();
				}
			}
			if (gamePlaying == false)
			{
				if (mousePos(20, 416, 44, 44, true) == true)
				{
					chip = 1;
					chipCount++;
					if (chipCount > 5)
					{
						chipCount = 5;
					}
					if (chipCount <= 4)
					{
						bet += 5;
						chipPos[chipCount] = 0;
					}
				}
				if (mousePos(92, 416, 44, 44, true) == true)
				{
					chip = 2;
					chipCount++;
					if (chipCount > 5)
					{
						chipCount = 5;
					}
					if (chipCount <= 4)
					{
						bet += 10;
						chipPos[chipCount] = 1;
					}
				}
				if (mousePos(160, 416, 44, 44, true) == true)
				{
					chip = 3;
					chipCount++;
					if (chipCount > 5)
					{
						chipCount = 5;
					}
					if (chipCount <= 4)
					{
						bet += 15;
						chipPos[chipCount] = 2;
					}
				}
				if (mousePos(216, 416, 48, 48, true) == true)
				{
					bet = 0;
					chip = 0;
					chipCount = -1;
				}
				if (mousePos(324, 424, 72, 48, true) == true)
				{
					if (bet > 0)
					{
						gamePlaying = true;
						cardCount = 1;
						startGame();
					}
				}
			}
		}
	}
}

bool Game::mousePos(int x, int y, int with, int height, bool click)
{
	sf::Vector2i winPos = window->getPosition();
	sf::Vector2i mousePos = sf::Mouse::getPosition();
	int mouseX = mousePos.x - winPos.x - 9;
	int mouseY = mousePos.y - winPos.y - 31;
	if (click == true)
	{
		if (x < mouseX && x + with > mouseX && y < mouseY && y + height > mouseY) {
			switch (ev.type)
			{
			case sf::Event::MouseButtonReleased:
				return true;
			}
		}
		else {
			return false;
		}
	} 
	else
	{
		if (x < mouseX && x + with > mouseX && y < mouseY && y + height > mouseY) {
			return true;
		}
		else {
			return false;
		}
	}
}

void Game::startGame()
{
	if (gamePlaying == true)
	{
		balance -= bet;

		srand(time(NULL));

		playCards[0] = rand() % 4;
		playCards[1] = rand() % 13;
		playCards[2] = rand() % 4;
		playCards[3] = rand() % 13;
		playCards[4] = rand() % 4;
		playCards[5] = rand() % 13;
		playCards[6] = rand() % 4;
		playCards[7] = rand() % 13;
		playCards[8] = rand() % 4;
		playCards[9] = rand() % 13;
		playCards[10] = rand() % 4;
		playCards[11] = rand() % 13;
		playCards[12] = rand() % 4;
		playCards[13] = rand() % 13;
		playCards[14] = rand() % 4;
		playCards[15] = rand() % 13;
		playCards[16] = rand() % 4;
		playCards[17] = rand() % 13;
		playCards[18] = rand() % 4;
		playCards[19] = rand() % 13;
		playCards[20] = rand() % 4;
		playCards[21] = rand() % 13;
		playCards[22] = rand() % 4;
		playCards[23] = rand() % 13;
	}
}

void Game::endGame()
{
	gameEnd = true;

	chipCount = -1;

	crupierCheck();

	if (player > 21) {
		bet = 0;
	}
	else if (crupier > 21) {
		balance += bet * 2;
		bet = 0;
	}
	else if (player == crupier) {
		balance += bet;
		bet = 0;
	}
	else if (player > crupier) {
		balance += bet * 2;
		bet = 0;
	}
	else {
		bet = 0;
	}
}

void Game::resetGame()
{
	gamePlaying = false;
	gameEnd = false;

	crupier = 0;
	player = 0;
	cardCount = 0;
	crupierCardCount = 0;

	playCards[0] = NULL;
	playCards[1] = NULL;
	playCards[2] = NULL;
	playCards[3] = NULL;
	playCards[4] = NULL;
	playCards[5] = NULL;
	playCards[6] = NULL;
	playCards[7] = NULL;
	playCards[8] = NULL;
	playCards[9] = NULL;
	playCards[10] = NULL;
	playCards[11] = NULL;
	playCards[12] = NULL;
	playCards[13] = NULL;
	playCards[14] = NULL;
	playCards[15] = NULL;

	chipPos[0] = NULL;
	chipPos[1] = NULL;
	chipPos[2] = NULL;
	chipPos[3] = NULL;
	chipPos[4] = NULL;
	chipPos[5] = NULL;
}

int Game::maxCheck(int value)
{
	if (value >= 10)
	{
		return 10;
	}
	else
	{
		return value + 1;
	}
}

void Game::crupierCheck()
{
	while (crupier <= 16 || crupierCardCount >= 6)
	{
		crupierCardCount++;
		switch (crupierCardCount)
		{
		case 1:
			crupier = maxCheck(playCards[3]) + maxCheck(playCards[7]);
			break;
		case 2:
			crupier = maxCheck(playCards[3]) + maxCheck(playCards[7]);
			break;
		case 3:
			crupier = maxCheck(playCards[3]) + maxCheck(playCards[7]) + maxCheck(playCards[11]);
			break;
		case 4:
			crupier = maxCheck(playCards[3]) + maxCheck(playCards[7]) + maxCheck(playCards[11]) + maxCheck(playCards[15]);
			break;
		case 5:
			crupier = maxCheck(playCards[3]) + maxCheck(playCards[7]) + maxCheck(playCards[11]) + maxCheck(playCards[15]) + maxCheck(playCards[19]);
			break;
		case 6:
			crupier = maxCheck(playCards[3]) + maxCheck(playCards[7]) + maxCheck(playCards[11]) + maxCheck(playCards[15]) + maxCheck(playCards[19]) + maxCheck(playCards[23]);
			break;
		}
	}
}

void Game::render()
{
	window->clear();
}

void Game::update()
{
	pollEvents();
}
