#include <iostream>
#include "Funciones.h"
#include <chrono>
#include <thread>

//#include "Arduino.ino"
using namespace std;
void simularCarga() {
    const int tiempoEspera = 150;
    const int numeroPuntos = 40;
    for (int i = 0; i < numeroPuntos; i++) {
        cout << ".";
        cout.flush();

        this_thread::sleep_for(chrono::milliseconds(tiempoEspera));
    }
    cout << endl;
}
int main() {
    char opc;
    int opcion = 0;
    do {
        cout << "Bienvenido al Menu Fase I - Proyecto final." << endl;
        cout << "Por favor elija una tabla: 1. Clientes 2. Puestos 3.Empleados 4. Marcas 5.Proveedores 6. Productos 7.Compras & Compras Detalle 8.Ventas & Ventas Detalle 9. Arduino 10.Imprimir" << endl;
        cin >> opcion;
        switch (opcion) {
        case 1:
            int opcionclientes;
            cout << "___Bienvenido al CRUD de Clientes___" << endl;
            cout << "1. Crear 2.Leer 3.Actualizar 4.Eliminar" << endl;
            cout << "opcion:";
            cin >> opcionclientes;
            switch (opcionclientes) {
            case 1:
                C_Clientes();
                break;
            case 2:
                R_Clientes();
                break;
            case 3:
                U_Clientes();
                break;
            case 4:
                D_Clientes();
                break;
            default: cout << "Esa opcion no existe!" << endl;
                break;
            }
            break;
        case 2:
            int opcionpuestos;
            cout << "___Bienvenido al CRUD de Puestos___" << endl;
            cout << "1. Crear 2.Leer 3.Actualizar 4.Eliminar" << endl;
            cout << "opcion:";
            cin >> opcionpuestos;
            switch (opcionpuestos) {
            case 1:
                C_Puestos();
                break;
            case 2:
                R_Puestos();
                break;
            case 3:
                U_Puestos();
                break;
            case 4:
                D_Puestos();
                break;
            default: cout << "Esa opcion no existe!" << endl;
                break;
            }
            break;
        case 3:
            int opcionempleados;
            cout << "___Bienvenido al CRUD de Empleados___" << endl;
            cout << "1. Crear 2.Leer 3.Actualizar 4.Eliminar" << endl;
            cout << "opcion:";
            cin >> opcionempleados;
            switch (opcionempleados) {
            case 1:
                C_Empleados();
                break;
            case 2:
                R_Empleados();
                break;
            case 3:
                U_Empleados();
                break;
            case 4:
                D_Empleados();
                break;
            default: cout << "Esa opcion no existe!" << endl;
                break;
            }
            break;
        case 4:
            int opcionmarcas;
            cout << "___Bienvenido al CRUD de Marcas___" << endl;
            cout << "1. Crear 2.Leer 3.Actualizar 4.Eliminar" << endl;
            cout << "opcion:";
            cin >> opcionmarcas;
            switch (opcionmarcas) {
            case 1:
                C_Marcas();
                break;
            case 2:
                R_Marcas();
                break;
            case 3:
                U_Marcas();
                break;
            case 4:
                D_Marcas();
                break;
            default: cout << "Esa opcion no existe!" << endl;
                break;
            }
            break;
        case 5:
            int opcionproveed;
            cout << "___Bienvenido al CRUD de Proveedores___" << endl;
            cout << "1. Crear 2.Leer 3.Actualizar 4.Eliminar" << endl;
            cout << "opcion:";
            cin >> opcionproveed;
            switch (opcionproveed) {
            case 1:
                C_Proveedores();
                break;
            case 2:
                R_Proveedores();
                break;
            case 3:
                U_Proveedores();
                break;
            case 4:
                D_Proveedores();
                break;
            default: cout << "Esa opcion no existe!" << endl;
                break;
            }
            break;
        case 6:
            int opcionpro;
            cout << "___Bienvenido al CRUD de Productos___" << endl;
            cout << "1. Crear 2.Leer 3.Actualizar 4.Eliminar" << endl;
            cout << "opcion:";
            cin >> opcionpro;
            switch (opcionpro) {
            case 1:
                C_Productos();
                break;
            case 2:
                R_Productos();
                break;
            case 3:
                U_Productos();
                break;
            case 4:
                D_Productos();
                break;
            default: cout << "Esa opcion no existe!" << endl;
                break;
            }
            break;
        case 7:;
            int opcioncompras;
            cout << "___Bienvenido al CRUD de Compras___" << endl;
            cout << "1. Crear 2.Leer 3.Actualizar 4.Eliminar" << endl;
            cout << "opcion:";
            cin >> opcioncompras;
            switch (opcioncompras) {
            case 1:
                C_Compras();
                break;
            case 2:
                R_Compras();
                break;
            case 3:
                U_Compras();
                break;
            case 4:
                D_Compras();
                break;
            default: cout << "Esa opcion no existe!" << endl;
                break;
            }
            break;
        case 8:
            int opcionv;
            cout << "___Bienvenido al CRUD de Ventas y Ventas Detalle!___" << endl;
            cout << "1. Crear 2.Leer 3.Actualizar 4.Eliminar" << endl;
            cout << "opcion:";
            cin >> opcionv;
            switch (opcionv) {
            case 1:
                C_ventas_detalle();
                break;
            case 2:
                R_ventas_detalle();
                break;
            case 3:
                U_ventas_detalle();
                break;
            case 4:
                D_ventas_detalle();
                break;
            default:
                cout << "Esa opcion no existe!" << endl;
                break;
            }
            break;
        case 9:
            cout << "Bienvenido al menu de arduino!" << endl;
            int opcard;
            cout << "Ingrese una opcion 1.setup 2.loop" << endl;
            cout << "opcion: ";
            cin >> opcard;
            switch (opcard) {
            case 1:
                //setup();
                break;
            case 2:
                //loop();
                break;
            default:
                cout << "Esa opcion no es valida!" << endl;
                break;
            };
            break;
        case 10:
            char opcionp;
            cout << "Desea imprimir? (S/n)" << endl;
            cin >> opcionp;
            if (opcionp == 'S' || opcionp == 's') {
                // imprimir();
            }
            break;
        default:
            cout << "La opcion ingresada no es valida!" << endl;
            break;
        }
        cout << "Desea continuar? (s/n)";
        cin >> opc;
    } while (opc == 's' || opc == 'S');
    cout << "\tEl programa ha llegado a su fin!" << endl;
    simularCarga();
    cout << "\t_______________________________________________Hecho por:_________________________________________________" << endl;
    cout << "\t|Valeria R.|" << "\t|Sebastian H.|" << "\t    |Angel S.|" << "\t|Ary R.|" << "\t|Jose Pablo I.|" << "\t|Alexander C.|" << endl;
    cout << "\t__________________________________________________________________________________________________________" << endl;
    return 0;
}