#pragma once
#include <ncurses.h>
#include "board.hpp"
#include "scoreboard.hpp"
#include "player.hpp"

class Invaders {
	Board board;
	Scoreboard scoreboard;
	bool game_over;
	int score;
	Player* player;

	public:
		Invaders(int dimension) {
			int height = dimension;
			int width = int(dimension * 2.5);
			board = Board(width, height, 50);
			int scoreboard_row = board.getStartRow() + height;
			int scoreboard_column = board.getStartColumn();
			scoreboard = Scoreboard(scoreboard_row, scoreboard_column, width);
			initialize(dimension);
		}

		void initialize(int dimension) {
			board.initialize();
			scoreboard.initialize(score);
			score = 0;
			player = new Player(dimension + 6, dimension - 5, board.getWidth());
			board.addEntity(player);
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
				case 'p':
					while (board.getInput() != 'p');
					break;
			}
		}

		void updateState() {
			// Spawn enemies
			// Update enemy movements
			// Update projectile movements
			// Need board.getEntity()
			std::vector<DrawableSet*> current_entities = board.getEntities();
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
