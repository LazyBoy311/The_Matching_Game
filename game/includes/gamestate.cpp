#include "gamestate.h"

using namespace std;
void PlayGame(int R,int C)
{
    Point** ptr;
    int turn = (R*C)/2 - 5;
	int Time = time(NULL);
    int crX = 0, crY =0;
    Point *p1 = nullptr,*p2 =nullptr;
    CreateGrid(R,C,ptr);
    GenerateValue(R,C,ptr);
    DrawGrid(R,C,ptr,&crX,&crY);
    SelectValue(R,C,ptr,&crX,&crY,turn,Time);
}

void CreateGrid(int R,int C,Point **&ptr)
{
    ptr = new Point*[R];
    for(int i = 0;i < R;i++)
    {
        
       *(ptr+i) = new Point[C]; 
    }

    for(int i = 0; i < R;i++)
    {
        for(int j = 0; j < C;j++)
        {
            Point p(i,j,0);
            ptr[i][j] = p;
            GenerateGraphic(ptr[i][j]);
        }
    }
}

void GenerateValue(int &R,int &C,Point **&ptr)
{

    for(int i = 1;i <=(int)(R*C)/2 - 5;i++)
    {
        int randomX = rand() %R;
        int randomY = rand() %C;
        bool complete_Assign = false;
        while(!complete_Assign)
        {
            if(ptr[randomX][randomY].value == 0)
            {
                ptr[randomX][randomY].value = i;
                ptr[randomX][randomY].UpdateBox(i);
                while(ptr[randomX][randomY].value != 0)
                {
                    randomX = rand() %R;
                    randomY = rand() %C;
                }
                ptr[randomX][randomY].value = i;
                ptr[randomX][randomY].UpdateBox(i);
                complete_Assign = true;
            }else{
                randomX = rand() %R;
                randomY = rand() %C;
            }
        }
    }

}

void DrawGrid(int R,int C,Point **ptr,int *currentX,int *currentY)
{
    //system("cls");
    int Row = 1;
    for(int z=0;z < R ;z++)
    { 
    //Create One Row 
        for(int k =0;k<5;k++){
            gotoxy(10,Row);
            Row++;
            for(int j = 0;j < C;++j){
                if(ptr[z][j].value == 0)
                {
                    if(j == *currentX && z == *currentY){
                        cout << (char)219u <<(char)219u<<(char)219u<<(char)219u<<(char)219u<<(char)219u<<(char)219u<<(char)219u;
                    }else{
                        cout << ptr[z][j].graph.layer[k];
                	}
                }else {
                    if(ptr[z][j].isSelected) {
                        if(k == 0){
                            cout << (char)218u <<(char)196u<<(char)196u<<(char)196u<<(char)196u<<(char)196u<<(char)196u<<(char)191u;
                        }else if(k == 4){
                            cout << (char)192u<<(char)196u<<(char)196u<<(char)196u<<(char)196u<<(char)196u<<(char)196u<<(char)217u;
                        }
                        else if(k == 2){
                            if(ptr[z][j].value >=10 &&  ptr[z][j].value != 0){
                                cout << (char)179u <<(char)219u<<(char)219u<<  ptr[z][j].value <<(char)219u<<(char)219u<<(char)179u;
                            }else {
                                cout << (char)179u <<(char)219u<<(char)219u<< "0"<<ptr[z][j].value<<(char)219u<<(char)219u<<(char)179u;
                            }
                        }else if(k < 4){
                            cout <<(char)179u <<(char)219u<<(char)219u<<(char)219u<< (char)219u<<(char)219u<<(char)219u<<(char)179u;
                        }
                    }else if(j == *currentX && z == *currentY){
                        if(k == 0){
                            cout << (char)218u <<(char)196u<<(char)196u<<(char)196u<<(char)196u<<(char)196u<<(char)196u<<(char)191u;
                        }else if(k == 4){
                            cout << (char)192u<<(char)196u<<(char)196u<<(char)196u<<(char)196u<<(char)196u<<(char)196u<<(char)217u;
                        }
                        else if(k == 2){
                            if(ptr[z][j].value >=10 &&  ptr[z][j].value != 0){
                                cout << (char)179u <<(char )219u<<(char)219u<<  ptr[z][j].value <<(char)219u<<(char)219u<<(char)179u;
                            }else {
                                cout << (char)179u <<(char)219u<<(char)219u<< "0" <<ptr[z][j].value <<(char)219u<<(char)219u<<(char)179u;
                            }
                        }else if(k < 4){
                            cout << (char)179u <<(char)219u<<(char)219u <<(char)219u<<(char)219u<<(char)219u<<(char)219u<<(char)179u;
                        }
                    }else {
                        if(k == 0){
                            cout << (char)218u <<(char)196u<<(char)196u<<(char)196u<<(char)196u<<(char)196u<<(char)196u<<(char)191u;
                        }else if(k == 4){
                            cout << (char)192u<<(char)196u<<(char)196u<<(char)196u<<(char)196u<<(char)196u<<(char)196u<<(char)217u;
                        }
                        else if(k == 2){
                            if(ptr[z][j].value >=10 &&  ptr[z][j].value != 0){
                                cout << (char)179u <<"  " <<  ptr[z][j].value <<"  "<<(char)179u;
                            }else {
                                cout << (char)179u<<"  " << "0" <<ptr[z][j].value <<"  "<<(char)179u;
                            }
                        }else if(k < 4){
                            cout << (char)179u<<"      "<<(char)179u;
                        }
                    }
                }
            }  
            cout << '\n';
            gotoxy(10,Row);
        }
        
    }   
	cout << "press Tab to view suggestion" << endl;
    
}

