#ifndef BLOCK_H
#define BLOCK_H

class Block {
public:
	Block();
	~Block();

	void init();
	void update();
	void draw(int x, int y);

	bool collision(int x, int y);

private:
	int img;
	int x;
	int y;
	int width;
	int height;
};

#endif // !BLOCK_H