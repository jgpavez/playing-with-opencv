#include "cv.h"
#include "highgui.h"
#include <assert.h>


/*Para Mostrar un video*/
int main(int argc, char** argv)
{
	cvNamedWindow("Example2",CV_WINDOW_AUTOSIZE);
	CvCapture* capture;
	if (argc == 1){
		capture = cvCreateCameraCapture(0);//En caso de que halla solo una camara conectada, se pone a 0, sino, se debe poner el codigo de camara
	}
	else{
		capture = cvCreateFileCapture(argv[1]);//El manejo para mostrar los frames es el mismo
	}
	assert(capture != NULL);
	IplImage* frame;
	while (1){
		frame = cvQueryFrame(capture);
		assert(frame != NULL);
		if (!frame) break;
		cvShowImage("Example2",frame);
		char c = cvWaitKey(33);
		if (c == 27) break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("Example2");
}
