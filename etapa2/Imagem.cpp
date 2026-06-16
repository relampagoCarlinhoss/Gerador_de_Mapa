#pragma once
#include "Imagem.h"
#include <iostream>
#include <fstream>

Pixel& Imagem::operator()(int x, int y){
    return pixels[y][x];
};

const Pixel& Imagem::operator()(int x, int y) const{
    return pixels[y][x];
}

//Métodos
bool Imagem::lerPPM(const std::string &nomeArquivo){
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        return false;
    }

    std::string formato;
    int l, a, maxValor;
    arquivo >> formato >> l >> a >> maxValor;

    if (formato != "P3" || maxValor != 255) {
        return false;
    }

    if (pixels != nullptr) {
        for (int i = 0; i < altura; i++) {
            delete[] pixels[i];
        }
        delete[] pixels;
    }

    largura = l;
    altura = a;

    pixels = new Pixel*[altura];
    for (int i = 0; i < altura; ++i) {
        pixels[i] = new Pixel[largura];
        for (int j = 0; j < largura; ++j) {
            int r, g, b;
            arquivo >> r >> g >> b;
            pixels[i][j] = {r, g, b};
        }
    }

    return true;
}

bool Imagem::salvarPPM(const std::string &nomeArquivo){
    std::ofstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
        return false;
    }

    arquivo << "P3\n" << largura << " " << altura << "\n255\n";
    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < largura; ++j) {
            Pixel& p = pixels[i][j];
            arquivo << p.r << " " << p.g << " " << p.b << std::endl;
        }
    }

    return true;
}