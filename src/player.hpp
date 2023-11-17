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
			x = 0;
			y = 0;
			boardWidth = 0;
			icon_set = {
				{' ', ' ', ' ', '^', ' ', ' ', ' '},
				{'|', '-', '-', '|', '-', '-', '|'},
				{'|', ' ', ' ', ' ', ' ', ' ', '|'}
			};
			hitBoxHeight = icon_set.size();
			hitBoxWidth = icon_set[0].size();
			speed = 0.0;
			identity = playerId;
		}

		Player(int x, int y, int boardWidth) {
			this->x = x;
			this->y = y;
			this->boardWidth = boardWidth;
			icon_set = {
				{' ', ' ', ' ', '^', ' ', ' ', ' '},
				{'|', '-', '-', '|', '-', '-', '|'},
				{'|', ' ', ' ', ' ', ' ', ' ', '|'}
			};
			hitBoxHeight = icon_set.size();
			hitBoxWidth = icon_set[0].size();
			speed = 0.0;
			identity = playerId;
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
		void clockAction() {}
};
