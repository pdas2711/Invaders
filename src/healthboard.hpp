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
			std::string full_health_bar = "Health: ";
			full_health_bar.append(calculateHealthBarString(new_health));
			char* health_bar_array = new char[full_health_bar.length() + 1];
			std::strcpy(health_bar_array, full_health_bar.c_str());
			mvwprintw(health_bar, 0, 0, health_bar_array);
		}
		void clear() {
			wclear(health_bar);
		}
		void refresh() {
			wrefresh(health_bar);
		}
		int getWidth() {
			return width;
		}
		int getHeight() {
			return height;
		}
	private:
		int width, height;
		std::string calculateHealthBarString(int health) {
			std::string health_bar_string = "";
			for (int i = 0; i < health; i = i + 2)
				health_bar_string.append("O");
			if (health % 2 != 0)
				health_bar_string.append("C");
			return health_bar_string;
		}
};
