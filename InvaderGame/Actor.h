#ifndef ACTOR_H
#define ACTOR_H

class Bullet;

class Actor {
public:
	Actor() = default;
	virtual ~Actor() = default;

	bool isActorCollision(Actor& enemy);        //Actor���m�̓����蔻��
	bool isBulletCollision(Bullet& bullet);	    //Bullet�̓����蔻��

	void LoadActorImage(const char* path);      //�摜�ǂݍ���
	void DrawImage(int x, int y);               //�摜�`��

	void LoadActorImgBuf(const char* _path);    //�摜�̔z��ɉ摜��ǂݍ���
	void DrawImageFromImgBuf(int _x, int _y, int _index);     //�摜�̔z�񂩂�index���w�肵�ĕ`�悷��

protected:
	virtual void setup()  = 0;      //��ɉ摜���������ɓǂݍ��ޏ���
	virtual void update() = 0;      //�X�V�֐�

	virtual void init() = 0;               //�������֐�
	virtual void init(int _x, int _y) {};  //�������֐�
	virtual void init(int _x, int _y, int _index) {};  //�������֐�
	virtual void draw() = 0;               //�`��֐�
	virtual void move() = 0;               //�ړ��֐�

public:
	int x;          //x���W
	int y;          //y���W

	int img;		//�摜�n���h��
	int imgbuf[3];
	int width;      //�摜�̉���
	int height;     //�摜�̏c��
	int xspeed;     //x���ւ̈ړ�����Ƃ��̃X�s�[�h
	int yspeed;     //y���ւ̈ړ�����Ƃ��̃X�s�[�h
	bool life;      //�����Ă��邩�̃t���O
};

#endif // !ACTOR_H