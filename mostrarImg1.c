#include "highgui.h"
/*Para mostrar una imagen*/
int main(int argc, char** argv)
{
	IplImage* img = cvLoadImage(argv[1],1);//Carga una imagen(nombre) y devuelve una estructura IplImage
	IplImage* img2 = cvLoadImage(argv[2],1);
	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);//Crea una ventana llamada example1 para mostrar imagenes
	cvShowImage("Example1",img);//Muestra la imagen en la ventana
	cvWaitKey(0);//Espera una tecla
	cvShowImage("Example1",img2);
	cvWaitKey(0);
	cvReleaseImage(&img);
	cvReleaseImage(&img2);
	cvDestroyWindow("Example1");
}
