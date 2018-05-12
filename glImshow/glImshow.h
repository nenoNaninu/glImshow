#pragma once
#include "stdafx.h"

void glImshowInit(int argc, char *argv[], int width, int height, const char* windowName, int glutMode);
void glImshowStart();
void glImshowSetFunc(void(*display)(void), void(*keydordFunc)(unsigned char, int, int), void(*mainLoop)(void), void(*mousePressed)(int button, int state, int x, int y));
void glImshow(const cv::Mat& mat, int convertFormatCV2GL, int glShowFormat);