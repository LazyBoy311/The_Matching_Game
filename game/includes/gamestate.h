#include"suggestmove.h"
#include"matching.h"
#include <cstdlib>
#include <iostream>
#include <conio.h>
#include "adjustterminal.h"
#include "endstate.h"
#include"graphic.h" 
#include"graphicrender.h"

using namespace std;

void PlayGame(int R,int C);

void CreateGrid(int R,int C,Point **&ptr);

void GenerateValue(int &R,int &C,Point **&ptr);

void DrawGrid(int R,int C,Point **ptr,int *currentX,int *currentY);

void SelectValue(int R,int C,Point **&ptr,int *currentX,int *currentY,int &turn, int Time);

