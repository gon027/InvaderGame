#ifndef ACTOR_H
#define ACTOR_H



class Bullet;

class Actor {
public:
	Actor() {};
	virtual ~Actor() {};

	bool isActorCollision(Actor& enemy);        //Actor���m�̓����蔻��
	bool isBulletCollision(Bullet& bullet);	    //Bullet�̓����蔻��

protected:
	virtual void setup()  = 0;      //��ɉ摜���������ɓǂݍ��ޏ���
	virtual void update() = 0;      //�X�V�֐�

	virtual void init() = 0;               //�������֐�
	virtual void init(int _x, int _y) {};  //�������֐�
	virtual void draw() = 0;               //�`��֐�
	virtual void move() = 0;               //�ړ��֐�

	void LoadActorImage(const char* path);      //�摜�ǂݍ���
	void DrawImage(int x, int y);               //�摜�`��

public:
	int x;          //x���W
	int y;          //y���W

	int img;		//�摜�n���h��
	int width;      //�摜�̉���
	int height;     //�摜�̏c��
	int xspeed;     //x���ւ̈ړ�����Ƃ��̃X�s�[�h
	int yspeed;     //y���ւ̈ړ�����Ƃ��̃X�s�[�h
	bool life;      //�����Ă��邩�̃t���O
};

#endif // !ACTOR_H