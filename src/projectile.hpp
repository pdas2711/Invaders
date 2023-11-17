#pragma once
#include "drawableset.hpp"

enum Team {
	player,
	enemy
};

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

		Projectile(int x, int y, int boardHeight, Team team) {
			this->x = x;
			this->y = y;
			this->boardHeight = boardHeight;
			this->team = team;
			icon_set = {
				{'X'}
			};
			hitBoxHeight = icon_set.size();
			hitBoxWidth = icon_set[0].size();
			speed = 0.40;
		}
		Team getTeam() {
			return team;
		}
	private:
		Team team;
		int boardHeight;
		void clockAction() {
			if (team == player)
				y -= 1;
			else if (team == enemy)
				y += 1;
		}
};
