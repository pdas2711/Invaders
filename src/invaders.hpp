#pragma once
#include <ncurses.h>
#include "board.hpp"
#include "scoreboard.hpp"
#include "player.hpp"
#include "entityset.hpp"
#include "projectile.hpp"

class Invaders {
	Board board;
	Scoreboard scoreboard;
	bool game_over;
	int score;
	Player* player;
	EntitySet entity_set;

	public:
		Invaders(int dimension) {
			int height = dimension;
			int width = int(dimension * 2.5);
			board = Board(width, height, entity_set.getAllEntities(), 50);
			int scoreboard_row = board.getStartRow() + height;
			int scoreboard_column = board.getStartColumn();
			scoreboard = Scoreboard(scoreboard_row, scoreboard_column, width);
			initialize(dimension);
		}

		void initialize(int dimension) {
			score = 0;
			board.initialize();
			scoreboard.initialize(score);
			player = new Player(dimension + 6, dimension - 5, board.getWidth());
			entity_set.addEntity(player);
			game_over = false;
		}

		void processInput() {
			chtype input = board.getInput();
			switch (input) {
				case KEY_LEFT:
				case 'a':
					player->moveLeft();
					break;
				case KEY_RIGHT:
				case 'd':
					player->moveRight();
					break;
				case KEY_UP:
				case 'w':
				case ' ': {
					Projectile* player_attack = new Projectile(player->getX() + 3, player->getY() - 1, board.getHeight(), Team::player);
					entity_set.addEntity(player_attack);
				}
					break;
				case 'p':
					while (board.getInput() != 'p');
					break;
			}
		}

		void updateState() {
			std::vector<DrawableSet*>* entities = entity_set.getAllEntities();
			for (int i = 0; i < entity_set.getSize(); i++) {
				(*entities)[i]->incrementClock();
				if (((*entities)[i]->getY() == 0) || ((*entities)[i]->getY() == board.getHeight())) {
					delete (*entities)[i];
					entities->erase(entities->begin() + i);  // The erase() function only accepts an iterator
				}
			}
		}

		void redraw() {
			board.refresh();
			scoreboard.refresh();
		}

		bool isOver() {
			return game_over;
		}

		int getScore() {
			return score;
		}
};
