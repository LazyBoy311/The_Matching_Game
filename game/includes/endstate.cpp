#include"endstate.h"

void EndGame(int X) {
	system("cls");
    LeaderBoard LB = readFile();
	cout << "you have completed the game" << endl;
    //X is completion time
    for(int i = 3; i >=1; i--)
    	addNode(LB, "Phat", 999);
    if (X < LB.tail->info.Time) {
        cout << "You have high score. Your name: ";
        std::string S;
        cin >> S;
        addNode(LB, S, X);
        PrintList(LB); 
    }else {
		cout << "Nice Try!!" << endl;
	}
    
	int n; 
    cout << "Press 1 to return menu press different key to exit program:";
    cin >> n;
    if(n == 1)
    { 
     	Menu();   
    }

}
