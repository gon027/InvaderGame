#ifndef FILEREADER_J
#define FILEREADER_H

#include <cstdio>
#include <cstdlib>
using namespace std;
#include "singleton.h"

class FileReader : singleton<FileReader>{
public:
	friend class singleton<FileReader>;

	void open(const char*, const char*);
	void read(const char*, const char *);
	void write(const char*, const char*, int);
	void close();
	int getScore();

protected:
	FileReader() = default;
	~FileReader() = default;

private:
	//int file;


	FILE *scoreFile;

	int hiScore;
};

#endif // !FILEREADER_J


