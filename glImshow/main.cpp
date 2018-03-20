#include "stdafx.h"
#include "glImshow.h"

void display();
void keyboard(unsigned char key, int x, int y);
void mainLoop();

cv::VideoCapture capture(2);

int main(int argc, char *argv[])
{
	glImshowInit(argc, argv, capture.get(CV_CAP_PROP_FRAME_WIDTH), capture.get(CV_CAP_PROP_FRAME_HEIGHT), "glImshow", GLUT_RGB);
	glImshowSetFunc(display, keyboard, mainLoop);
	glImshowStart();
	return 0;
}

void display()
{

}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'q':
	case 'Q':
	case '\033':
		glutLeaveMainLoop();
	default:
		break;
	}
}

void mainLoop()
{
	cv::Mat mat;
	capture >> mat;
	glImshow(mat, CV_BGR2RGB, GL_RGB);
}
