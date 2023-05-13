#include <iostream>
#include <mysql.h>
#include "Cliente.h"
#include "Puestos.h"
#include "Empleados.h"
#include "Proveedores.h"
#include "Marcas.h"
#include "Productos.h"
#include "ventas_detalle.h"

using namespace std;
void C_Clientes() {
    string NIT, nombres, apellidos, telefono, correo_electronico;
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
    Cliente c = Cliente(idCliente, nombres, apellidos, NIT, genero, telefono, correo_electronico);
    c.crear();
    system("pause");
};
void R_Clientes() {
    Cliente l = Cliente();
    l.leer();
};
void U_Clientes() {
    string NIT, nombres, apellidos, telefono, correo_electronico;
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
    Cliente x = Cliente(idCliente, nombres, apellidos, NIT, genero, telefono, correo_electronico);
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
    Puestos U = Puestos(idPuesto, puesto);
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

//Table Empleados
void C_Empleados() {
    int idPuesto, idEmpleado;
    string nombres, apellidos, direccion, telefono, Dpi, fechanacimiento, fecha_inicio_labores;
    bool genero = 0;
    cout << "Ingrese el idPuesto: ";
    cin >> idPuesto;
    cin.ignore();
    Empleados l = Empleados(idPuesto, nombres);
    bool valor = l.leerId();
    if (!valor) {
        return;
    }
    cout << "Ingrese el idEmpleado:";
    cin >> idEmpleado;
    cin.ignore();
    cout << "Ingrese los nombres: ";
    getline(cin, nombres);
    cout << "Ingrese los apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese la direccion : ";
    getline(cin, direccion);
    cout << "Ingrese el telefono : ";
    getline(cin, telefono);
    cout << "Ingrese el DPI: ";
    getline(cin, Dpi);
    cout << "Ingrese genero (0. masculino 1. femenino): ";
    cin >> genero;
    cin.ignore();
    cout << "Ingrese la fecha de nacimiento: ";
    getline(cin, fechanacimiento);
    cout << "Ingrese la fecha de inicio de labores: ";
    getline(cin, fecha_inicio_labores);
    Empleados c = Empleados(idEmpleado, nombres, apellidos, direccion, telefono, Dpi, genero, fechanacimiento, idPuesto, fecha_inicio_labores);
    c.crear();
};
void R_Empleados() {
    Empleados l = Empleados();
    l.leer();

};
void U_Empleados() {
    int idPuesto, idEmpleado;
    string nombres, apellidos, direccion, telefono, Dpi, fechanacimiento, fecha_inicio_labores;
    bool genero = 0;
    cout << "Ingrese el idEmpleado que quiere cambiar los datos:";
    cin >> idEmpleado;
    cin.ignore();
    cout << "Ingrese los nuevos nombres: ";
    getline(cin, nombres);
    cout << "Ingrese los nuevos apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese la nueva direccion : ";
    getline(cin, direccion);
    cout << "Ingrese el nuevo telefono : ";
    getline(cin, telefono);
    cout << "Ingrese el nuevo DPI: ";
    getline(cin, Dpi);
    cout << "Ingrese el idPuesto: ";
    cin >> idPuesto;
    cin.ignore();
    cout << "Ingrese nuevo genero (0. masculino 1. femenino): ";
    cin >> genero;
    cin.ignore();
    cout << "Ingrese la nueva fecha de nacimiento: ";
    getline(cin, fechanacimiento);
    cout << "Ingrese la nueva fecha de inicio de labores: ";
    getline(cin, fecha_inicio_labores);
    Empleados u = Empleados(idEmpleado, nombres, apellidos, direccion, telefono, Dpi, genero, fechanacimiento, idPuesto, fecha_inicio_labores);
    u.actualizar();
};
void D_Empleados() {
    int idEmpleado = 0;
    cout << "Ingrese el idEmpleado a eliminar: " << endl;
    cin >> idEmpleado;
    cin.ignore();
    Empleados D = Empleados(idEmpleado);
    D.eliminar();
};
//Table Marcas
void C_Marcas() {
    int idMarca;
    string marca;
    cout << "Ingrese el idMarca: " << endl;
    cin >> idMarca;
    cin.ignore();
    cout << "Ingrese la marca: " << endl;
    getline(cin, marca);
    Marcas C = Marcas(idMarca, marca);
    C.crear();
};
void R_Marcas() {
    Marcas l = Marcas();
    l.leer();
};
void U_Marcas() {
    int idMarca;
    string marca;
    cout << "Ingrese el idMarca a buscar: " << endl;
    cin >> idMarca;
    cin.ignore();
    cout << "Ingrese la nueva marca: " << endl;
    getline(cin, marca);
    Marcas U = Marcas(idMarca, marca);
    U.actualizar();
};
void D_Marcas() {
    int idMarca = 0;
    cout << "Ingrese el idMarca a eliminar: " << endl;
    cin >> idMarca;
    cin.ignore();
    Marcas D = Marcas(idMarca);
    D.eliminar();
}
//Table Productos
void C_Productos() { //CORREGIR
    int idProducto, idMarca, existencia;
    string producto, descripcion, imagen;
    float precio_costo, precio_venta;
    cout << "Ingrese el idMarca a comprobar si existe: " << endl;
    cin >> idMarca;
    cin.ignore();
    Productos l = Productos(idMarca, producto);
    bool valor = l.leerId();
    if (!valor) {
        return;
    }
    cout << "Ingrese idProducto: " << endl;
    cin >> idProducto;
    cin.ignore();
    cout << "Ingrese el producto: " << endl;
    getline(cin, producto);
    cout << "Ingrese la descripcion: " << endl;
    getline(cin, descripcion);
    cout << "Ingrese la imagen: " << endl;
    getline(cin, imagen);
    cout << "Ingrese el precio costo: " << endl;
    cin >> precio_costo;
    cin.ignore();
    cout << "Ingrese el precio venta: " << endl;
    cin >> precio_venta;
    cin.ignore();
    cout << "Ingrese la existencia: " << endl;
    cin >> existencia;
    cin.ignore();

    Productos C = Productos(idProducto, producto, idMarca, descripcion, imagen, precio_costo, precio_venta, existencia);
    C.crear();
};
void R_Productos() {
    Productos l = Productos();
    l.leer();
};
void U_Productos() {
    int idProducto, idMarca, existencia;
    string producto, descripcion, imagen;
    float precio_costo, precio_venta;
    cout << "Ingrese el idProducto que desea actualizar:";
    cin >> idProducto;
    cin.ignore();
    cout << "Ingrese nuevo Producto: ";
    getline(cin, producto);
    cout << "Ingrese nuevo idMarca: ";
    cin >> idMarca;
    cin.ignore();
    cout << "Ingrese nueva descripcion : ";
    getline(cin, descripcion);
    cout << "Ingrese nueva imagen : ";
    getline(cin, imagen);
    cout << "Ingrese precio_costo: ";
    cin >> precio_costo;
    cout << "Ingrese precio_venta: ";
    cin >> precio_venta;
    cout << "Ingrese nueva existencia: ";
    cin >> existencia;
    cin.ignore();

    Productos u = Productos(idProducto, producto, idMarca, descripcion, imagen, precio_costo, precio_venta, existencia);
    u.actualizar();
};
void D_Productos() {
    int idProducto = 0;
    cout << "Ingrese el idProducto a eliminar: " << endl;
    cin >> idProducto;
    cin.ignore();
    Productos d = Productos(idProducto);
    d.eliminar();
};
//Table Proveedores
void C_Proveedores() {
    int idProveedore;
    string proveedor, nit, direccion, telefono;

    cout << "Ingrese idProveedor: ";
    cin >> idProveedore;
    cin.ignore();
    cout << "Ingrese Proveedor: ";
    getline(cin, proveedor);
    cout << "Ingrese NIT: ";
    getline(cin, nit);
    cout << "Ingrese Direccion: ";
    getline(cin, direccion);
    cout << "Ingrese telefono: ";
    getline(cin, telefono);

    Proveedores c = Proveedores(idProveedore, proveedor, nit, direccion, telefono);
    c.crear();
};
void R_Proveedores() {
    Proveedores r = Proveedores();
    r.leer();
};
void U_Proveedores() {
    int idProveedore;
    string proveedor, nit, direccion, telefono;

    cout << "Ingrese el idProveedor que desea actualizar: ";
    cin >> idProveedore;
    cin.ignore();
    cout << "Ingrese Nuevo Proveedor: ";
    getline(cin, proveedor);
    cout << "Ingrese Nuevo NIT: ";
    getline(cin, nit);
    cout << "Ingrese NuevaDireccion: ";
    getline(cin, direccion);
    cout << "Ingrese telefono: ";
    getline(cin, telefono);

    Proveedores u = Proveedores();
    u.actualizar();
};
void D_Proveedores() {
    int idProveedore = 0;
    cout << "Ingrese el idProveedor a eliminar:" << endl;
    cin >> idProveedore;
    cin.ignore();
    Proveedores d = Proveedores(idProveedore);
    d.eliminar();
};
void C_ventas_detalle() {
    //Variables Venta
    int idVenta = 0, no_factura=0,idcliente=0,idempleado=0;
    char serie = ' ';
    string fechafactura;
    //Variables venta detalle
    int idproducto=0, idventa = 0, idventa_detalle= 0;
    string cantidad;
    float precio_unitario = 0;
    cout << "Ingrese idCliente: " << endl;
    cin >> idcliente;
    cin.ignore();
    Ventas_detalle VC = Ventas_detalle(idcliente,idVenta);
    bool valClientes=VC.leerIdClientes();
    //llamar constructor
    cout << "Ingrese idEmpleado: " << endl;
    cin >> idempleado;
    cin.ignore();
    Ventas_detalle VE = Ventas_detalle(idempleado, no_factura, serie);
    bool valEmpleados=VE.leerIdEmpleados();
    
    cout << "Ingrese idProducto: " << endl;
    cin >> idproducto;
    cin.ignore();
    Ventas_detalle VP = Ventas_detalle(idproducto, idventa, idventa_detalle, cantidad);
    bool valProducto = VP.leerIdProductos();

    cout << "Ingrese idVentas: " << endl;
    cin >> idVenta;
    cin.ignore();
    Ventas_detalle VV = Ventas_detalle(idVenta, idproducto, idventa_detalle, cantidad, precio_unitario);
    bool valVentas = VV.leerIdVentas();

    //condicion
    if (!valClientes || !valEmpleados || !valProducto ||!valVentas){
        return;
    }

    cout << "Ingrese el Numero Factura: " << endl;
    cin >> no_factura;
    cin.ignore();
    cout << "Ingrese la serie (recuerde que este es solo un caracter)" << endl;
    cin >> serie;
    cin.ignore();
    cout << "Ingrese la fecha de la factura: " << endl;
    getline(cin, fechafactura);
    cin.ignore();
    cout << "Ingrese el idventa_detalle: " << endl;
    cin >> idventa_detalle;
    cin.ignore();
    cout << "Ingrese la cantidad: " << endl;
    getline(cin, cantidad);
    cout << "Ingrese el precio unitario" << endl;
    cin >> precio_unitario;
    cin.ignore();

    //pasos para crearla
    Ventas_detalle C = Ventas_detalle(idVenta, no_factura, serie, fechafactura, idcliente, idempleado, idventa_detalle, idVenta, idproducto, cantidad, precio_unitario);
    C.crear();
};
void R_ventas_detalle() {
    Ventas_detalle r = Ventas_detalle();
    r.leer();
};

int main() {
    char opc;
    int opcion = 0;
    do {
        cout << "Bienvenido al Menu Fase I - Proyecto final." << endl;
        cout << "Por favor elija una tabla: 1. Clientes 2. Puestos 3.Empleados 4. Marcas 5.Proveedores 6. Productos 7.Compras & Compras Detalle 8.Ventas & Ventas Detalle" << endl;
        cin >> opcion;
        switch (opcion) {
        case 1: //Clientes
            //C_Clientes(); 
            //R_Clientes(); 
            //U_Clientes();
            //D_Clientes();
            break;
        case 2: //Puestos
            //C_Puestos();
            //R_Puestos();
            //U_Puestos();
            //D_Puestos();
            break;
        case 3: //Empleados
            //C_Empleados();
            //R_Empleados(); 
            //U_Empleados();  
            //D_Empleados(); 
            break;
        case 4: //Marcas
            //C_Marcas();
            //R_Marcas();
            //U_Marcas();
            //D_Marcas();
            break;
        case 5: //Proveedores
            //C_Proveedores();
            //R_Proveedores();
            //U_Proveedores(); //ARREGLAR ESTE
            //D_Proveedores();
            break;
        case 6: //Productos
            //C_Productos();
            //R_Productos();
            //U_Productos();
            //D_Productos();        
            break;
        case 7: //Compras
            //C_Compras();
            //R_Compras();
            //U_Compras();
            //D_Compras();       
            break;
        case 8: //Ventas
            //C_ventas_detalle();
            R_ventas_detalle();
            //U_ventas_detalle();
            //D_ventas_detalle();
            break;
        default:
            break;
        }
        cout << "Desea continuar? (s/n)";
        cin >> opc;
    } while (opc == 's' || opc == 'S');

    system("pause");
    return 0;
}