#ifndef WALL_H
#define WALL_H

#include "Block.h"

class WALL {
public:
	WALL();
	~WALL();

	void init(int _x, int _y);
	void load();
	void draw();
	void update();

	WALL& operator+=(int count);

private:
	Block wall[4][4];
};

#endif // !WALL_H
