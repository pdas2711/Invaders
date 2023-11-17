#pragma once
#include <ncurses.h>
#include <string>
#include <cstring>

class Healthboard {
	WINDOW* health_bar;
	public:
		Healthboard() {
		}
		Healthboard(int row, int column, int width) {
			this->width = width;
			height = 1;
			health_bar = newwin(height, width, row, column);
		}
		void initialize(int initial_health) {
			clear();
			mvwprintw(health_bar, 0, 0, "Health: ");
			updateHealth(initial_health);
			refresh();
		}
		void updateHealth(int new_health) {
			health = new_health;
			redraw();
		}
		void redraw() {
			std::string full_health_bar = "Health: ";
			full_health_bar.append(calculateHealthBarString());
			char* health_bar_array = new char[full_health_bar.length() + 1];
			std::strcpy(health_bar_array, full_health_bar.c_str());
			mvwprintw(health_bar, 0, 0, health_bar_array);
		}
		void clear() {
			wclear(health_bar);
		}
		void refresh() {
			clear();
			redraw();
			wrefresh(health_bar);
		}
		int getWidth() {
			return width;
		}
		int getHeight() {
			return height;
		}
		int getHealth() {
			return health;
		}
		void decrementHealth(int amount) {
			updateHealth(health - amount);
		}
	private:
		int width, height, health;
		std::string calculateHealthBarString() {
			std::string health_bar_string = "";
			for (int i = 2; i <= health; i = i + 2)
				health_bar_string.append("O");
			if (health % 2 != 0)
				health_bar_string.append("C");
			return health_bar_string;
		}
};
