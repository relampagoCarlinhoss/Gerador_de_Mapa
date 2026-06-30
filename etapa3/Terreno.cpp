#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib> 
#include <ctime> 
#include "Terreno.h"

    Terreno::Terreno() {
        n = 0;
        rugosidade = 0.0;
        terreno = nullptr;
    }

    Terreno::Terreno(int numero, double r) {
        n = numero;
        rugosidade = r;
        terreno = new int*[n];
        for (int i = 0; i < n; i++) {
            terreno[i] = new int[n];
            for (int j = 0; j < n; j++) {
                terreno[i][j] = 0.0;
            }
        }
    }

    Terreno::~Terreno() {
        if (terreno != nullptr) {
            for (int i = 0; i < n; i++) {
                delete[] terreno[i];
            }
        delete[] terreno;
        terreno = nullptr;
        }
    }

    //gerar numero aleatorio de incremento/ decremento
    int Terreno::gerarNmr(int min, int max){
        return (rand() %(max - min + 1)) + min;
    }

    //preenchimento dos pontos no centro
    void Terreno::square(int tamanho){
        //para conseguir o centro
        int metade = tamanho/2;
        
        //considerando os centro "simetricos" nos movimentamos por ele pelo for encadeado
        for(int i = metade; i < n; i += tamanho){
             for(int j = metade; j < n; j += tamanho){
                terreno[i][j] = ((terreno[i - metade][j - metade]
                                + terreno[i - metade][j + metade] 
                                + terreno[i + metade][j + metade] 
                                + terreno[i + metade][j - metade])/4.0) + gerarNmr(min, max);                    
            }
        }
    }

    //preenchimentos dos pontos ortogonais as arestas
    void Terreno::diamond (int tamanho){
        int metade = tamanho/2;
        
        for(int i = 0; i < n; i += metade){
            
            //para cada etapa ele confere se o preenchimento é  desde o inicio ou nao 
            int imParj = ((i/metade) % 2 == 0) ? metade: 0; 
            
            //como a terreno é "simetrica" o incremente de tamanho me leva até outro centro da terreno
            for(int j = imParj; j < n; j += tamanho){
                double soma = 0, pontos = 0;

                if(i - metade >= 0){ 
                    soma += terreno[i - metade][j];
                    pontos++;
                }

                if(i + metade < n){
                    soma += terreno[i + metade][j];
                    pontos++;
                }

                if(j - metade >= 0){
                    soma += terreno[i][j - metade];
                    pontos++;
                }
                
                if(j + metade < n){
                    soma += terreno[i][j + metade];
                    pontos++;
                }

                if(pontos > 0){
                    terreno[i][j] = (soma + gerarNmr(min, max))/pontos;
                }
            }
        }       
    }
    
    void Terreno::diamondSquare(int tamanho, double r){
        if(tamanho < 2){
            return;
        }
            square(tamanho);
            diamond(tamanho);
            
            min *=r;
            max *= r;
            return diamondSquare(tamanho/2, r/2);
        
    }

    void Terreno::geradorDeMapa(int tamTerreno, double r){
        //incializalização de variaveis
        srand(time(0));
        
        n = tamTerreno;
        rugosidade= r;
        max=20;
        min =0; 
    
        if (terreno != nullptr) {
            for (int i = 0; i < n; i++) {
                delete[] terreno[i];
            }
            delete[] terreno;
        }
         
        //preenchimento das bordas com limite superior e inferior. 
        terreno = new int*[n]; 
        for(int i = 0; i < n; i++){
            terreno[i] = new int [n];
            for(int j = 0; j < n; j++){
                terreno[i][j] = 0.0;
            }
        }

        terreno[0][0] = gerarNmr(min, max);
        terreno[0][n - 1] = gerarNmr(min, max);
        terreno[n - 1][0] = gerarNmr(min, max);
        terreno[n - 1][n - 1] = gerarNmr(min, max);
    
        diamondSquare(n - 1, rugosidade);
    }

    int Terreno::consultarColuna(){
        return n; 
    }
    int Terreno::consultarLinha(){
        return n; 
    }

    int Terreno::consultarAltitude(int l, int c){
            return terreno[l][c]; 
    }

    bool Terreno::salvarTerreno(const std::string &nomeArquivo){
        std::ofstream arquivo(nomeArquivo);
        if (!arquivo.is_open()) {
            return false;
        }

        arquivo << n << "\n"; 
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                arquivo << terreno[i][j] << " ";
            }
            arquivo << "\n"; 
        }
        arquivo.close(); 
        return true;
    
    }

    bool Terreno::lerTerreno(const std::string &nomeArquivo){
        std::ifstream arquivo(nomeArquivo);

        if (!arquivo.is_open()) {
            return false;
        }

        int novoN;
        arquivo >> novoN; 

        if (terreno != nullptr) {
            for (int i = 0; i < n; i++) {
                delete[] terreno[i];
            }
            delete[] terreno;
        }

        n = novoN;
        terreno = new int*[n];
        for (int i = 0; i < n; ++i) {
            terreno[i] = new int[n];
                for (int j = 0; j < n; j++) {
                    arquivo >> terreno[i][j]; 
                }
        }
        arquivo.close();
        return true;
    }