void SelectValue(int R,int C,Point **&ptr,int *currentX,int *currentY,int &turn, int Time)
{
    int c = 0;
    Point values[2];
    int numberItemSelected = 0;
    while(c != 27 && turn > 0)
    {
        c = 0;
        switch(c= getch()) {
            case 72:
                if(*currentY > 0){
                    --(*currentY);//key up
                }
                break;
            case 80:
                if(*currentY < R-1){
                    ++(*currentY); // key down
                }
                break;
            case 75:
                if(*currentX > 0){
                    --(*currentX);// key left
                }
                break;
            case 77:
                if(*currentX < C-1){
                    ++(*currentX);// key right
                }
                break;
            case 32:              // key space
                if(numberItemSelected == 0 && ptr[*currentY][*currentX].value != 0)
                {
                    values[numberItemSelected] = ptr[*currentY][*currentX];
                    if (values[0].x == values[1].x && values[0].y == values[1].y) continue;
                    numberItemSelected++;
                    ptr[*currentY][*currentX].isSelected = true;
                    ptr[*currentY][*currentX].SelectedBox();
                }else if(numberItemSelected >= 1) {
                    values[numberItemSelected] = ptr[*currentY][*currentX];
                    ptr[*currentY][*currentX].isSelected = true;
                    ptr[*currentY][*currentX].SelectedBox();
                    if(values[0].value == values[1].value && values[1].value != 0 && (values[0].x != values[1].x || values[0].y != values[1].y ) )
                    {
                        if (checkMatching(R, C, ptr, values[1], values[0])) {
                            ptr[values[0].x][values[0].y].value = 0;
                            ptr[values[1].x][values[1].y].value = 0;
                            ptr[values[0].x][values[0].y].DeSelected();
                            ptr[values[1].x][values[1].y].DeSelected();
                            turn--;
                            if (!checkAvailable(R, C, ptr) && turn != 0) //Chekc còn đường đi
                                resetValue(R, C, ptr);
                        }
                        else {
                            ptr[values[0].x][values[0].y].DeSelected();
                            ptr[values[1].x][values[1].y].DeSelected();
                        }

                    }else {
                        ptr[values[0].x][values[0].y].DeSelected();
                        ptr[values[1].x][values[1].y].DeSelected();
                        
                    }

                    ptr[values[0].x][values[0].y].isSelected = false;
                    ptr[values[1].x][values[1].y].isSelected = false;
                    numberItemSelected = 0;
                }
                
                break;
            case 9:
            	SuggestMove(R, C, ptr);
            	break;
            case 27:
                return;
                break;
        }
        DrawGrid(R, C, ptr,currentX,currentY);
    }
    EndGame(time(NULL) - Time);
}

