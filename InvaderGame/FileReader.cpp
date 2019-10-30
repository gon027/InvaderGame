#include "FileReader.h"

#include "DxLib.h"

void FileReader::open(const char *_path, const char* _mode){
	errno_t error;
	error = fopen_s(&scoreFile, _path, _mode);
	if (error != 0) {
		printfDx("FileReader::open_ERROR\n");
	}
	printfDx("FileReader::open_SUCCESS!!\n");
}

void FileReader::read(const char *_path, const char * _mode){
	open(_path, _mode);
	int eof = fscanf_s(scoreFile, "%d", &hiScore);
	if (eof == EOF) {
		printfDx("FileReader::read_ERROR!!\n");
	}
	close();
	printfDx("FileReader::read_SUCCESS!!\n");
}

void FileReader::write(const char *_path, const char* _mode, int _hiScore){
	open(_path, _mode);
	int eof = fprintf_s(scoreFile, "%d", _hiScore);
	if (eof == EOF) {
		printfDx("FileReader::write_ERROR!!\n");
	}
	close();
	printfDx("FileReader::write_SUCCESS!!\n");
}

void FileReader::close(){
	fclose(scoreFile);
}

int FileReader::getScore(){
	return hiScore;
}