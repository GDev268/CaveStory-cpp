#include <iostream>
#include <string>
#include <map>


namespace Global{
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    const float PLAYER_SIZE = 2.0f;
};

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Vector2 {
	int x, y;
	Vector2() :
		x(0), y(0)
	{}
	Vector2(int x, int y) :
		x(x), y(y)
	{}
	Vector2 zero() {
		return Vector2(0, 0);
	}
};