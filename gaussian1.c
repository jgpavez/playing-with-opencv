#include "cv.h"
#include "highgui.h"

int main(int argc, char** argv)
{
	cvNamedWindow("Example4-in",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Example4-out",CV_WINDOW_AUTOSIZE);
	IplImage* img = cvLoadImage(argv[1],1);
	cvShowImage("Example4_in",img);
	IplImage* out = cvCreateImage(cvGetSize(img),IPL_DEPTH_8U,3);//crea una estructura para una imagem. recibe el tamaño,el tipo de data usado para cada canal en cada pixel, el numero de canales(3 canales, 8 bit por canal) 
	cvSmooth(img,out,CV_GAUSSIAN,3,3,0,0);//realiza el smooth en la imagen, lo guarda en out, recibe el tipo de smooth, y el area del smooth(3x3) centrado en el pixel
	cvShowImage("Exammple4_out",out);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvReleaseImage(&out);
	cvDestroyWindow("Example4-in");
	cvDestroyWindow("Example4-out");
}

