#ifndef BLOCK_H
#define BLOCK_H

class Block {
public:
	Block();
	~Block();

	void init(int _x, int _y);
	void load();
	void update();
	void draw();
	bool collision(int _x, int _y, int _width, int _height);

	bool getLife();

	void zeroLife();

	//‰æ‘œ‚ð“ü‚ê‘Ö‚¦‚é
	Block& operator++(int _count);

	//¶‘¶ƒtƒ‰ƒO‚ð•Ô‚·
	bool operator()() {
		return this->life;
	}

private:
	int img[4];
	int image;
	int x;
	int y;
	int width = 32;
	int height = 32;
	int count;
	bool life;
};

#endif // !BLOCK_H