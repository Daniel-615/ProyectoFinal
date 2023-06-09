#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>

class Proveedores
{

private:
	int idProveedore;
	string proveedor, nit, direccion, telefono;

public:
	Proveedores() {
	};
	Proveedores(int id, string prov, string n, string dir, string tel) {
		idProveedore = id;
		proveedor = prov;
		nit = n;
		direccion = dir;
		telefono = tel;
	};
	Proveedores(int id) {
		idProveedore = id;
	};

	//CRUD
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string t = to_string(idProveedore);
			string insert = "INSERT INTO proveedores(idProveedore,proveedor,nit,direccion,telefono) "
				"VALUES('" + t + "','" + proveedor + "','" + nit + "','" + direccion + "','" + telefono + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Query Insert Successfuly" << endl;
			}
			else {
				cout << "Query Insert got problems" << mysql_error(cn.getConectar()) << endl;
			}
		}
		else {
			cout << "Error al conectar" << endl;
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
			string consulta = "SELECT *FROM proveedores";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "idProveedore " << fila[0] << endl;
					cout << "Proveedores: " << fila[1] << endl;
					cout << "NIT: " << fila[2] << endl;
					cout << "Direccion: " << fila[3] << endl;
					cout << "Telefono: " << fila[4] << endl;
					cout << "\n";
				}
				cout << "\n";
				cout << "_________________________________" << endl;
			}
			else {
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
			string t = to_string(idProveedore);
			string update = "UPDATE proveedores SET proveedor='" + proveedor + "', NIT='" + nit + "', Direccion='" + direccion + "', telefono='" + telefono + "' WHERE idProveedore='" + t + "'";
			const char* u = update.c_str();
			q_estado = mysql_query(cn.getConectar(), u);
			if (!q_estado) {
				cout << "Query Update Successfuly" << endl;
			}
			else {
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
			string deleteQuery = "DELETE FROM proveedores WHERE idProveedore = '" + to_string(idProveedore) + "'";
			const char* d = deleteQuery.c_str();
			q_estado = mysql_query(cn.getConectar(), d);
			if (!q_estado) {
				cout << "Query Delete Successfuly" << endl;
			}
			else {

				cout << "Query Delete got problems";
			}
		}
		else {
			cout << "Error al conectar" << endl;
		}
		cn.cerrar_conexion();
	};

};