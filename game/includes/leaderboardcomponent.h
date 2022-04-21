#pragma once
#include<string>

struct Data {
    std::string Name;
    int Time;
};
struct Node {
    Data info;
    Node* next = nullptr;
};

struct LeaderBoard {
    Node* head = nullptr;
    Node* tail = nullptr;
};

