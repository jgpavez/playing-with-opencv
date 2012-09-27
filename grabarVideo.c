//Convierte a escala de grises
//argv[1]:input video
//argv[2]:Nombre del output

#include "cv.h"
#include "highgui.h"
#include <assert.h>

int main(int argc, char* argv[])
{
	cvNamedWindow("Example1",CV_WINDOW_AUTOSIZE);	
	CvCapture* capture;
	if (argc == 1){
		capture = cvCreateCameraCapture(0);
	}
	else{
		capture = cvCreateFileCapture(argv[1]);
	}
	assert(capture != NULL);
	IplImage* bgr_frame = cvQueryFrame(capture);
	//double fps = cvGetCaptureProperty(capture,CV_CAP_PROP_FPS);
	CvSize size = cvSize((int) cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_WIDTH),(int) cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT));
	//CvVideoWriter* writer = cvCreateVideoWriter(argv[2],CV_FOURCC('M','J','P','G'),fps,size,1);//Crea un writer de video, recibe el nombre del video a crear, el codec de video(se usa el codigo de 4 caracteres del codec MJPG en este caso),el frame rate, el tamaño de las imagenes,1)
	IplImage* logpolar_frame = cvCreateImage(size,IPL_DEPTH_8U,3);
	bgr_frame = cvQueryFrame(capture);
	assert(capture != NULL);
	while ((bgr_frame = cvQueryFrame(capture)) != NULL){
		cvLogPolar(bgr_frame,logpolar_frame,cvPoint2D32f(bgr_frame->width/2,bgr_frame->height/2),40,CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS);
		cvShowImage("Example1",logpolar_frame);
		char c = cvWaitKey(33);
		if (c == 27) break;
	}
	//cvReleaseVideoWriter(&writer);
	//cvReleaseImage(&logpolar_frame);
	cvReleaseCapture(&capture);
	cvDestroyWindow("Example1");
	return 0;
}


