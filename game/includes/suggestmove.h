#pragma once
#include"point.h"

struct suggestmove {
    int x1, y1, x2, y2;
};

suggestmove SuggestMove(int R, int C, Point** ptr);
