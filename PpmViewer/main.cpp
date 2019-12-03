#ifdef WIN32_
#define WIN32 1
#endif


#include "PpmWindow.hpp"
int main(int argc, char* argv[])
{
	PpmWindow win{ 0, 0, 600, 250, "PPM Viewer" };
	win.end();
	win.show();
	return Fl::run();
}