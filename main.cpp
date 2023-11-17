#include <ncurses.h>
#include "src/invaders.hpp"

const int BOARD_DIM = 35;

int main() {
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
