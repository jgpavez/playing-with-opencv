#include "highgui.h"
#include "cv.h"
#include <assert.h>

int g_slider_position = 0;//Variable global que representa la posicion del slide
CvCapture* g_capture  = NULL;

void onTrackbarSlide(int pos)//Callback, usado al mover el slider, recibe la posicion del slider
{
	cvSetCaptureProperty(g_capture,CV_CAP_PROP_POS_FRAMES,pos);//Setea propiedades del cvCapture,recibe, elo objeto cvCapture, la propiedad a setear, el valor
}

/*Para Mostrar un video*/
int main(int argc, char** argv)
{
	cvNamedWindow("Example3",CV_WINDOW_AUTOSIZE);
	g_capture = cvCreateFileCapture(argv[1]);
//	assert(capture != NULL);
	int frames = (int) cvGetCaptureProperty(g_capture,CV_CAP_PROP_FRAME_COUNT);//Entrega el numero de frames en el cvCapture object, para calibrar el slider
	if (frames != 0){//Algunas codificaciones no entregan info de el # de frames
		cvCreateTrackbar("Position","Example3",&g_slider_position,frames,onTrackbarSlide);//crea el trackbar, recibe el nombre, la ventana, una referencia para informar su posicion, el total de frames y el callback
	}
	IplImage* frame;
	while (1){
		frame = cvQueryFrame(g_capture);//Carga siguiente frame en memoria(que ya es parte de capture) y devuelve una estructura IplImage
//		assert(frame != NULL);
		if (!frame) break;
		cvShowImage("Example3",frame);
		char c = cvWaitKey(33);//waits 33 ms
		if (c == 27) break;//if c = esc termina de reproducir
	}
	cvReleaseCapture(&g_capture);
	cvDestroyWindow("Example3");
}
