#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Terreno {

    int n;
    double rugosidade; 
    int **terreno; 
    int max = 20, min = 0; 

    int gerarNmr(int min, int max);
    void square(int tamanho);
    void diamond(int tamanho);
    void diamondSquare(int tamanho, double r);

    public:
    Terreno();
    Terreno(int numero, double r);
    ~Terreno();

    void geradorDeMapa(int tamTerreno, double r);
    int consultarColuna();
    int consultarLinha();
    int consultarAltitude(int l, int c);
    bool salvarTerreno(const std::string &nomeArquivo);
    bool lerTerreno(const std::string &nomeArquivo); 
};
