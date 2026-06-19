#pragma once
#include "Cor.h"
#include <string>
#pragma once

Cor converterRGB(std::string hexa){
    Cor cor; 
    for(int i = 2; i < 7; i = i+ 2){
        int primeiro, segundo;
        int rgb;

        if(hexa[i - 1] < 47 || hexa[i - 1] > 57){
            primeiro = hexa[i - 1] - 87;    
        }
        
        else{
            primeiro = hexa[i - 1] - '0';
        }
        
        if(hexa[i] < 47 || hexa[i] >57){
            segundo  = hexa[i] - 87; 
        }

        else{
            segundo = hexa[i] - '0';
        }
        
        rgb = primeiro*16 + segundo;
        
        if(i == 2){cor.r = rgb;}
        if(i == 4){cor.g = rgb;}
        if(i == 6){cor.b = rgb;}
    }

}