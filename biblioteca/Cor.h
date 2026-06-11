#include <iostream> 

class Cor{
    int r;
    int g;
    int b;
        
    public: 
    //construtores
    Cor(int r = -1, int g = -1, int b = -1): r(r % 256), g(g % 256), b(b % 256){}

    //Get
    int getR(){return r;}
    int getG(){return g;}
    int getB(){return b;}  

    //Set        
    void setR(int rP){r = rP;}
    void setG(int gP){g = gP;}
    void setB(int bP){b = bP;}

};

