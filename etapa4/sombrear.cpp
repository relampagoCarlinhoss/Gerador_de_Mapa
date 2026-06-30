#include "../etapa3/Terreno.h"

void sombrear(int** ter){
    for(int i = 8; i >= 0; i--){
        for(int j = 8; j >= 0; j--){
            
            if(i == 0 || j == 0){continue;}    
            
            if(ter[i - 1][j - 1] > ter[i][j]){
                ter[i][j] /= 2;
            }
        }
    }
}

int main(){
    Terreno ter;
    ter.geradorDeMapa(9,0.5);
    std::cout << ter.consultarAltitude(4,4) << " \n";
    ter.salvarTerreno("arquivoSombreado");
    
    int** matriz = new int*[9];

    for(int i = 0; i < 9; i++){
        matriz[i] = new int[9];
        for(int j = 0; j < 9; j++){
            matriz[i][j] = ter.consultarAltitude(i,j);
        }
    }

    sombrear(matriz);

    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
           std::cout << matriz[i][j] << " ";
    }
        std::cout << "\n";
}

}