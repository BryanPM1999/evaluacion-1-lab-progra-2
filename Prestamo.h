#ifndef PRESTAMO_H_INCLUDED
#define PRESTAMO_H_INCLUDED
#include "Cliente.h"
#include "Pago.h"
#define TAM 10

class Prestamo{
    private:
        int numeroPrestamo;
        Cliente *cliente;
        Fecha *fechaAprobacion;
        float montoAprobado;
        Pago *lstPagos[TAM];
        float saldoPendiente;
        int contadorPago;
    public:
        Prestamo(){
            this->numeroPrestamo=0;
            this->montoAprobado=0;
            this->saldoPendiente=0;
            this->contadorPago=0;
        }
        Prestamo(int nP, Cliente *cli, Fecha *fa, float mA){
            this->numeroPrestamo=nP;
            this->cliente=cli;
            this->fechaAprobacion=fa;
            this->montoAprobado=mA;
            this->saldoPendiente=mA;
            this->contadorPago=0;
        }
        int getNumeroPrestamo(){
            return this->numeroPrestamo;
        }
        void setNumeroPrestamo(int NP){
            this->numeroPrestamo=NP;
        }
        Cliente *getCliente(){
            return this->cliente;
        }
        void setCliente(Cliente *cli){
            this->cliente=cli;
        }
        void setFechaAprobacion(Fecha *fa){
            this->fechaAprobacion=fa;
        }
        Fecha *getFechaAprobacion(){
            return this->fechaAprobacion;
        }
        void setMontoAprobado(float MP){
            this->montoAprobado=MP;
        }
        float getMontoAprobado(){
            return this->montoAprobado;
        }
        bool hacerPago(Pago *pa){
            bool retorno=false;
            if (this->contadorPago<TAM){
                this->lstPagos[this->contadorPago]=pa;
                this->contadorPago++;
                this->saldoPendiente -=pa->getMontoPago();
                retorno=true;
            }
            return retorno;
        }
        Pago **getLstPago(){
            return this->lstPagos;
        }
        float getSaldoPendiente(){
            return this->saldoPendiente;
        }
        int getContadorPagos(){
            return this->contadorPago;
        }
};

#endif // PRESTAMO_H_INCLUDED
