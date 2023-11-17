#pragma once
#include "drawableset.hpp"

/* The player icon set design:

   ^   
|--|--|
|     |

*/

class Player : public DrawableSet {
	public:
		Player() {
			this->x = 0;
			this->y = 0;
			this->boardWidth = 0;
			this->icon_set = {
				{' ', ' ', ' ', '^', ' ', ' ', ' '},
				{'|', '-', '-', '|', '-', '-', '|'},
				{'|', ' ', ' ', ' ', ' ', ' ', '|'}
			};
			this->speed = 0;
			hitBoxHeight = icon_set.size();
			hitBoxWidth = icon_set[0].size();
		}

		Player(int x, int y, int boardWidth) {
			this->x = x;
			this->y = y;
			this->boardWidth = boardWidth;
			this->icon_set = {
				{' ', ' ', ' ', '^', ' ', ' ', ' '},
				{'|', '-', '-', '|', '-', '-', '|'},
				{'|', ' ', ' ', ' ', ' ', ' ', '|'}
			};
			this->speed = 0;
			hitBoxHeight = icon_set.size();
			hitBoxWidth = icon_set[0].size();
		}

		void moveLeft() {
			if (x - 1 > 0)
				x = x - 1;
		}

		void moveRight() {
			if (x + 1 + hitBoxWidth < boardWidth)
				x = x + 1;
		}

		int getHitboxWidth() {
			return hitBoxWidth;
		}
	private:
		int boardWidth;
};
