#pragma once
#include "drawableset.hpp"

class Projectile : public DrawableSet {
	public:
		Projectile() {
			x = 0;
			y = 0;
			boardHeight = 0;
			icon_set = {
				{'X'}
			};
			hitBoxHeight = icon_set.size();
			hitBoxWidth = icon_set[0].size();
			speed = 0.40;
		}

		Projectile(int x, int y, int boardHeight) {
			this->x = x;
			this->y = y;
			this->boardHeight = boardHeight;
			icon_set = {
				{'X'}
			};
			hitBoxHeight = icon_set.size();
			hitBoxWidth = icon_set[0].size();
			speed = 0.40;
		}	
	private:
		int boardHeight;
		void clockAction() {
			y = y - 1;
		}
};
