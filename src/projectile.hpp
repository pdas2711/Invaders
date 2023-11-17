#pragma once
#include "drawableset.hpp"

class Projectile : public DrawableSet {
	public:
		Projectile() {
			this->x = 0;
			this->y = 0;
			this->boardWidth = 0;
			this->icon_set = {
				{'X'}
			};
			hitBoxHeight = icon_set.size();
			hitBoxWidth = icon_set[0].size();
		}

		Projectile(int x, int y, int boardHeight) {
			this->x = x;
			this->y = y;
			this->boardHeight = boardHeight;
			this->icon_set = {
				{'X'}
			};
			hitBoxHeight = icon_set.size();
			hitBoxWidth = icon_set[0].size();
		}
	private:
		int boardHeight;
};
