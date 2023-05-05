#include <iostream>

class ember{
protected:
    char* nev;
    int magassag;
    int fizetes;
    int szuletes;
public:
    void setEmber(char* nev, int magassag, int fizetes, int szuletes){
        this->nev=nev;
        this->magassag=magassag;
        this->fizetes=fizetes;
        this->szuletes=szuletes;
    }
    void getEmber(char* nev, int* magassag, int* fizetes, int* szuletes){
        nev=this->nev;
        magassag=&this->magassag;
        fizetes=&this->fizetes;
        szuletes=&this->szuletes;
    }
    int getFizetes(){
        return this->fizetes;
    }
    void fizetesemeles(int szazalek){
        this->fizetes= this->fizetes*((100+szazalek)/100);
    }
};

int main() {
    ember Sanyi;
    ember Bela;
    Sanyi.setEmber("Sanyi",170,1000000, 20030211);
    Bela.setEmber("Bela",143,10000000, 20030201);
    Sanyi.fizetesemeles(20);
    std::cout<<"Sanyi fizetése:"<<Sanyi.getFizetes()<<std::endl;

    return 0;
}
