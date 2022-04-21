#include"menustate.h"

void OpenMenu(){
	ifstream fi;
    fi.open("LeaderBoard.txt");
    string s;
    
    if(!fi){
    	std::cout << "error 404: not found";
	}
	std::cout << "LeaderBoard" << endl;  
    while (!fi.eof()) {
        getline(fi,s);
		std::cout << s << std:: endl; 
    }
    fi.close();
    std::cout << "Press 1 to return menu :";
	int n;
	std::cin >> n;
	if(n ==1) 
	{
		Menu();
	} 
} 

void InitGame(int index)
{
	system("cls"); 
    if(index == 0)
    {
        int R,C;
		gotoxy(65,20);
        std::cout << "Write Amount Row and Column:";
        std::cin >> R >> C;
        while(R < 5 && C < 5) {
        	gotoxy(65,20);
        	std::cout << "You type smaller than 5 x 5 please try again :";
        	std::cin >> R >> C;
		} 
        system("cls"); 
        PlayGame(R,C);
    }else if(index == 1){
    	OpenMenu();
	} else {
		return ; 
	} 
}

void DrawMenu(Button *btn,int n)
{
    system("cls");
    gotoxy(74,1);
    std::cout << "WELCOME" << std::endl;
    int renderRow = 3;
    for(int i = 0; i < n;i++)
    {
        for(int j = 0;j < btn[0].box.length();j++)
        {

            if(j % 14 == 0)
            {
                std::cout << std::endl;
                gotoxy(70 ,renderRow++);
            }
            std::cout << btn[i].box[j];
        }
        std::cout << std::endl << std::endl;
        renderRow+=2;
    } 

}

void SimpleMenu(Button *btn)
{
    int c = 0;
    int index = 0;

    //using string Array can be take up more memory in application but it can bring better user experience UX and easy to maintain
    while(c != 27)
    {
        c = 0;
        switch(c = _getch()) {
            // if the option change please change 2 to n as you desired
            case 72:
                index = index <= 0 ? 2 : index - 1;
                for(int i = 0; i < 3;i++)
                {
                    btn[i].DeSelectButton();    
                }
                btn[index].SelectButton();   
                DrawMenu(btn,3);
                break;
            case 80:
                index = index >= 2 ? 0 : index+1;
                for(int i = 0; i < 3;i++)
                {
                    btn[i].DeSelectButton();    
                }
                btn[index].SelectButton();   
                DrawMenu(btn,3);
                break;  
            case 32:
                InitGame(index);
                break;
            }
        }
        
}

void Menu()
{
    Button buttons[3] = {{"+------------+|            ||    PLAY    ||            |+------------+"}, 
						{"+------------+|            ||     LB     ||            |+------------+"},
                        {"+------------+|            ||    EXIT    ||            |+------------+"} 
    },* btn = buttons;

    buttons[0].SelectButton();
    DrawMenu(btn,3);
    SimpleMenu(btn);
}
