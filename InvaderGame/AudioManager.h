#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

#include "singleton.h"

class AudioManager : public singleton<AudioManager>{
public:
	friend class singleton<AudioManager>;

	void read(const char* _path, int _index);
	void play(int _index);

protected:
	AudioManager() = default;
	~AudioManager() = default;

private:
	int sound[10];
};

#endif // !AUDIOMANAGER_H
