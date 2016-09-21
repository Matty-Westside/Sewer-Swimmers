#ifndef LOGIC_H
#define LOGIC_H

#include "collisionManager.h"
#include "enemy.h"
#include "entityContainer.h"
#include "entityList.h"
#include "FileReader.h"
#include "gameEvent.h"
#include "ground.h"
#include "interface.h"
#include "player.h"
#include "timer.h"
#include "rock.h"
#include "tunnelDigger.h"
#include "vector2f.h"
#include <list>
#include <memory>
#include <ctime>
#include <vector>
#include <iostream>

using std::list;
using std::vector;

class Logic
{
public:
	Logic();
	
private:
	void startGame();
	void updateGame(float changeInTime);
	void splashscreen(float time);
	void renderGame();
	void createEnemies();
	void createTunnels();
	void createGround();
	void createRocks();
	void gameInput();
	void collisions();
	void pause();
	void win();
	void lose();
	void endGame();
	vector<int>& updateStats();
	
	Interface _interface;
	EntityContainer _entities;
	FileReader _score_history;
	vector<shared_ptr<MovingEntity>> _moving_entities;
	vector<shared_ptr<ShootingMovingEntity>> _shooting_entities;
	shared_ptr<Player> _player;
	vector<int> _stats;
	vector<Vector2f> _coords;
	
	bool _running = true;
	bool _paused = false;
	bool _splashscreen = true;
	static constexpr const auto _fps = 30.f;
	static constexpr const auto _screen_width = 1000.f;
	static constexpr const auto _screen_height = 800.f;
};

#endif