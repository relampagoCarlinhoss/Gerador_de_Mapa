#pragma once
#include <vector>
#include <string>
#include "Cor.h"

class Paleta {
    std::vector<Cor> paleta;
    int tamanho = 0; 
    
public:
    //construtores
    Paleta() { tamanho = 0; }
    Paleta(const std::string& nomeArquivo); 
    
    //metodos
    void adicionarCor(Cor cor); 
    int consultarTamanho();
    Cor consultarCor(int indice); 
};