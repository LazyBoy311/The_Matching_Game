#pragma once
#include"graphic.h"

struct Point{
    
    int value;
    int x;
    int y;
    bool isSelected; 
    Graphic graph;
    
    Point()
    {
        int x;
        int y;
        int value = 0;
        bool isSelected = false;
    }

    Point(int defX,int defY,int defValue)
    {
        x = defX;
        y = defY;
        value = defValue;
        isSelected = false;
    }
        
    void UpdateBox(int newvalue)
    {    
        value = newvalue; 
    }

    void SelectedBox()
    {
        isSelected = true;
    }

    void DeSelected()
    {
        isSelected = false;
    }
    // có thể dùng để Chỉnh hình ảnh sau khi ô bị biến mất 
};
