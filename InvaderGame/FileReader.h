#ifndef FILEREADER_J
#define FILEREADER_H

#include <cstdio>
#include <cstdlib>
#include "singleton.h"
using namespace std;

class FileReader : public singleton<FileReader>{
public:
	friend class singleton<FileReader>;

	void open(const char*, const char*);			//ファイルを開く
	void read(const char*, const char *);			//ファイルを読み込む
	void write(const char*, const char*, int);		//ファイルに書き込む
	void close();									//ファイルを閉じる
	int getScore();

protected:
	FileReader() = default;
	~FileReader() = default;

private:
	FILE *scoreFile;
	int hiScore;
};

#endif // !FILEREADER_J


