#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>
using namespace std;

class Fecha{
    private:
        int dia, mes, anio;
    public:
        Fecha(int d, int m, int a){
            this->dia=d;
            this->mes=m;
            this->anio=a;
        }
        void mostrarFecha(){
        cout<<this->dia<<"/"<<this->mes<<"/"<<this->anio<<"/"<<endl;
        }
};

#endif // FECHA_H_INCLUDED
