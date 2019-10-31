#ifndef WALL_H
#define WALL_H

#include "Block.h"

class WALL {
public:
	WALL();
	~WALL();

	void init(int _x, int _y);
	void setup();
	void draw();
	void update();
	void clear();
	bool hitTest(int _x, int _y, int _w, int _h);
	void ehitTest(int _x, int _y, int _w, int _h);

private:
	Block wall[4][4];
	int size = 16;
};

#endif // !WALL_H
