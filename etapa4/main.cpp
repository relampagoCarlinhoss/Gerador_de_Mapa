#include <iostream>
#include <string>
#include <cmath>
#include "../etapa1/Paleta.h"
#include "../etapa2/Imagem.h"
#include "../etapa3/Terreno.h"

int main() {
    std::string arquivoCores;
    std::string arquivoSaida;
    int n;
    double rugosidade;

    std::cout << "Diga o nome do arquivo das cores (cores.hex): ";
    std::cin >> arquivoCores;
    std::cout << "Diga o tamanho(n): ";
    std::cin >> n;
    std::cout << "Digite o fator de rugosidade: ";
    std::cin >> rugosidade;
    std::cout << "Digite o nome do arquivo para saída com .ppm (ex:a.ppm): ";
    std::cin >> arquivoSaida;

    Paleta paleta(arquivoCores); 
    Terreno terreno;

    std::cout << "Renderizando o mapa..." << std::endl;

    terreno.gerarMapadeCores(paleta, arquivoSaida, n, rugosidade, 0.7);

    std::cout << "Deu certo "<< std::endl;

    return 0;
}