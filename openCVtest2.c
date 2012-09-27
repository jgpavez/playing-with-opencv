#include "highgui.h"
#include <assert.h>

/*Para Mostrar un video*/
int main(int argc, char** argv)
{
	cvNamedWindow("Example2",CV_WINDOW_AUTOSIZE);
	CvCapture* capture = cvCreateFileCapture(argv[1]);//Carga la informacionm y frames de un archivo.avi, se inicia en primer frame
//	assert(capture != NULL);
	IplImage* frame;
	while (1){
		frame = cvQueryFrame(capture);//Carga siguiente frame en memoria(que ya es parte de capture) y devuelve una estructura IplImage
//		assert(frame != NULL);
		if (!frame) break;
		cvShowImage("Example2",frame);
		char c = cvWaitKey(33);//waits 33 ms
		if (c == 27) break;//if c = esc termina de reproducir
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("Example2");
}
