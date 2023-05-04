#include <iostream>
#include <mysql.h>
#include "Cliente.h"
using namespace std;
int main()
{
    string NIT, nombres, apellidos, telefono, correo_electronico, fechaingreso;
    int idCliente,genero;
    cout << "Ingrese idCliente: ";
    cin >> idCliente;
    cin.ignore();
    cout << "Ingrese nombres: ";
    getline(cin, nombres);
    cout << "Ingrese apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese NIT: ";
    getline(cin, NIT);
    cout << "Ingrese genero: ";
    cin >> genero;
    cin.ignore();
    cout << "Ingrese telefono: ";
    getline(cin, telefono);
    cout << "Ingrese correo electronico: ";
    getline(cin, correo_electronico);
    cout << "Ingrese fecha de ingreso: ";
    getline(cin, fechaingreso);
    Cliente c = Cliente(idCliente,nombres, apellidos, NIT, genero, telefono, correo_electronico,fechaingreso);
    c.crear();
    c.leer();
    return 0;
}