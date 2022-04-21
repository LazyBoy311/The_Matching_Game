#pragma once
#include<string>
#include <bits/stdc++.h>

struct Button{
    std::string box= "+-----------+|           ||           ||           |+-----------+" ;

    Button()
    {
        box= "+-----------+|           ||           ||           |+-----------+" ;
    }

    Button(std::string str)
    {
        box= str;
    }

    void SelectButton()
    {
        for(int i = 0;i < box.length();i++)
        {
            if(box[i] == ' ')
            {
                box[i] =  (char)219u;
            }
        }
    }

    void DeSelectButton()
    {
        for(int i = 0;i < box.length();i++)
        {
            if(box[i] == (char)219u)
            {
                box[i] =  ' ';
            }
        }
    }
};
