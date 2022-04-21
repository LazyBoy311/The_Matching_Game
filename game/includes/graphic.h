#pragma once
#include<string>

struct Graphic
{
    std::string layer[5];
    Graphic()
    {
        layer[0] = "        ";
        layer[1] = "        ";
        layer[2] = "        ";
        layer[4] = "        ";
    }
    Graphic(std::string layer1,std::string layer2,std::string layer3,std::string layer4,std::string layer5)
    {
        layer[0] = layer1;
        layer[1] = layer2;
        layer[2] = layer3;
        layer[3] = layer4;
        layer[4] = layer5;
    }
};

