#include "stdafx.h"
#include "glImshow.h"

void display();
void keyboard(unsigned char key, int x, int y);
void mainLoop();
void mousePressed(int button, int state, int x, int y);
void displayFps();

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
    displayFps();
}

void mousePressed(int button, int state, int x, int y)
{
    std::cout << x << " " << y << std::endl;
}

void displayFps()
{
    static int fps = 0;
    static std::chrono::system_clock::time_point time = std::chrono::system_clock::now();
    if (std::chrono::duration_cast<std::chrono::milliseconds> (std::chrono::system_clock::now() - time).count() >= 1000)
    {
        std::cout << fps << std::endl;
        fps = 0;
        time = std::chrono::system_clock::now();
    }
    fps++;
}
