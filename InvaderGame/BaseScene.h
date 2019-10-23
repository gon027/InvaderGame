#ifndef BASESCENE_H
#define BASESCENE_H

class BaseScene {
public:
	BaseScene() {};
	virtual ~BaseScene() {};

	virtual void start() = 0;
	virtual void update() = 0;
};

#endif // !BASESCENE_H
