#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
class Ventas_detalle
{
private:
	//Variables Ventas
	int idVenta=0, nofactura=0, idcliente=0, idempleado=0;
	char serie;
	string fechafactura;
	//Variables Ventas_detalle
	int idventa_detalle=0, idventa=0, idproducto=0;
	string cantidad;
	float precio_unitario=0;
public:
	//constructor
	Ventas_detalle() {

	};
	//compras
	Ventas_detalle(int idV, int nof, char s, string fechaf, int idc, int ide) {
		idVenta = idV;
		nofactura = nof;
		serie = s;
		fechafactura = fechaf;
		idcliente = idc;
		idempleado = ide;
	};
	//compras_detalle
	Ventas_detalle(int idventa_d, int idv, int idp, string cant, float precio_u) {
		idventa_detalle = idventa_d;
		idventa = idv;
		idproducto = idp;
		cantidad = cant;
		precio_unitario = precio_u;
	};
	//CRUD
	void crear() {

	};
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			//Tabla Ventas
			string consulta = "SELECT v.idventa,v.nofactura,v.serie,v.fechafactura,v.fechaingreso,e.idempleado,e.nombres,e.apellidos,c.idCliente,c.nombres,c.apellidos from ventas v JOIN empleados e ON v.idempleado = e.idempleado JOIN clientes c ON v.idcliente = c.idCliente; ";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "idVenta: " << fila[0] << endl;
					cout << "numero Factura: " << fila[1] << endl;
					cout << "Serie: " << fila[2] << endl;
					cout << "Fecha Factura: " << fila[3] << endl;
					cout << "Fecha Ingreso: " << fila[4] << endl;
					cout << "_________Empleado_________" << endl;
					cout << "idEmpleado: " << fila[5] << endl;
					cout << "Nombres: " << fila[6] << endl;
					cout << "Apellidos: " << fila[7] << endl;
					cout << "_________Cliente_________"<<endl;
					cout << "idCliente: " << fila[8] << endl;
					cout << "Nombres: " << fila[9] << endl;
					cout << "Apellidos: " << fila[10] << endl;
					cout << "\n";
				}
				cout << "\n";
				cout << "_________________________________" << endl;
			}
			else {
				system("cls");
				cout << "Query Select got problems" << mysql_error(cn.getConectar()) << endl;
			}
			//Tabla ventas_detalle
			string consulta2 = "SELECT vd.idventa_detalle,vd.cantidad,vd.precio_unitario, (vd.cantidad * vd.precio_unitario) AS total, v.idVenta,v.nofactura,p.idProducto,p.producto from ventas_detalle vd JOIN ventas v ON vd.idVenta = v.idVenta JOIN productos p ON vd.idProducto = p.idProducto;";
			const char* y = consulta2.c_str();
			q_estado = mysql_query(cn.getConectar(), y);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "idVenta_detalle:  " << fila[0] << endl;
					cout << "Cantidad: " << fila[1] << endl;
					cout << "precio_unitario: " << fila[2] << endl;
					cout << "total: " << fila[3] << endl;
					cout << "___________Ventas___________" << endl;
					cout << "idVenta: " << fila[4] << endl;
					cout << "Numero Factura: " << fila[5] << endl;
					cout << "___________Productos___________" << endl;
					cout << "idProducto: " << fila[5] << endl;
					cout << "Producto: " << fila[6] << endl;
					cout << "\n";
				}
				cout << "\n";
				cout << "_________________________________" << endl;
			}
			else {
				system("cls");
				cout << "Query Select got problems" << mysql_error(cn.getConectar()) << endl;
			}

		}
		else {
			cout << "Error en la conexion" << endl;
		}

		cn.cerrar_conexion();

	};
	void actualizar() {

	};
	void eliminar() {

	};
};

