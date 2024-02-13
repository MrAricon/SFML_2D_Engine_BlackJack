#include "../headers/Game.h"
#include "../headers/Display.h"

int main() 
{
	Game game;
	game.initWindow();

	Display interface;
	interface.initDisplay();

	game.balance = 1000;

	while (game.window->isOpen())
	{
		game.update();

		game.window->draw(interface.bckgrn);

		game.betDis[0] = game.bet / 10 % 10;
		game.betDis[1] = game.bet % 10;

		game.window->draw(interface.numArray(sf::Vector2f(268.0f, 332.0f), sf::Vector2f(16, 24), game.betDis, 2), &interface.greenNums);

		game.balanceDis[0] = game.balance / 1000 % 10;
		game.balanceDis[1] = game.balance / 100 % 10;
		game.balanceDis[2] = game.balance / 10 % 10;
		game.balanceDis[3] = game.balance % 10;

		game.window->draw(interface.numArray(sf::Vector2f(132.0f, 380.0f), sf::Vector2f(16, 24), game.balanceDis, 4), &interface.brownNums);

		if (game.cardCount == 1 && game.gameEnd == false)
		{
			game.crupier = game.maxCheck(game.playCards[3]);
		}

		game.crupierDis[0] = game.crupier / 10 % 10;
		game.crupierDis[1] = game.crupier % 10;

		game.window->draw(interface.numArray(sf::Vector2f(346.0f, 140.0f), sf::Vector2f(16, 24), game.crupierDis, 2), &interface.greenNums);

		switch (game.cardCount)
		{
		case 1:
			game.player = game.maxCheck(game.playCards[1]) + game.maxCheck(game.playCards[5]);
			break;
		case 2:
			game.player = game.maxCheck(game.playCards[1]) + game.maxCheck(game.playCards[5]) + game.maxCheck(game.playCards[9]);
			break;
		case 3:
			game.player = game.maxCheck(game.playCards[1]) + game.maxCheck(game.playCards[5]) + game.maxCheck(game.playCards[9]) + game.maxCheck(game.playCards[13]);
			break;
		}

		game.playerDis[0] = game.player / 10 % 10;
		game.playerDis[1] = game.player% 10;

		game.window->draw(interface.numArray(sf::Vector2f(346.0f, 388.0f), sf::Vector2f(16, 24), game.playerDis, 2), &interface.brownNums);

		if (game.player >= 21)
		{
			game.endGame();
		}

		switch (game.chipCount)
		{
		case 0:
			game.window->draw(interface.chipArray(sf::Vector2f(264.0f, 276.0f - game.chipCount * 4), sf::Vector2f(36, 40), game.chipPos[0]), &interface.chips);
			break;
		case 1:
			game.window->draw(interface.chipArray(sf::Vector2f(264.0f, 276.0f - ((game.chipCount * 4) - 4)), sf::Vector2f(36, 40), game.chipPos[0]), &interface.chips);
			game.window->draw(interface.chipArray(sf::Vector2f(264.0f, 276.0f - game.chipCount * 4), sf::Vector2f(36, 40), game.chipPos[1]), &interface.chips);
			break;
		case 2:
			game.window->draw(interface.chipArray(sf::Vector2f(264.0f, 276.0f - ((game.chipCount * 4) -8)), sf::Vector2f(36, 40), game.chipPos[0]), &interface.chips);
			game.window->draw(interface.chipArray(sf::Vector2f(264.0f, 276.0f - ((game.chipCount * 4) - 4)), sf::Vector2f(36, 40), game.chipPos[1]), &interface.chips);
			game.window->draw(interface.chipArray(sf::Vector2f(264.0f, 276.0f - game.chipCount * 4), sf::Vector2f(36, 40), game.chipPos[2]), &interface.chips);
			break;
		case 3:
			game.window->draw(interface.chipArray(sf::Vector2f(264.0f, 276.0f - ((game.chipCount * 4) - 12)), sf::Vector2f(36, 40), game.chipPos[0]), &interface.chips);
			game.window->draw(interface.chipArray(sf::Vector2f(264.0f, 276.0f - ((game.chipCount * 4) - 8)), sf::Vector2f(36, 40), game.chipPos[1]), &interface.chips);
			game.window->draw(interface.chipArray(sf::Vector2f(264.0f, 276.0f - ((game.chipCount * 4) - 4)), sf::Vector2f(36, 40), game.chipPos[2]), &interface.chips);
			game.window->draw(interface.chipArray(sf::Vector2f(264.0f, 276.0f - game.chipCount * 4), sf::Vector2f(36, 40), game.chipPos[3]), &interface.chips);
			break;
		case 4:
			game.window->draw(interface.chipArray(sf::Vector2f(264.0f, 276.0f - ((game.chipCount * 4) - 16)), sf::Vector2f(36, 40), game.chipPos[0]), &interface.chips);
			game.window->draw(interface.chipArray(sf::Vector2f(264.0f, 276.0f - ((game.chipCount * 4) - 12)), sf::Vector2f(36, 40), game.chipPos[1]), &interface.chips);
			game.window->draw(interface.chipArray(sf::Vector2f(264.0f, 276.0f - ((game.chipCount * 4) - 8)), sf::Vector2f(36, 40), game.chipPos[2]), &interface.chips);
			game.window->draw(interface.chipArray(sf::Vector2f(264.0f, 276.0f - ((game.chipCount * 4) - 4)), sf::Vector2f(36, 40), game.chipPos[3]), &interface.chips);
			game.window->draw(interface.chipArray(sf::Vector2f(264.0f, 276.0f - game.chipCount * 4), sf::Vector2f(36, 40), game.chipPos[4]), &interface.chips);
			break;
		case 5:
			game.window->draw(interface.chipArray(sf::Vector2f(264.0f, 276.0f - (((game.chipCount - 1) * 4) - 16)), sf::Vector2f(36, 40), game.chipPos[0]), &interface.chips);
			game.window->draw(interface.chipArray(sf::Vector2f(264.0f, 276.0f - (((game.chipCount - 1) * 4) - 12)), sf::Vector2f(36, 40), game.chipPos[1]), &interface.chips);
			game.window->draw(interface.chipArray(sf::Vector2f(264.0f, 276.0f - (((game.chipCount - 1) * 4) - 8)), sf::Vector2f(36, 40), game.chipPos[2]), &interface.chips);
			game.window->draw(interface.chipArray(sf::Vector2f(264.0f, 276.0f - (((game.chipCount - 1) * 4) - 4)), sf::Vector2f(36, 40), game.chipPos[3]), &interface.chips);
			game.window->draw(interface.chipArray(sf::Vector2f(264.0f, 276.0f - (game.chipCount - 1) * 4), sf::Vector2f(36, 40), game.chipPos[4]), &interface.chips);
			break;
		}

		if (game.gamePlaying == true)
		{
			switch (game.cardCount)
			{
			case 1:
				game.window->draw(interface.cardArray(sf::Vector2f(332.0f, 252.0f), sf::Vector2f(56, 84), game.playCards[0], game.playCards[1]), &interface.cards);
				game.window->draw(interface.cardArray(sf::Vector2f(300.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[2], game.playCards[3]), &interface.cards);
				game.window->draw(interface.cardArray(sf::Vector2f(354.0f, 221.0f), sf::Vector2f(56, 84), game.playCards[4], game.playCards[5]), &interface.cards);
				game.window->draw(interface.cardArray(sf::Vector2f(364.0f, 32.0f), sf::Vector2f(56, 84), 0, 13), &interface.cards);
				if (game.gameEnd == true)
				{
					switch (game.crupierCardCount)
					{
					case 1:
						game.window->draw(interface.cardArray(sf::Vector2f(364.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[7]), &interface.cards);
						break;
					case 2:
						game.window->draw(interface.cardArray(sf::Vector2f(364.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[7]), &interface.cards);
						break;
					case 3:
						game.window->draw(interface.cardArray(sf::Vector2f(428.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[11]), &interface.cards);
						break;
					case 4:
						game.window->draw(interface.cardArray(sf::Vector2f(600.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[15]), &interface.cards);
						game.window->draw(interface.cardArray(sf::Vector2f(428.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[11]), &interface.cards);
						break;
					case 5:
						game.window->draw(interface.cardArray(sf::Vector2f(492.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[15]), &interface.cards);
						game.window->draw(interface.cardArray(sf::Vector2f(428.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[11]), &interface.cards);
						game.window->draw(interface.cardArray(sf::Vector2f(556.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[19]), &interface.cards);
						break;
					case 6:
						game.window->draw(interface.cardArray(sf::Vector2f(600.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[15]), &interface.cards);
						game.window->draw(interface.cardArray(sf::Vector2f(428.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[11]), &interface.cards);
						game.window->draw(interface.cardArray(sf::Vector2f(556.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[19]), &interface.cards);
						game.window->draw(interface.cardArray(sf::Vector2f(620.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[23]), &interface.cards);
						break;
					}

					game.window->draw(interface.cardArray(sf::Vector2f(364.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[7]), &interface.cards);
				}
				break;
			case 2:
				game.window->draw(interface.cardArray(sf::Vector2f(332.0f, 252.0f), sf::Vector2f(56, 84), game.playCards[0], game.playCards[1]), &interface.cards);
				game.window->draw(interface.cardArray(sf::Vector2f(300.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[2], game.playCards[3]), &interface.cards);
				game.window->draw(interface.cardArray(sf::Vector2f(354.0f, 221.0f), sf::Vector2f(56, 84), game.playCards[4], game.playCards[5]), &interface.cards);
				if (game.gameEnd == true)
				{
					switch (game.crupierCardCount)
					{
					case 1:
						game.window->draw(interface.cardArray(sf::Vector2f(364.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[7]), &interface.cards);
						break;
					case 2:
						game.window->draw(interface.cardArray(sf::Vector2f(364.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[7]), &interface.cards);
						break;
					case 3:
						game.window->draw(interface.cardArray(sf::Vector2f(428.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[11]), &interface.cards);
						break;
					case 4:
						game.window->draw(interface.cardArray(sf::Vector2f(600.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[15]), &interface.cards);
						game.window->draw(interface.cardArray(sf::Vector2f(428.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[11]), &interface.cards);
						break;
					case 5:
						game.window->draw(interface.cardArray(sf::Vector2f(492.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[15]), &interface.cards);
						game.window->draw(interface.cardArray(sf::Vector2f(428.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[11]), &interface.cards);
						game.window->draw(interface.cardArray(sf::Vector2f(556.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[19]), &interface.cards);
						break;
					case 6:
						game.window->draw(interface.cardArray(sf::Vector2f(600.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[15]), &interface.cards);
						game.window->draw(interface.cardArray(sf::Vector2f(428.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[11]), &interface.cards);
						game.window->draw(interface.cardArray(sf::Vector2f(556.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[19]), &interface.cards);
						game.window->draw(interface.cardArray(sf::Vector2f(620.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[23]), &interface.cards);
						break;
					}

					game.window->draw(interface.cardArray(sf::Vector2f(364.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[7]), &interface.cards);
				}
				else
				{
					game.window->draw(interface.cardArray(sf::Vector2f(364.0f, 32.0f), sf::Vector2f(56, 84), 0, 13), &interface.cards);

				}
				game.window->draw(interface.cardArray(sf::Vector2f(376.0f, 190.f), sf::Vector2f(56, 84), game.playCards[8], game.playCards[9]), &interface.cards);
				break;
			case 3:
				game.window->draw(interface.cardArray(sf::Vector2f(332.0f, 252.0f), sf::Vector2f(56, 84), game.playCards[0], game.playCards[1]), &interface.cards);
				game.window->draw(interface.cardArray(sf::Vector2f(300.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[2], game.playCards[3]), &interface.cards);
				game.window->draw(interface.cardArray(sf::Vector2f(354.0f, 221.0f), sf::Vector2f(56, 84), game.playCards[4], game.playCards[5]), &interface.cards);
				if (game.gameEnd == true)
				{
					switch (game.crupierCardCount)
					{
					case 1:
						game.window->draw(interface.cardArray(sf::Vector2f(364.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[7]), &interface.cards);
						break;
					case 2:
						game.window->draw(interface.cardArray(sf::Vector2f(364.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[7]), &interface.cards);
						break;
					case 3:
						game.window->draw(interface.cardArray(sf::Vector2f(428.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[11]), &interface.cards);
						break;
					case 4:
						game.window->draw(interface.cardArray(sf::Vector2f(600.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[15]), &interface.cards);
						game.window->draw(interface.cardArray(sf::Vector2f(428.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[11]), &interface.cards);
						break;
					case 5:
						game.window->draw(interface.cardArray(sf::Vector2f(492.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[15]), &interface.cards);
						game.window->draw(interface.cardArray(sf::Vector2f(428.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[11]), &interface.cards);
						game.window->draw(interface.cardArray(sf::Vector2f(556.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[19]), &interface.cards);
						break;
					case 6:
						game.window->draw(interface.cardArray(sf::Vector2f(600.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[15]), &interface.cards);
						game.window->draw(interface.cardArray(sf::Vector2f(428.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[11]), &interface.cards);
						game.window->draw(interface.cardArray(sf::Vector2f(556.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[19]), &interface.cards);
						game.window->draw(interface.cardArray(sf::Vector2f(620.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[23]), &interface.cards);
						break;
					}
					game.window->draw(interface.cardArray(sf::Vector2f(364.0f, 32.0f), sf::Vector2f(56, 84), game.playCards[6], game.playCards[7]), &interface.cards);
				}
				else
				{
					game.window->draw(interface.cardArray(sf::Vector2f(364.0f, 32.0f), sf::Vector2f(56, 84), 0, 13), &interface.cards);

				}
				game.window->draw(interface.cardArray(sf::Vector2f(376.0f, 190.f), sf::Vector2f(56, 84), game.playCards[8], game.playCards[9]), &interface.cards);
				game.window->draw(interface.cardArray(sf::Vector2f(398.0f, 159.f), sf::Vector2f(56, 84), game.playCards[10], game.playCards[11]), &interface.cards);
				break;
			}
		}

		game.window->draw(interface.cardArray(sf::Vector2f(632.0f, 32.0f), sf::Vector2f(56, 84), 0, 13), &interface.cards);

		game.window->display();

		game.render();
	}

	return 0;
}