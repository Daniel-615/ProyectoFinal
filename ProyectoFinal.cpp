#include <iostream>
#include <mysql.h>
#include "Cliente.h"
#include "Puestos.h"
using namespace std;

//tabla Clientes
void C_Clientes() {
    string NIT, nombres, apellidos, telefono, correo_electronico, fechaingreso;
    int idCliente = 0;
    bool genero;
    cout << "Ingrese idCliente: ";
    cin >> idCliente;
    cin.ignore();
    cout << "Ingrese nombres: ";
    getline(cin, nombres);
    cout << "Ingrese apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese NIT: ";
    getline(cin, NIT);
    cout << "Ingrese genero: (0 masculino. 1 femenino)" << endl;
    cin >> genero;
    cin.ignore();
    cout << "Ingrese telefono: ";
    getline(cin, telefono);
    cout << "Ingrese correo electronico: ";
    getline(cin, correo_electronico);
    cout << "Ingrese fecha de ingreso: " << endl;
    getline(cin, fechaingreso);
    Cliente c = Cliente(idCliente, nombres, apellidos, NIT, genero, telefono, correo_electronico, fechaingreso);
    c.crear();
    system("pause");
};
void R_Clientes() {
    Cliente l = Cliente();
    l.leer();
};
void U_Clientes() {
    string NIT, nombres, apellidos, telefono, correo_electronico, fechaingreso;
    int idCliente = 0;
    bool genero;
    cout << "Ingrese el idCliente que desea actualizar: " << endl;
    cin >> idCliente;
    cin.ignore();
    cout << "Ingrese nuevos Nombres: " << endl;
    getline(cin, nombres);
    cout << "Ingrese nuevos Apellidos: " << endl;
    getline(cin, apellidos);
    cout << "Ingrese nuevo nit: " << endl;
    getline(cin, NIT);
    cout << "Ingrese nuevo genero: (0 masculino. 1 femenino)" << endl;
    cin >> genero;
    cin.ignore();
    cout << "Ingrese nuevo telefono: " << endl;
    getline(cin, telefono);
    cout << "Ingrese nuevo correo electronico: " << endl;
    getline(cin, correo_electronico);
    cout << "Ingrese nueva fecha de ingreso: ";
    getline(cin, fechaingreso);
    Cliente x = Cliente(idCliente, nombres, apellidos, NIT, genero, telefono, correo_electronico, fechaingreso);
    x.actualizar();

};
void D_Clientes() {
    int idCliente = 0;
    cout << "Ingrese el idCliente a eliminar:" << endl;
    cin >> idCliente;
    cin.ignore();
    Cliente d = Cliente(idCliente);
    d.eliminar();
}; 

//tabla Puestos
void C_Puestos() {
    int idPuesto = 0; 
    string puesto;
    cout << "Ingrese el idPuesto: " << endl;
    cin >> idPuesto;
    cin.ignore();
    cout << "Ingrese el puesto: " << endl;
    getline(cin, puesto);
    Puestos c = Puestos(idPuesto, puesto);
    c.crear();
};
void R_Puestos() {
    Puestos l = Puestos();
    l.leer();
};
void U_Puestos() {
    int idPuesto = 0;
    string puesto;
    cout << "Ingrese el idPuesto a modificar: " << endl;
    cin >> idPuesto;
    cin.ignore();
    cout << "Ingrese el nuevo puesto: " << endl;
    getline(cin, puesto);
    Puestos U = Puestos(idPuesto,puesto);
    U.actualizar();
};
void D_Puestos() {
    int idPuesto = 0;
    cout << "Ingrese el idPuesto a eliminar: " << endl;
    cin >> idPuesto;
    cin.ignore();
    Puestos D = Puestos(idPuesto);
    D.eliminar();
};
int main()
{
    //C_Clientes();
    //R_Clientes();
    //U_Clientes();
    //D_Clientes();
    //C_Puestos();
    //R_Puestos();
    //U_Puestos();
    D_Puestos();    
    return 0;
}