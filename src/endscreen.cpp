#pragma once
#include <ncurses.h>
#include <string>
#include "board.hpp"

WINDOW* end_screen;

void window_construct(int width, int height) {
	int xMax, yMax;
	getmaxyx(stdscr, yMax, xMax);
	int start_row = (yMax / 2) - (height / 2);
	int start_column = (xMax / 2) - (width / 2);
	end_screen = newwin(height, width, start_row, start_column);
}
void showEndScreen(int dimension, int score) {
	int height = dimension;
	int width = dimension * 2.5;
	window_construct(width, height);
	box(end_screen, 0, 0);
	std::string message = "Game Over!";
	int messagePos = (width - message.length()) / 2;
	char* messageArray = new char[message.length()];
	std::strcpy(messageArray, message.c_str());
	mvwprintw(end_screen, height / 2, messagePos, messageArray);
}
