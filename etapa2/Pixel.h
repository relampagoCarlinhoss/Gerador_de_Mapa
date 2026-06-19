#pragma once
#include "../etapa1/Cor.h"

class Pixel{
   public:
      int r, g, b;

     //construtor
      Pixel(int rP = 0, int gP = 0, int bP = 0):r(rP), g(gP), b(bP){} 
      Pixel(Cor corP){
        r = corP.r;
        g = corP.g;
        b = corP.b;
     }
};