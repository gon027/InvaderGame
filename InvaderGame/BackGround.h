#ifndef BACKGROUND_H
#define BACKGROUND_H

class BackGround {
public:
	BackGround() = default;
	BackGround(int, int, const char*);
	~BackGround() = default;

	//使わない（将来使うかもしれない）---
	void setup();
	void init(int, int, const char*);
	//----------------------------------

	void loadImage();
	void draw();

private:
	int img;
	int x;
	int y;
	const char* path;
};

#endif // !BACKGROUND_H
