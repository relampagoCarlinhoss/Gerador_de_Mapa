#include "Cor.h"
#include <string>

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
        
        if(i == 2){cor.setR(rgb);}
        if(i == 4){cor.setG(rgb);}
        if(i == 6){cor.setB(rgb);}
    }

}

std::string converterHexa(Cor cor){
    std::string hexa = "#";
    
    cor.getR() >  ?(hexa.push_back(std::to_string(cor.getR()/ 16));
    hexa.push_back(cor.getR() % 16);
    
    hexa.push_back(cor.getG() / 16);
    hexa.push_back(cor.getG() % 16);
    
    hexa.push_back(cor.getB() / 16);
    hexa.push_back(cor.getB() % 16);

    for
}