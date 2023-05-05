#include <iostream>
#include <mysql.h>
#include "Cliente.h"
using namespace std;

int main()
{
    string NIT, nombres, apellidos, telefono, correo_electronico, fechaingreso;
    int idCliente;
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
    c.leer();
    cout << "Ingrese el idCliente que desea actualizar: " << endl;
    cin >> idCliente;
    cin.ignore();
    cout << "Ingrese Nombres: " << endl;
    getline(cin, nombres);
    cout << "Ingrese Apellidos: " << endl;
    getline(cin, apellidos);
    cout << "Ingrese nuevo nit: " << endl;
    getline(cin, NIT);
    cout << "Ingrese nuevo genero: (0 masculino. 1 femenino)" << endl;
    cin >> genero;
    cin.ignore();
    cout << "Ingrese nuevo telefono: "<<endl;
    getline(cin, telefono);
    cout << "Ingrese nuevo correo electronico: "<<endl;
    getline(cin, correo_electronico);
    cout << "Ingrese nueva fecha de ingreso: ";
    getline(cin, fechaingreso);
    Cliente x = Cliente(idCliente, nombres, apellidos, NIT, genero, telefono, correo_electronico, fechaingreso);
    x.actualizar();
    cout << "Ingrese el idCliente a eliminar:" << endl;
    cin >> idCliente;
    cin.ignore();
    Cliente d = Cliente(idCliente);
    d.eliminar();
    return 0;
}
