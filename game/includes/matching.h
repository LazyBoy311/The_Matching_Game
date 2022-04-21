#pragma once
#include"point.h"
#include <cmath>
#include <ctime>

using namespace std;
bool checkMatching(int R, int C, Point** ptr, Point ps1, Point ps2);

bool checkAvailable(int R, int C, Point** ptr);

void resetValue(int R, int C, Point**& ptr);
