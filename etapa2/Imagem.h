#pragma once
#include "./Pixel.h"

class Imagem{
    int largura; 
    int altura;
    Pixel *pixels;

    public:
    //construtores
    Imagem(){
        largura = 0;
        altura = 0;
        pixels = nullptr;
    }

    Imagem(int larguraP, int alturaP){
        larguraP = largura;
        alturaP = altura;
        pixels = new Pixel[largura*altura];
    } 

    //destrutor
    ~Imagem(){delete[]pixels;}

    //get e set:
    int consultarLargura(){return largura;}
    int consultarAltura(){return altura;}
    
    //metodos
    bool lerPPM(const std::string &nomeArquivo);
    bool salvarPPM(const std::string &nomeArquivo);

    //operador
    Pixel& operator()(int x, int y);
};


