#include "AudioManager.h"

#include "DxLib.h"

void AudioManager::read(const char * _path, int _index){
	sound[_index] = LoadSoundMem(_path);
	if (sound[_index] == -1) {
		printfDx("AidioManage::Read_ERROR");
	}
}

void AudioManager::play(int _index){
	int error;
	error = PlaySoundMem(sound[_index], DX_PLAYTYPE_BACK);
	if (error == -1) {
		printfDx("AudioManager::Play_ERROR");
	}
}
