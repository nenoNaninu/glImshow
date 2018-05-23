#include "stdafx.h"
#include "glImshow.h"

void display();
void keyboard(unsigned char key, int x, int y);
void mainLoop();
void mousePressed(int button, int state, int x, int y);

cv::VideoCapture capture(0);

int main(int argc, char *argv[])
{
    glImshowInit(argc, argv, capture.get(CV_CAP_PROP_FRAME_WIDTH), capture.get(CV_CAP_PROP_FRAME_HEIGHT), "glImshow", GLUT_RGB);
    glImshowSetFunc(display, keyboard, mainLoop, mousePressed);
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

void mousePressed(int button, int state, int x, int y)
{
    std::cout << x << " " << y << std::endl;
}