#include "Imagem.h"

Pixel& Imagem::operator()(int x, int y){
    return pixels[x*y + y];
};