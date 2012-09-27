#include "cv.h"
#include "highgui.h"

int main(int argc, char **argv)
{
	cvNamedWindow("Src",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Dstr",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Dst",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Dst2",CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Laplace",CV_WINDOW_AUTOSIZE);
	IplImage *src = cvLoadImage(argv[1],1);
	cvShowImage("Src",src);
	IplImage *dst = cvCreateImage(cvSize(src->width/2,src->height/2), src->depth, src->nChannels);
	IplImage *dstr = cvCreateImage(cvSize(src->width/2,src->height/2), src->depth, src->nChannels);

	cvPyrDown(src,dst, IPL_GAUSSIAN_5x5); //Do PyrDown pierde informacion de la imagen
	cvResize(src,dstr, CV_INTER_LINEAR);
	cvShowImage("Dst",dst);
	cvShowImage("Dstr",dstr);
	uchar *ptr = (uchar *)src->imageData;
	printf("%f\n", (float)ptr[3]);
	ptr = (uchar *)dst->imageData;
	printf("%f\n", (float)ptr[3]);
	IplImage *laplace = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);
	IplImage *dst2 = cvCreateImage(cvGetSize(src), src->depth, src->nChannels);
	cvPyrUp(dst,dst2,IPL_GAUSSIAN_5x5);//Hay información que no se tiene de la imagen original
					//por lo que pyrUp no mantiene la resolución
	cvSub(src,dst2,laplace,NULL);//en laplace Pyramid se guarda la información que se pierde
				//en pyrdown
	cvAdd(laplace,dst2,dst2,NULL);//Se agrega esta información a la imagen final
	cvShowImage("Laplace",laplace);
	cvShowImage("Dst2",dst2);
	cvWaitKey(0);
	cvDestroyWindow("Src");
	cvDestroyWindow("Dst2");
	cvDestroyWindow("Dst");
	cvDestroyWindow("Laplace");
}
