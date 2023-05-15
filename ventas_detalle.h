#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
class Ventas_detalle
{
private:
	//Variables Ventas
	int idVenta = 0, nofactura = 0, idcliente = 0, idempleado = 0;
	char serie;
	string fechafactura;
	//Variables Ventas_detalle
	int idventa_detalle = 0, idventa = 0, idproducto = 0;
	string cantidad;
	float precio_unitario = 0;
public:
	//constructor
	Ventas_detalle() {

	};
	//ventas
	Ventas_detalle(int idV, int nof, char s, string fechaf, int idc, int ide, int idventa_d, int idv, int idp, string cant, float precio_u) {
		idVenta = idV;
		nofactura = nof;
		serie = s;
		fechafactura = fechaf;
		idcliente = idc;
		idempleado = ide;
		idventa_detalle = idventa_d;
		idventa = idv;
		idproducto = idp;
		cantidad = cant;
		precio_unitario = precio_u;
	};
	//constructor para validacion ventas
	Ventas_detalle(int idC) {
		idcliente = idC;
	};
	Ventas_detalle(int idE, int no, char s) {
		idempleado = idE;
		nofactura = no;
		serie = s;
	}

	//constructor para validaciones ventas detalle
	Ventas_detalle(int idp, int idv, int idventad, string c) {
		idproducto = idp;
		idventa = idv;
		idventa_detalle = idventad;
		cantidad = c;

	};
	Ventas_detalle(int idv, int idp, int idventad, string c, float pu) {
		idventa = idp;
		idproducto = idp;
		idventa_detalle = idventad;
		cantidad = c;
		precio_unitario = pu;

	};
	//eliminar
	Ventas_detalle(int idV, int idVD) {
		idVenta = idV;
		idventa_detalle = idVD;
	};
	//CRUD
	void crear() {
		//ventas
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idVenta);
			string tt = to_string(nofactura);
			string insert = "INSERT INTO ventas(idVenta,nofactura,serie,fechafactura,idcliente,idempleado,fechaingreso) "
				"VALUES('" + t + "','" + tt + "','" + serie + "','" + fechafactura + "','" + to_string(idcliente) + "','" + to_string(idempleado) + "',  NOW()  )";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				system("cls");
				cout << "Query Insert Successfuly" << endl;
			}
			else {
				system("cls");
				cout << "Query Insert got problems" << mysql_error(cn.getConectar()) << endl;
			}
		}
		else {
			cout << "Error al conectar" << endl;
		}
		bool valor=leerIdVentas();
		if (!valor) {
			return; 
		}
		system("pause");
		//ventas detalle
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idventa_detalle);
			string tt = to_string(idventa);
			string ttt = to_string(idproducto);
			string tttt = to_string(precio_unitario);
			string insert = "INSERT INTO ventas_detalle(idventa_detalle,idVenta,idProducto,cantidad,precio_unitario)"
				"VALUES('" + t + "','" + tt + "','" + ttt + "','" + cantidad + "','" + tttt + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				system("cls");
				cout << "Query Insert Successfuly" << endl;
			}
			else {
				system("cls");
				cout << "Query Insert Ventas got problems " << mysql_error(cn.getConectar()) << endl;
			}
		}
		else {
			cout << "Error al conectar" << endl;
		}
		cn.cerrar_conexion();
	};

	//Validaciones Ventas
	bool leerIdClientes() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idcliente);
			string consulta = "SELECT nombres, apellidos FROM clientes  WHERE idCliente = '" + t + "'";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				if (mysql_num_rows(resultado) == 0) {
					cout << "No se encontraron resultados con el idCliente: " << t << endl;
					return false;
				}
				while (fila = mysql_fetch_row(resultado)) {
					cout << "Nombres: " << fila[0] << endl;
					cout << "Apellidos: " << fila[1] << endl;
					cout << "\n";
				}
				cout << "\n";
				cout << "_________________________________" << endl;
			}
			else {
				system("cls");
				cout << "Query Select got problems" << mysql_error(cn.getConectar()) << endl;
				return false;
			}

		}
		else {
			cout << "Error en la conexion" << endl;
			return false;
		}
		cn.cerrar_conexion();
	};
	bool leerIdEmpleados() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idempleado);
			string consulta = "SELECT nombres, apellidos FROM empleados  WHERE idEmpleado = '" + t + "'";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				if (mysql_num_rows(resultado) == 0) {
					cout << "No se encontraron resultados con el idEmpleado: " << t << endl;
					return false;
				}
				while (fila = mysql_fetch_row(resultado)) {
					cout << "Nombres: " << fila[0] << endl;
					cout << "Apellidos: " << fila[1] << endl;
					cout << "\n";
				}
				cout << "\n";
				cout << "_________________________________" << endl;
			}
			else {
				system("cls");
				cout << "Query Select got problems" << mysql_error(cn.getConectar()) << endl;
				return false;
			}

		}
		else {
			cout << "Error en la conexion" << endl;
			return false;
		}
		cn.cerrar_conexion();
	};

	//Validaciones Ventas_detalle
	bool leerIdProductos() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idproducto);
			string consulta = "SELECT producto FROM productos  WHERE idProducto = '" + t + "'";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				if (mysql_num_rows(resultado) == 0) {
					cout << "No se encontraron resultados con el idProducto: " << t << endl;
					return false;
				}
				while (fila = mysql_fetch_row(resultado)) {
					cout << "Producto: " << fila[0] << endl;
					cout << "\n";
				}
				cout << "\n";
				cout << "_________________________________" << endl;
			}
			else {
				system("cls");
				cout << "Query Select got problems" << mysql_error(cn.getConectar()) << endl;
				return false;
			}

		}
		else {
			cout << "Error en la conexion" << endl;
			return false;
		}
		cn.cerrar_conexion();
	};
	bool leerIdVentas() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idventa);
			string consulta = "SELECT nofactura FROM ventas  WHERE idVenta = '" + t + "'";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				if (mysql_num_rows(resultado) == 0) {
					cout << "No se encontraron resultados con el idVenta: " << t << endl;
					return false;
				}
				while (fila = mysql_fetch_row(resultado)) {
					cout << "Numero Factura: " << fila[0] << endl;
					cout << "\n";
				}
				cout << "\n";
				cout << "_________________________________" << endl;
			}
			else {
				system("cls");
				cout << "Query Select got problems" << mysql_error(cn.getConectar()) << endl;
				return false;
			}

		}
		else {
			cout << "Error en la conexion" << endl;
			return false;
		}
		cn.cerrar_conexion();
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
					cout << "_________Cliente_________" << endl;
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
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idVenta);
			string tt = to_string(nofactura);
			string ic = to_string(idcliente);
			string ie = to_string(idempleado);
			string update = "UPDATE ventas SET nofactura='" + tt + "',serie='" + serie + "',idcliente='" + ic + "',idempleado='" + ie + "' WHERE idVenta = '" + t + "'";
			const char* u = update.c_str();
			q_estado = mysql_query(cn.getConectar(), u);
			if (!q_estado) {
				system("cls");
				cout << "Query Update Successfuly" << endl;
			}
			else {
				system("cls");
				cout << "Query Update Failed: " << mysql_error(cn.getConectar()) << endl;
				return; 
			}
		}
		else {
			cout << "Error al conectar" << endl;
			return; 
		}
		cn.cerrar_conexion();

		//ventas detalle
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idventa);
			string tt = to_string(idproducto);
			string pu = to_string(precio_unitario);
			string vd = to_string(idventa_detalle);
			string update = "UPDATE ventas_detalle SET idVenta='" + t + "',idProducto='" + tt + "',cantidad='" + cantidad + "',precio_unitario='" + pu + "' WHERE idventa_detalle = '" + vd + "'";
			const char* u = update.c_str();
			q_estado = mysql_query(cn.getConectar(), u);
			if (!q_estado) {
				system("cls");
				cout << "Query Update Successfuly" << endl;
			}
			else {
				system("cls");
				cout << "Query Update Failed: " << mysql_error(cn.getConectar()) << endl;
			}
		}
		else {
			cout << "Error al conectar" << endl;
		}
		cn.cerrar_conexion();
	};
	void eliminar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string deleteQuery = "DELETE FROM ventas_detalle WHERE idventa_detalle = '" + to_string(idventa_detalle) + "'";
			const char* d = deleteQuery.c_str();
			q_estado = mysql_query(cn.getConectar(), d);
			if (!q_estado) {
				system("cls");
				cout << "Query Delete Successfuly from Ventas Detalle" << endl;
			}
			else {
				system("cls");
				cout << "Query Delete got problems from Ventas Detalle" << mysql_error(cn.getConectar()) << endl;
			}
		}
		else {
			cout << "Error al conectar" << endl;
		}
		cn.cerrar_conexion();
		system("pause");
		system("cls");

		//ventas
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string deleteQuery = "DELETE FROM ventas WHERE idVenta = '" + to_string(idVenta) + "'";
			const char* d = deleteQuery.c_str();
			q_estado = mysql_query(cn.getConectar(), d);
			if (!q_estado) {
				system("cls");
				cout << "Query Delete Successfuly from Ventas" << endl;
			}
			else {
				system("cls");
				cout << "Query Delete got problems from Ventas "<< mysql_error(cn.getConectar())<<endl;
			}
		}
		else {
			cout << "Error al conectar" << endl;
		}
		cn.cerrar_conexion();
	};
};