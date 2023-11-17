#pragma once
#include <ncurses.h>

class Scoreboard {
	WINDOW* score_window;
	public:
		Scoreboard() {
		}

		Scoreboard(int row, int column, int width) {
			this->width = width;
			height = 1;
			score_window = newwin(1, width, row, column);
		}

		void initialize(int initial_score) {
			clear();
			mvwprintw(score_window, 0, 0, "Score:");
			updateScore(initial_score);
			refresh();
		}

		void updateScore(int score) {
			mvwprintw(score_window, 0, score_window -> _maxx - 10, "%11llu", score);
		}

		void clear() {
			wclear(score_window);
		}

		void refresh() {
			wrefresh(score_window);
		}
		int getWidth() {
			return width;
		}
		int getHeight() {
			return height;
		}
	private:
		int width, height;
};
