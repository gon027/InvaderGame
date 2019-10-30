#ifndef FILEREADER_J
#define FILEREADER_H

#include <cstdio>
#include <cstdlib>
#include "singleton.h"
using namespace std;

class FileReader : public singleton<FileReader>{
public:
	friend class singleton<FileReader>;

	void open(const char*, const char*);			//�t�@�C�����J��
	void read(const char*, const char *);			//�t�@�C����ǂݍ���
	void write(const char*, const char*, int);		//�t�@�C���ɏ�������
	void close();									//�t�@�C�������
	int getScore();

protected:
	FileReader() = default;
	~FileReader() = default;

private:
	FILE *scoreFile;
	int hiScore;
};

#endif // !FILEREADER_J


