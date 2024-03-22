#include <iostream>
using namespace std;
#include <stdlib.h>
#include "Cliente.h"
#include "Prestamo.h"
#define TM 10

int menu(){
    int op;
    cout<<"MENU DE OPCIONES\n";
    cout<<"1. Agregar clientes a la lista.\n";
    cout<<"2. Agregar prestamo a la lista.\n";
    cout<<"3. Hacer pagos de prestamos\n";
    cout<<"4. Mostrar lista de clientes\n";
    cout<<"5. Mostrar lista de prestamos\n";
    cout<<"6. Mostrar detalles del prestamo\n";
    cout<<"7. Salir \n";
    cout<<"Digite una opcion: ";
    cin>>op;
    return op;
}

Cliente *BuscarCliente(Cliente *lst[], int cont, int db){
    bool encontrado=false;
    int contar=0;
    Cliente *cli=NULL;
    while (contar<cont && !encontrado){
        if (lst[contar]->getCliente() == db){
            encontrado = true;
            cli=lst[contar];
        }
        else{
            contar++;
        }
    }
    return cli;
}

Prestamo *BuscarPrestamo(Prestamo *lst[], int cont, int db){
    bool encontrado = false;
    int contar=0;
    Prestamo *pM=NULL;
    while (contar<cont && !encontrado){
        if (lst[contar]->getNumeroPrestamo() == db){
            encontrado = true;
            pM=lst[contar];
        }
        else{
            contar++;
        }
    }
    return pM;
}

Cliente *agregarCliente(){
    int id;
    string n,a;
    Cliente *cli;
    cout<<"Cree un id del cliente: ";
    cin>>id;
    cout<<"Digite el nombre del cliente: ";
    cin>>n;
    cout<<"Digite el apellido del cliente: ";
    cin>>a;
    cli=new Cliente(id, n,a);
    return cli;
}
Prestamo *agregarPrestamo(Cliente *cli){
    int np;
    int d, m, a;
    Fecha *fa;
    float ma;
    Prestamo *ptO;
    cout<<"Cree un codigo del prestamo: ";
    cin>>np;
    cout<<"Digite el dia de aprobacion: ";
    cin>>d;
    cout<<"Digite el mes de aprobacion: ";
    cin>>m;
    cout<<"Digite el anio de aprobacion: ";
    cin>>a;
    fa = new Fecha(d,m,a);
    cout<<"Digite el monto que se aprobara: ";
    cin>>ma;
    ptO=new Prestamo(np, cli, fa, ma);
    return ptO;
}

void registrarPago(Prestamo *_Prestamo){
    int d, m, a;
    Fecha *fp;
    float mp;
    Pago *Pag;
    cout<<"Digite el dia del pago: ";
    cin>>d;
    cout<<"\nDigite el mes: ";
    cin>>m;
    cout<<"\nDigite el anio: ";
    cin>>a;
    cout<<"\nDigite el monto a pagar: ";
    cin>>mp;
    fp=new Fecha(d, m, a);
    Pag=new Pago(fp, mp);
    _Prestamo->hacerPago(Pag);
}
void verDetalles(Prestamo *prtmo){
    cout<<"Codigo: " << prtmo->getNumeroPrestamo()<<endl;
    cout<<"Cliente: " << prtmo->getCliente()->getNombre() << " " << prtmo->getCliente()->getApellido() << endl;
    cout<<"Fecha Aprobacion: ";
    prtmo->getFechaAprobacion()->mostrarFecha();
    cout<<"Monto aprobado: " << prtmo->getMontoAprobado()<<endl;
    cout<<"Saldo pendiente: " << prtmo->getSaldoPendiente()<< endl;
    if (prtmo->getContadorPagos() == 0){
        cout<<"No tiene pagos registrados\n";
    }
    else{
        Pago **lista = prtmo->getLstPago();
        cout<<"No\tFecha\tMonto\n";
        for (int i=0; i<prtmo->getContadorPagos();i++){
            cout<<(i+1) << "\t";
            lista[i]->getFechaPago()->mostrarFecha();
            cout<< "\t" << lista[i]->getMontoPago()<< endl;
        }
    }
}
int main()
{
    Cliente *listCliente[TM];
    Prestamo *listPrestamo[TM];
    Cliente *clien=NULL;
    Prestamo *presta=NULL;
    int opc, contPrestamo=0, contCliente=0, idCli, idPres;
    do{
        system("cls");
        opc = menu();
        switch(opc){
            case 1:///Agregar clientes a la lista
                if(contCliente<TM){
                    listCliente[contCliente]=agregarCliente();
                    contCliente++;
                }
                else{
                    cout<<"La lista esta llena\n";
                }
                break;
            case 2:///Agregar préstamo a la lista.
                if(contPrestamo<TM){
                    cout<<"Digite el id del cliente: ";
                    cin>>idCli;
                    clien = BuscarCliente(listCliente, contCliente, idCli);
                    if(clien){
                        listPrestamo[contPrestamo] = agregarPrestamo(clien);
                        contPrestamo++;
                        cout<<"El prestamo se registro con exito\n";
                    }
                    else{
                        cout<<"El cliente no existe, no se puede agregar el prestamo";
                    }
                }
                else{
                    cout<<"La lista esta llena\n";
                }
                break;
            case 3:///Hacer pagos de préstamos
            {
                cout<<"Digite el codigo de prestamo: \n";
                cin>>idPres;
                presta=BuscarPrestamo(listPrestamo, contPrestamo, idPres);
                if(presta){
                    registrarPago(presta);
                    cout<<"El pago se registro con exito\n";
                }
                else{
                    cout<<"El prestamo no existe\n";
                }
            }
                break;
            case 4:///Mostrar lista de clientes
                if (contCliente == 0){
                    cout<<"La lista esta vacia\n";
                }
                else{
                    cout<< "Id\tNombre\tApellido\n";
                    for (int i=0;i<contCliente;i++){
                        cout<<listCliente[i]->getCliente() << "\t";
                        cout<<listCliente[i]->getNombre() << "\t";
                        cout<<listCliente[i]->getApellido() << "\n";
                    }
                }
                break;
            case 5:///Mostrar lista de prestamos
                if(contPrestamo==0){
                    cout<<"La lista esta vacia\n";
                }
                else{
                    cout <<"No\tCliente\t\tFecha\t\tMonto\t\tSaldo\n";
                    for(int i=0; i<contPrestamo;i++){
                        cout<<listPrestamo[i]->getNumeroPrestamo()<< "\t";
                        cout<<listPrestamo[i]->getCliente()->getNombre() << " "<<listPrestamo[i]->getCliente()->getApellido()<< "\t";
                        listPrestamo[i]->getFechaAprobacion()->mostrarFecha();
                        cout<< "\t \t \t \t \t" <<listPrestamo[i]->getMontoAprobado()<< "\t \t";
                        cout<< listPrestamo[i]->getSaldoPendiente()<<endl;
                    }
                }
                break;
            case 6:///Mostrar detalles del préstamo
                cout<<"Digite el numero de prestamo: ";
                cin>>idPres;
                presta = BuscarPrestamo(listPrestamo, contPrestamo, idPres);
                if(presta){
                    verDetalles(presta);
                }
                else{
                    cout<<"El prestamo no existe";
                }
                break;
            case 7:///Salir
                cout<<"Saliendo del programa...\n";
                break;
            default:
                cout<<"Error, esa opcion no existe!!!\n";
        }
        system("pause");
    }while(opc!=7);
    return 0;
}
