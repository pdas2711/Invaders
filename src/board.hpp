#pragma once
#include <ncurses.h>
#include <iostream>
#include <vector>
#include "drawableset.hpp"

class Board {
	public:
		Board() {
			construct(0, 0, NULL, 100);
		}

		Board(int width, int height, std::vector<DrawableSet*>* entity_set, int timeout = 10) {
			construct(width, height, entity_set, timeout);
		}

		void initialize() {
			clear();
			refresh();
		}

		void addBorder() {
			box(board_window, 0, 0);
		}

		void drawEntity(DrawableSet* drawable) {
			drawEntity(drawable->getX(), drawable->getY(), drawable->getGraphic());
		}

		void drawEntity(int x, int y, std::vector<std::vector<chtype>> graphic) {
			for (int i = 0; i < graphic.size(); i++)
				for (int j = 0; j < graphic[0].size(); j++)
					mvwaddch(board_window, y + i, x + j, graphic[i][j]);
		}

		chtype getInput() {
			return wgetch(board_window);
		}

		void clear() {
			wclear(board_window);
			addBorder();
		}

		void refresh() {
			clear();
			for (int i = 0; i < entities->size(); i++)
				drawEntity((*entities)[i]);
			wrefresh(board_window);
		}

		int getWidth() {
			return width;
		}

		int getHeight() {
			return height;
		}

		int getStartRow() {
			return start_row;
		}

		int getStartColumn() {
			return start_column;
		}

		void setTimeout(int timeout) {
			wtimeout(board_window, timeout);
		}

	private:
		WINDOW* board_window;
		int width, height, start_row, start_column, timeout;
		std::vector<DrawableSet*>* entities;

		void construct(int width, int height, std::vector<DrawableSet*>* entity_set, int timeout) {
			int xMax, yMax;
			getmaxyx(stdscr, yMax, xMax);

			this->width = width;
			this->height = height;
			this->entities = entity_set;

			start_row = (yMax / 2) - (height / 2);
			start_column = (xMax / 2) - (width / 2);
			board_window = newwin(height, width, start_row, start_column);

			this->timeout = timeout;
			setTimeout(timeout);

			keypad(board_window, true);
		}
};
