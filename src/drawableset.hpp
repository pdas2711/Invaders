#pragma once
#include <vector>
#include <ncurses.h>

class DrawableSet {
	public:
		DrawableSet() {
			x = y = speed = 0;
			icon_set.push_back({{' '}});
			hitBoxWidth = hitBoxHeight = 0;
		}

		DrawableSet(int x, int y, int speed, std::vector<std::vector<chtype>> icon_set) {
			this->x = x;
			this->y = y;
			this->speed = speed;
			this->icon_set = icon_set;
			hitBoxHeight = icon_set.size();
			hitBoxWidth = icon_set[0].size();
		}

		int getX() {
			return x;
		}

		int getY() {
			return y;
		}

		int getSpeed() {
			return speed;
		}

		std::vector<std::vector<chtype>> getGraphic() {
			return icon_set;
		}

		bool isInHitbox(int x, int y) {
			if ((x >= this->x && x <= this->x + hitBoxWidth) && (y >= this->y && y <= this->y + hitBoxHeight))
				return true;
			else
				return false;
		}

		// These 2 methods allow setting a counter for these individual entities
		int getClock() {
			return clock;
		}

		int incrementClock() {
			if ((speed != 0) && (clock++ < (1 / speed)))
				clock += 1;
			else if (speed == 0)
				clock = 0;
			else
				clock = 0;
			return clock;
		}

	protected:
		int x, y;
		int speed;  // 0 to 1
		std::vector<std::vector<chtype>> icon_set;
		int hitBoxWidth, hitBoxHeight;
	private:
		int clock = 0;
};
