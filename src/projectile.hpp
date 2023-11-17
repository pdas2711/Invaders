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
			speed = 0.90;
		}

		Projectile(int x, int y, int boardHeight, Identifier identity) {
			this->x = x;
			this->y = y;
			this->boardHeight = boardHeight;
			icon_set = {
				{'X'}
			};
			hitBoxHeight = icon_set.size();
			hitBoxWidth = icon_set[0].size();
			speed = 0.90;
			this->identity = identity;
		}
	private:
		int boardHeight;
		void clockAction() {
			if (identity == projectileId_player)
				y -= 1;
			else if (identity == projectileId_enemy)
				y += 1;
		}
};
