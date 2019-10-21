#ifndef DEFINE_H
#define DEFINE_H

//#define FULL_SCREEN

#define OR ||
#define AND &&

namespace Window {
	
#ifdef FULL_SCREEN
	static const int WIDTH = 1440;
	static const int HEIGHT = 900;
#else
	static const int WIDTH = 640;
	static const int HEIGHT = 480;
#endif // FULL_SCREEN
}

namespace Alian{
	static const int W = 3;
	static const int H = 3;
}

#endif // !DEFINE_H

