#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>

using namespace std;
class Productos
{
private:
	int idProducto = 0, idMarca = 0, existencia = 0;
	string producto, descripcion, imagen, precio_costo, precio_venta, fecha_ingreso;
	//constructor	
public:
	Productos() {
	};
	Productos(int idP, string pro, int idM, string des, string img, string pr_c, string pr_v, int e, string fecha_i) {
		idProducto = idP;
		producto = pro;
		idMarca = idM;
		descripcion = des;
		imagen = img;
		precio_costo = pr_c;
		precio_venta = pr_v;
		existencia = e;
		fecha_ingreso = fecha_i;
	}
	Productos(int idP, string pro) {
		idProducto = idP;
		producto = pro;
	};
	Productos(int idM) {
		idMarca = idM;
	};
	//metodos
	//set (modificar)
	void setidProducto(int idP) { idProducto = idP; };
	void setproducto(string pro) { producto = pro; };
	void setidMarca(int idM) { idMarca = idM; };
	void setdescripcion(string des) { descripcion = des; };
	void setimagen(string img) { imagen = img; };
	void setprecio_costo(string pr_c) { precio_costo = pr_c; };
	void setprecio_venta(string pr_v) { precio_venta = pr_v; };
	void setExistencia(int e) { existencia = e; };
	void setfecha_ingreso(string fecha_i) { fecha_ingreso = fecha_i; };

	//get (obtener)
	int getidProducto() { return idProducto; }
	string geProducto() { return producto; }
	int getidMarca() { return idMarca; }
	string getDescripcion() { return descripcion; }
	string getImagen() { return imagen; }
	string getPrecio_costo() { return precio_costo; }
	string getPrecio_venta() { return precio_venta; }
	int getExistencia() { return existencia; }
	string getFecha_ingreso() { return fecha_ingreso; }


	//CRUD
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idProducto);
			string tt = to_string(idMarca);
			string insert = "INSERT INTO productos(idProducto,producto,idMarca,descripcion,imagen,precio_costo,precio_venta,existencia,fecha_ingreso) "
				"VALUES('" + t + "','" + producto + "','" + tt + "','" + descripcion + "','" + imagen + "','" + precio_costo + "'," + precio_venta + ",'" + to_string(existencia) + "','" + fecha_ingreso + "')";
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
		cn.cerrar_conexion();

	};
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			//  string consulta = "select e.idEmpleado, e.nombres, e.apellidos, e.direccion, e.telefono, e.DPI, e.genero, e.fecha_nacimiento, e.fecha_inicio_labores, e.fechaingreso, p.puesto from empleados As e inner join puestos AS p on e.idPuesto = p.idPuesto";
			string consulta = "select p.idProducto, p.producto, p.descripcion, p.imagen, p.precio_costo, p.precio_venta,p.existencia, p.fecha_ingreso, m.marcas from productos As p inner join marcas AS m on p.idMarca = m.idMarca";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "idProducto: " << fila[0] << endl;
					cout << "Producto: " << fila[1] << endl;
					cout << "Descripcion: " << fila[2] << endl;
					cout << "Imagen: " << fila[3] << endl;
					cout << "Precio Costo: " << fila[4] << endl;
					cout << "Precio Venta: " << fila[5] << endl;
					cout << "Existencia: " << fila[6] << endl;
					cout << "Fecha Ingreso: " << fila[7] << endl;
					cout << "idMarca: " << fila[8] << endl;
					cout << "\n";
				}
				cout << "\n";
				cout << "_________________________________" << endl;
			}
			else {
				system("cls");
				cout << "Query Select got problems " << mysql_error(cn.getConectar()) << endl;
			}
		}
		else {
			cout << "Error en la conexion" << endl;
		}
		cn.cerrar_conexion();

	};
	bool leerId() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idProducto);
			string consulta = "SELECT *FROM productos  WHERE idProducto = '" + t + "'";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				if (mysql_num_rows(resultado) == 0) {
					cout << "No se encontraron resultados con el idProducto: " << t << endl;
					return false;
				}
				while (fila = mysql_fetch_row(resultado)) {
					cout << "idProducto: " << fila[0] << endl;
					cout << "Producto: " << fila[1] << endl;
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

	void actualizar() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idProducto);
			string tt = to_string(idMarca);
			string update = "UPDATE productos SET producto='" + producto + "',idMarca='" + tt + "',descripcion='" + descripcion + "',imagen='" + imagen + "',precio_costo='" + precio_costo + "',precio_venta=" + precio_venta + ",existencia='" + to_string(existencia) + "',fecha_ingreso='" + fecha_ingreso + "' WHERE idProducto = '" + t + "'";
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
			string deleteQuery = "DELETE FROM productos WHERE idProducto = '" + to_string(idProducto) + "'";
			const char* d = deleteQuery.c_str();
			q_estado = mysql_query(cn.getConectar(), d);
			if (!q_estado) {
				system("cls");
				cout << "Query Delete Successfuly" << endl;
			}
			else {
				system("cls");
				cout << "Query Delete got problems";
			}
		}
		else {
			cout << "Error al conectar" << endl;
		}
		cn.cerrar_conexion();
	};
};