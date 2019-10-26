#ifndef ACTOR_H
#define ACTOR_H



class Bullet;

class Actor {
public:
	Actor() {};
	virtual ~Actor() {};

	bool isActorCollision(Actor& enemy);        //Actor同士の当たり判定
	bool isBulletCollision(Bullet& bullet);	    //Bulletの当たり判定

protected:
	virtual void setup()  = 0;      //主に画像をメモリに読み込む処理
	virtual void update() = 0;      //更新関数

	virtual void init() = 0;               //初期化関数
	virtual void init(int _x, int _y) {};  //初期化関数
	virtual void draw() = 0;               //描画関数
	virtual void move() = 0;               //移動関数

	void LoadActorImage(const char* path);      //画像読み込み
	void DrawImage(int x, int y);               //画像描画

public:
	int x;
	int y;

	int img;		//画像ハンドル
	int width;
	int height;
	int xspeed;
	int yspeed;
	bool life;
};

#endif // !ACTOR_H