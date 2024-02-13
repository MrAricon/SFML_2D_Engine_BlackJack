#pragma once

#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

class Game
{
public:
	sf::RenderWindow* window = nullptr;
	sf::VideoMode videoMode;
	sf::Image ico;
	sf::Event ev;

	int cardCount;
	int crupierCardCount = 0;
	int chipCount;
	int chipPos[6];
	int bet;
	int betDis[2];
	int balance;
	int balanceDis[4];
	int crupier;
	int crupierDis[2];
	int player;
	int playerDis[2];
	int chip;
	bool card;
	bool gamePlaying;
	bool gameEnd;
	int playCards[24];

	void initWindow();
	void pollEvents();
	bool mousePos(int x, int y, int with, int height, bool click);
	void startGame();
	void endGame();
	void resetGame();
	int maxCheck(int value);
	void crupierCheck();
	void render();
	void update();
};