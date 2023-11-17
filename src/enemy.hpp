#pragma once
#include "drawableset.hpp"

/* Enemy icon set design:

|-|-|
  V
 
*/

class Enemy : public DrawableSet {
	public:
		Enemy() {
			x = y = boardWidth = 0;
			icon_set = {
				{'|', '-', '|', '-', '|'},
				{' ', ' ', 'V', ' ', ' '}
			};
			hitBoxHeight = icon_set.size();
			hitBoxWidth = icon_set[0].size();
			speed = 0.05;
			identity = enemyId;
		}
		Enemy(int x, int y, int boardWidth) {
			this->x = x;
			this->y = y;
			this->boardWidth = boardWidth;
			icon_set = {
				{'|', '-', '|', '-', '|'},
				{' ', ' ', 'V', ' ', ' '}
			};
			hitBoxHeight = icon_set.size();
			hitBoxWidth = icon_set[0].size();
			speed = 0.05;
			identity = enemyId;
		}
	private:
		int boardWidth;
		void clockAction() {
			y = y + 1;
		}
};
