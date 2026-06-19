#pragma once
#include "./Pixel.h"
#include <string>
#include "fstream"

class Imagem{
    int largura; 
    int altura;
    Pixel** pixels;
    public:

    //construtores
    Imagem(){
        largura = 0;
        altura = 0;
        pixels = nullptr;
    }

    Imagem(int l, int a) {
        largura = l;
        altura = a; 
        pixels = new Pixel*[altura];
        for (int i = 0; i < altura; i++) {
            pixels[i] = new Pixel[largura];
        }
    }

    //destrutor
    ~Imagem() {
        for (int i = 0; i < altura; i++) {
            delete[] pixels[i]; 
        }
        delete[] pixels;
    }

    //get:
    int consultarLargura(){return largura;}
    int consultarAltura(){return altura;}
    
    //metodos
    bool lerPPM(const std::string &nomeArquivo);
    bool salvarPPM(const std::string &nomeArquivo);

    //operador
    //Pixel& operator()(int x, int y);
    Pixel& operator()(int x, int y);

};


