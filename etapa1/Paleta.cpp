#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Cor.h"
#include "Paleta.h"

Cor conversorRGB(std::string h){
    Cor cor;
    std::vector<int> v;

    for(int i = 1; i < 7; i++){
        if(h[i] > 47 && h[i] < 58){
            int n = h[i] - '0'; 
            v.push_back(n);
        } else {
            int n = h[i] - 'a' + 10;  
            v.push_back(n); 
        }
    }

    cor.r = v[0] * 16 + v[1];
    cor.g = v[2] * 16 + v[3];
    cor.b = v[4] * 16 + v[5];

    return cor;
}

Paleta::Paleta(const std::string& nome_arquivo){
    tamanho = 0;
    std::ifstream arquivo(nome_arquivo);
    
    std::string hexa;
    if(arquivo.is_open()){
        while(std::getline(arquivo, hexa)){    
            paleta.push_back(conversorRGB(hexa));
            tamanho = paleta.size();
        }
        arquivo.close();
    }
}

void Paleta::adicionarCor(Cor cor){
    paleta.push_back(cor);
    tamanho = paleta.size();
}

int Paleta::consultarTamanho(){ return tamanho; }

Cor Paleta::consultarCor(int indice){
    if (indice < 0 || indice >= tamanho) {
        return Cor{0, 0, 0}; 
    }
    return paleta[indice]; 
}