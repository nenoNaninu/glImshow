#include "stdafx.h"
#include "glImshow.h"

void timer(int value)
{
    glutSwapBuffers();
    glutTimerFunc(value, timer, value);
}

void glImshowInit(int argc, char *argv[], int width, int height, const char* windowName, int glutMode, int fps)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(glutMode | GLUT_DOUBLE);
    glutInitWindowSize(width, height);
    glutCreateWindow(windowName);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, width, height, 0.0);
    glViewport(0, 0, width, height);
    glutTimerFunc(1000 / fps, timer, 1000 / fps);//fpsをmsecに換算
    std::cout << 1000 / fps << std::endl;
}

void glImshowStart()
{
    glutMainLoop();
}

void glImshowSetFunc(void(*display)(void), void(*keydordFunc)(unsigned char, int, int), void(*mainLoop)(void), void(*mousePressed)(int button, int state, int x, int y))
{
    glutDisplayFunc(display);
    glutKeyboardFunc(keydordFunc);
    glutIdleFunc(mainLoop);
    glutMouseFunc(mousePressed);
}

void glImshow(const cv::Mat & mat, int convertFormatCV2GL, int glShowFormat)
{
    cv::Mat clone = mat.clone();
    cv::flip(mat, clone, 0);
    cv::cvtColor(clone, clone, convertFormatCV2GL);

    glClear(GL_COLOR_BUFFER_BIT);
    glDrawPixels(clone.cols, clone.rows,
        glShowFormat, GL_UNSIGNED_BYTE, clone.data);
}
