#include "cv.h"
#include "highgui.h"
#include <assert.h>
//Funciones Wrappers,se encargan de alocar memoria y generar la imagen
//
IplImage* doPyrDown(IplImage* in)//Reduce la imagen a la mitad de su tamaño
{
	assert(in->width%2 == 0 && in->height%2 == 0);
	IplImage* out = cvCreateImage(cvSize(in->width/2, in->height/2),in->depth,in->nChannels);
	cvPyrDown(in,out,CV_GAUSSIAN_5x5);
	return out;
};

IplImage* doCanny(IplImage* in, double lowThresh, double highThresh, double aperture)
{
	assert(in->nChannels == 1);
	IplImage* out = cvCreateImage(cvGetSize(in),IPL_DEPTH_8U,1);
	cvCanny(in, out, lowThresh, highThresh, aperture);
	return out;
}
int main(int argc, char** argv)
{
	cvNamedWindow("Example5-in",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Example5-out",CV_WINDOW_AUTOSIZE);
	IplImage* img = cvLoadImage(argv[1],1);
	cvShowImage("Example5-in", img);
	IplImage* img2 = doPyrDown(img);
	IplImage* out = doCanny(img2,10,100,3);
	cvShowImage("Example5-out",out);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvReleaseImage(&img2);
	cvReleaseImage(&out);
	cvDestroyWindow("Example5-in");
	cvDestroyWindow("Example5-out");
}


	
