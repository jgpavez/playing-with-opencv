#include <cv.h>
#include <highgui.h>

/*
 * Alpha blend example, 
 * calcula la suma de dos imagenes, segun los parametros dados para roi
 * y un alpha y betha que simbolizan el peso de cada imagen
 * ./prog img1 img2 x y width height alpha betha
 * alpha + betha = 1
 */
int main(int argc, char **argv)
{
	IplImage *src1,*src2;
	if (argc == 9 && ((src1 = cvLoadImage(argv[1],1)) != 0) && ((src2 = cvLoadImage(argv[2],1)) != 0)){
		int x = atoi(argv[3]);
		int y = atoi(argv[4]);
		int width = atoi(argv[5]);
		int height = atoi(argv[6]);
		double alpha = (double)atof(argv[7]);
		double beta  = (double)atof(argv[8]);

		cvSetImageROI(src1, cvRect(x,y,width,height));
		cvSetImageROI(src2, cvRect(0,0,width,height));
		cvAddWeighted(src1,alpha,src2,beta,0.0,src1);
		cvResetImageROI(src1);
		cvNamedWindow("Alplha_blend",CV_WINDOW_AUTOSIZE);
		cvShowImage("Alpha_blend", src1);
		cvWaitKey(0);
}
return 0;
}

