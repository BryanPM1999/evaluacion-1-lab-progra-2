#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <string>
using namespace std;

class Cliente{
    private:
        int idCliente;
        string nombre, apellido;
    public:
        Cliente(int id, string n, string a){
            this->idCliente=id;
            this->nombre=n;
            this->apellido=a;
        }
        int getCliente(){
            return this->idCliente;
        }
        string getNombre(){
            return this->nombre;
        }
        string getApellido(){
            return this->apellido;
        }
};

#endif // CLIENTE_H_INCLUDED
