#include <cv.h>
#include <highgui.h>
#define __ROI__
/*
 * Ejemplo de uso de ROI para definir un segmento dentro 
 * de la imagen y modificarlo. 
 * Tambien se agrega la posibilidad de realizar lo mismo por
 * medio del uso de widthStep
 */
int main(int argc, char** argv)
{
	IplImage *src;
	if (argc == 7 && ((src = cvLoadImage(argv[1],1)) != 0)){
		int x = atoi(argv[2]);
		int y = atoi(argv[3]);
		int width = atoi(argv[4]);
		int height = atoi(argv[5]);
		int add = atoi(argv[6]);
#ifdef __ROI__ 
		cvSetImageROI(src,cvRect(x,y,width,height)); //Crea el segmento en base a un rectangulo, en las posiciones x e y, de tamaño w y h.
		cvAddS(src, cvScalar(add,0,0,0),src, NULL); //Suma una matriz con un scalar
		cvResetImageROI(src);
		//con widthStep:
#else
		cvRect interest_rect = cvRect(x,y,width,height);
		IplImage *sub_img = cvCreateImageHeader(//Se define el header de una nueva imagen, con el tamano del segmento deseado,y el widthStep y depth de la imagen original(para que al moverse por el subcuadro sea como moverse por la imagen completa
				cvSize(
					interest_rect.width,
					interest_rect.height),
				src->depth,
				src->nChannels
				);
		sub_img->origin = src->origin;
		sub_img->widthStep = src->widthStep;
		//Se pone el puntero de imageData de la subimagen en donde se desea ubicar el recuadro, en la imagen original
		sub_img->imageData = src->imageData + interest_rect->y * src->widthStep + interest_rect->x * srx->nChannels;
		cvAddS(sub_img,cvScalar(1,0,0,0),sub_img);
#endif
		cvNamedWindow("ROI_ADD",CV_WINDOW_AUTOSIZE);
		cvShowImage("ROI_ADD",src);
		cvWaitKey(0);
		}
	return 0;
}
