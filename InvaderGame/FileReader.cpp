#include "FileReader.h"

#include <cstdio>
#include <cstdlib>
#include "DxLib.h"
using namespace std;

void FileReader::open(const char *_path, const char* _mode){
	errno_t error;
	error = fopen_s(&scoreFile, _path, _mode);
	if (error != 0) {
		printfDx("FileReader::Setup_ERROR");
	}
}

void FileReader::read(const char *_path, const char * _mode){
	open(_path, _mode);
	fscanf_s(scoreFile, "%d", &hiScore);
	close();
}

void FileReader::write(const char *_path, const char* _mode, int _hiScore){
	open(_path, _mode);
	fprintf_s(scoreFile, "%d", _hiScore);
	close();
}

void FileReader::close(){
	fclose(scoreFile);
}

int FileReader::getScore(){
	return hiScore;
}
