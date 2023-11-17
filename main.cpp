#include <ncurses.h>
#include <iostream>
#include "src/invaders.hpp"

const int BOARD_DIM = 30;

int main() {
	if (BOARD_DIM * 2.5 < 18) {
		std::cout << "Board dimension is too small. Please make it larger." << std::endl;
		return 1;
	}
	initscr();
	refresh();
	noecho();
	curs_set(0);

	// Create board
	Invaders game(BOARD_DIM);
	
	// Create Game Loop
	while (!game.isOver()) {
		game.processInput();
		game.updateState();
		game.redraw();
	}
	
	endwin();
	return 0;
}
