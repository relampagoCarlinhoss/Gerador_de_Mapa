#include <bits/stdc++.h>
#include "Cor.h";

class PaletaCor{
    std::vector<Cor> paleta;

    public:

    //construtores
    PaletaCor(){paleta.push_back({});}
    PaletaCor(std::ifstream arquivo){
        std::string hexa;

        if(arquivo.is_open()){
            while(std::getline(arquivo, hexa)){    
                paleta.push_back(converterRGB(hexa)); 
            }
            arquivo.close();
        }
    }

    //operações
    void adicionarCor(Cor cor){
        paleta.push_back(cor);
    }

    int consultarNmrCores(){return paleta.size();}


};