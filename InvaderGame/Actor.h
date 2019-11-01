#ifndef ACTOR_H
#define ACTOR_H

class Bullet;

class Actor {
public:
	Actor() = default;
	virtual ~Actor() = default;

	bool isActorCollision(Actor& enemy);        //Actor同士の当たり判定
	bool isBulletCollision(Bullet& bullet);	    //Bulletの当たり判定

	void LoadActorImage(const char* path);      //画像読み込み
	void DrawImage(int x, int y);               //画像描画

	void LoadActorImgBuf(const char* _path);    //画像の配列に画像を読み込む
	void DrawImageFromImgBuf(int _x, int _y, int _index);     //画像の配列からindexを指定して描画する

protected:
	virtual void setup()  = 0;      //主に画像をメモリに読み込む処理
	virtual void update() = 0;      //更新関数

	virtual void init() = 0;               //初期化関数
	virtual void init(int _x, int _y) {};  //初期化関数
	virtual void init(int _x, int _y, int _index) {};  //初期化関数
	virtual void draw() = 0;               //描画関数
	virtual void move() = 0;               //移動関数

public:
	int x;          //x座標
	int y;          //y座標

	int img;		//画像ハンドル
	int imgbuf[3];
	int width;      //画像の横幅
	int height;     //画像の縦幅
	int xspeed;     //x軸への移動するときのスピード
	int yspeed;     //y軸への移動するときのスピード
	bool life;      //生きているかのフラグ
};

#endif // !ACTOR_H