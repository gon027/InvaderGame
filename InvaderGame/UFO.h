#ifndef UFO_H
#define UFO_H

#include "Actor.h"

class UFO : public Actor {
public:
	UFO();
	~UFO();

	void setup() override;
	void update() override;
	void clear();

	void init() override;
	void draw() override;
	void move() override;

	void randPoint();

	int getUfoScore() noexcept;

private:
	int interval;
};

#endif // !UFO_H
