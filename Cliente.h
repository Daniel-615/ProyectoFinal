#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>
using namespace std;
class Cliente
{
	private:
		int idCliente=0,genero=0;
		string nombres, apellidos, Nit,telefono,correo_electronico,fecha_ingreso;
	//constructor
	public:
	Cliente() {
	};
	Cliente(int id, string nom, string ape, string n, int g,string phone, string correo, string fecha) {
		idCliente = id;
		nombres = nom;
		apellidos= ape;
		Nit = n;
		genero = g;
		telefono = phone;
		correo_electronico = correo;
		fecha_ingreso = fecha;
	};
	//metodos
	//set (modificar)
	void setidCliente(int id) { idCliente = id; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setNit(string n) { Nit = n; }
	void setGenero(int g) { genero = g; }
	void setTelefono(string phone) { telefono = phone; }
	void setCorreo_electronico(string correo) { correo_electronico = correo; }
	void setfechaingreso(string fecha) { fecha_ingreso = fecha; }
	//get (obtener)
	int getidCliente() { return idCliente; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getNit() { return Nit; }
	int getGenero() { return genero; }
	string getTelefono() { return telefono; }
	string getCorreo_electronico() { return correo_electronico; }
	string getfechaingreso() { return fecha_ingreso; }

	//CRUD

	//Crear arreglar lo de Bit (genero)
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {

			string t = to_string(idCliente);
			string ge = to_string(genero);
			string insert = "INSERT INTO clientes(idCliente,nombres,apellidos,NIT,genero,telefono,correo_electronico,fechaingreso) VALUES('" + t + "','" + nombres + "','" + apellidos + "','" + Nit + "','" + ge + "','"+telefono+"','" + correo_electronico + "','" + fecha_ingreso + "')";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				system("cls");
				cout << "Query Insert Successfuly" << endl;
			}
			else {
				system("cls");
				cout << "Query Insert got problems";
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
			string consulta = "SELECT *FROM clientes";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "idCliente: " << fila[0] << endl;
					cout << "nombres: " << fila[1] << endl;
					cout << "apellidos: " << fila[2] << endl;
					cout << "NIT: " << fila[3] << endl;
					cout << "genero: " << fila[4] << endl;
					cout << "telefono :" << fila[5] << endl;
					cout << "correo_electronico :" << fila[6] << endl;
					cout << "fechaingreso: " << fila[7] << endl;
					cout << "\n";
				}
				cout << "\n";
				cout << "_________________________________" << endl;
			}
			else {
				system("cls");
				cout << "Query Select got problems" << endl;
			}

		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();
	}
	void actualizar() {

	};
	void eliminar() {

	};
};