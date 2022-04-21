#include"leaderboardcomponent.h"
#include<string>
#include<fstream>
Node* createNode(std::string name, int time);

void addNode(LeaderBoard& P,std::string name, int time);

LeaderBoard readFile();

void PrintList(LeaderBoard P);

