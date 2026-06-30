#include "Terreno.h"

int main(){
    Terreno ter;
    Terreno ter1;
    ter.geradorDeMapa(9, 0.5);
    ter.salvarTerreno("TerrenoTesteS2");
    std:: cout << ter.consultarAltitude(2,2) << " \n";
    
    std:: cout << ter1.lerTerreno("TerrenoTeste1");
    ter1.salvarTerreno("T_teste1");

    std::cout << ter.consultarLinha() << "\n";
    std::cout << ter.consultarColuna() << "\n";
}