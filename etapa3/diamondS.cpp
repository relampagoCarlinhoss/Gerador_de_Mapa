#include <bits/stdc++.h>
#include <cstdlib>
#include <ctime>
    
    int tamMax;
    int max = 20, min = 0;

    //gerar numero aleatorio de incremento/ decremento
    int gerarNmr(int min, int max){
        return (rand() %(max - min + 1)) + min;
    }

    //preenchimento dos pontos no centro
    void square(int** matriz,int tamanho){
        //para conseguir o centro
        int metade = tamanho/2;
        
        //considerando os centro "simetricos" nos movimentamos por ele pelo for encadeado
        for(int i = metade; i <= tamMax; i += tamanho){
             for(int j = metade; j <= tamMax; j += tamanho){
                matriz[i][j] = ((matriz[i - metade][j - metade]
                                + matriz[i - metade][j + metade] 
                                + matriz[i + metade][j + metade] 
                                + matriz[i + metade][j - metade])/4) + gerarNmr(min, max);                    
            }
        }
    }

    //preenchimentos dos pontos ortogonais as arestas
    void diamond(int** matriz, int tamanho){
        int metade = tamanho/2;
        
        for(int i = 0; i <= tamMax; i += metade){
            
            //para cada etapa ele confere se o preenchimento é  desde o inicio ou nao 
            int imParj = ((i/metade) % 2 == 0) ? metade: 0; 
            
            //como a matriz é "simetrica" o incremente de tamanho me leva até outro centro da matriz
            for(int j = imParj; j <= tamMax; j += tamanho){
                int soma = 0, pontos = 0;

                if(i - metade >= 0){ 
                    soma += matriz[i - metade][j];
                    pontos++;
                }

                if(i + metade <= tamMax){
                    soma += matriz[i + metade][j];
                    pontos++;
                }

                if(j - metade >= 0){
                    soma += matriz[i][j - metade];
                    pontos++;
                }
                
                if(j + metade <= tamMax){
                    soma += matriz[i][j + metade];
                    pontos++;
                }

                matriz[i][j] = (soma + gerarNmr(min, max))/pontos;
            }
        }       
    }
    
    void diamondSquare(int** matriz,int tamanho, int rugosidade){
        if(tamanho < 2){
            return;
        }
            square(matriz, tamanho);
            diamond(matriz, tamanho);
            
            min *=rugosidade;
            max *= rugosidade;
            return diamondSquare(matriz, tamanho/2, rugosidade);
        
    }

    void gerarMatriz(){
        //incializalização de variaveis
        srand(time(0));
        int linha, coluna, rugosidade;
        
        //linha, coluna e tamMax(para registrar)
        std::cin >> linha;
        std:: cin >> rugosidade;
        coluna = linha;
        tamMax = linha  - 1;
    
        //criação da matriz
        int** matriz;
        matriz = new int*[linha];
         
        //preenchimento das bordas com limite superior e inferior. 
        for(int i = 0; i < linha; i++){
            matriz[i] = new int [coluna];
            for(int j = 0; j < linha; j++){
                matriz[i][j] = 0;
                
                if(i == 0 && (j == 0 || j == coluna - 1)){
                    matriz[i][j] = gerarNmr(min, max);
                }

                if(i == linha -1 && (j == 0 ||j == coluna -1)){
                    matriz[i][j] = gerarNmr(min, max);
                }
            }
        }

        //chamar algoritimo 
        diamondSquare(matriz, linha - 1, rugosidade);

        //imprimir matriz
        for(int i = 0; i < linha; i++){
                for(int j = 0; j < coluna; j++){
                    std::cout <<  matriz[i][j]<< " ";
                }
                std::cout << "\n";
            }
        }
