#MakeFile OpenCV 

CC = -lcxcore -lcv -lcvaux -lhighgui -lml
CXXFLAGS = -I"/home/juan/opencvdir/OpenCV-2.1.0/include/opencv"
LIBS = -L"/usr/local/lib"

doPyr: cameraCapture.c
	gcc cameraCapture.c -o cameraCapturetest $(CXXFLAGS) $(LIBS) $(CC) 

