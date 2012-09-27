#include <cxcore.h>

int main()
{
	char *libraries,*modules;
	cvGetModuleInfo(0,&libraries,&modules);
	printf("Libraries: %s\n Modules: %s\n",libraries, modules);
	return 0;
	}

