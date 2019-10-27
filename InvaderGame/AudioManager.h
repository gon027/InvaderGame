#ifndef AUDIOMANAGER_H
#define AUDIOMANAGER_H

class AudioManager {
private:
	AudioManager();

	static AudioManager* sound;



public:
	void play(int);
};

static AudioManager::AudioManager* sound == nullptr;

#endif // !AUDIOMANAGER_H
