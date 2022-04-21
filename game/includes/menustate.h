#pragma once
#include"button.h"
#include"gamestate.h"
#include"adjustterminal.h"
#include<iostream>
#include<fstream>

void OpenMenu();

void InitGame(int index);

void DrawMenu(Button *btn,int n);

void SimpleMenu(Button *btn);

void Menu();
