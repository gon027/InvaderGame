#ifndef TITLESCENE_H
#define TITLESCENE_H

#include "BaseScene.h"

class TitleScene : public BaseScene{
public:
	TitleScene();
	~TitleScene();

	void start() override;
	void update() override;
};


#endif // !TITLESCENE_H
