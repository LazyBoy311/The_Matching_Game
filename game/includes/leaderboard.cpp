#include "leaderboardcomponent.h"
#include<iostream>
#include"leaderboard.h"
using namespace std;
Node* createNode(string name, int time) {
    Node* P = new Node;
    P->info.Name = name;
    P->info.Time = time;
    P->next = nullptr;
    return P;
}

void addNode(LeaderBoard& P, string name, int time) {
    Node* A = createNode(name, time), * tmp = P.head;
    if (P.head == nullptr)
        P.head = P.tail = A;
    else {
        if (P.head->info.Time > time) {
            A->next = P.head;
            P.head = A;
        }
        else {
            while (tmp->next != nullptr && tmp->next->info.Time < time)
                tmp = tmp->next;
            A->next = tmp->next;
            tmp->next = A;
            if (A->next == nullptr) P.tail = A;
        }
    }
}

LeaderBoard readFile() {
    ifstream fi;
    fi.open("LeaderBoard.txt");
    LeaderBoard P;
    string s;
    int a;
    
    if(!fi){
    	std::cout << "error 404: not found";
	}

    while (!fi.eof()) {
        fi >> s;
        fi >> a;
        addNode(P, s, a);
    }
    fi.close();
    return P;
}

void PrintList(LeaderBoard P) {
    ofstream fo;
    fo.open("LeaderBoard.txt");
    int i = 3;
    while (i-- && P.head != nullptr) {
    	if(P.head->info.Name != "")
        	fo << P.head->info.Name << " " << P.head->info.Time << "\n";
        P.head = P.head->next;
    }
    fo.close();
}

