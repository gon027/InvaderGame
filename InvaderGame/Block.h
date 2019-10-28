#ifndef BLOCK_H
#define BLOCK_H

class Block {
public:
	Block();
	~Block();

	void init(int _x, int _y);
	void setup();
	void update();
	void draw();
	void addCount(int _value);
	bool collision(int _x, int _y, int _width, int _height);

	bool getLife();
	void zeroLife();

	//‰æ‘œ‚ð“ü‚ê‘Ö‚¦‚é
	Block& operator++(int _count);

private:
	int img[4];
	int x;
	int y;
	int width = 16;
	int height = 16;
	int count;
	bool life;
};

#endif // !BLOCK_H