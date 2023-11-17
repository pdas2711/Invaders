#pragma once
#include <ncurses.h>
#include "board.hpp"
#include "scoreboard.hpp"
#include "healthboard.hpp"
#include "player.hpp"
#include "entityset.hpp"
#include "projectile.hpp"

class Invaders {
	Board board;
	Scoreboard scoreboard;
	Healthboard healthboard;
	bool game_over;
	int score;
	int health;
	Player* player;
	EntitySet entity_set;
	EntitySet all_projectiles;
	EntitySet all_enemies;

	public:
		Invaders(int dimension) {
			int height = dimension;
			int width = int(dimension * 2.5);
			board = Board(width, height, entity_set.getAllEntities(), 50);
			int healthboard_row = board.getStartRow() + height;
			int healthboard_column = board.getStartColumn();
			healthboard = Healthboard(healthboard_row, healthboard_column, width);
			int scoreboard_row = board.getStartRow() + height + healthboard.getHeight();
			int scoreboard_column = board.getStartColumn();
			scoreboard = Scoreboard(scoreboard_row, scoreboard_column, width);
			initialize(dimension);
		}

		void initialize(int dimension) {
			score = 0;
			health = 20;
			board.initialize();
			scoreboard.initialize(score);
			healthboard.initialize(health);
			player = new Player(dimension + 6, dimension - 5, board.getWidth());
			entity_set.addEntity(player);
			game_over = false;
		}

		void processInput() {
			chtype input = board.getInput();
			switch (input) {
				case KEY_LEFT:
				case 'a':
					player->moveLeft();
					break;
				case KEY_RIGHT:
				case 'd':
					player->moveRight();
					break;
				case KEY_UP:
				case 'w':
				case ' ': {
					Projectile* player_attack = new Projectile(player->getX() + 3, player->getY() - 1, board.getHeight(), Identifier::playerId);
					entity_set.addEntity(player_attack);
					all_projectiles.addEntity(player_attack);
				}
					break;
				case 'p':
					while (board.getInput() != 'p');
					break;
			}
		}

		void updateState() {
			if (health <= 0)
				game_over = true;
			spawnEnemy();
			std::vector<DrawableSet*>* entities = entity_set.getAllEntities();
			for (int i = 0; i < entity_set.getSize(); i++) {
				if ((*entities)[i] == nullptr)
					entities->erase(entities->begin() + i);
				(*entities)[i]->incrementClock();
				if (((*entities)[i]->getY() == 0) || ((*entities)[i]->getY() == board.getHeight())) {
					delete (*entities)[i];
					entities->erase(entities->begin() + i);  // The erase() function only accepts an iterator
				}
				if ((*entities)[i]->getIdentity() == projectileId_enemy) {
					int projX = (*entities)[i]->getX();
					int projY = (*entities)[i]->getY();
					if (player->isInHitbox(projX, projY))
						health = health - 1;
				}
				if ((*entities)[i]->getIdentity() == projectileId_player) {
					int projX = (*entities)[i]->getX();
					int projY = (*entities)[i]->getY();
					for (int j = 0; i < entity_set.getSize(); j++)
						if (((*entities)[j]->getIdentity() == enemyId) && ((*entities)[j]->isInHitbox(projX, projY))) {
							delete (*entities)[j];
							entities->erase(entities->begin() + j);
							score = score + 1;
						}
				}
			}
		}

		void redraw() {
			board.refresh();
			scoreboard.refresh();
		}

		bool isOver() {
			return game_over;
		}

		int getScore() {
			return score;
		}
		void spawnEnemy() {
		}
};
