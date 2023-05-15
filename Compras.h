#pragma once
#include <iostream>
#include <mysql.h>
#include "ConexionBD.h"
#include <string>

class Compras {
  private: 
  //Compras
  int idCompra=0, no_orden_compra=0,idproveedor=0 ;
  string fecha_orden,fechaingreso;
  //Compras_Detalle
  int id_compra_detalle=0,idcompra=0,idproducto=0,cantidad=0;
  float precio_costo_unitario=0;

  public: //Constructores
  Compras() {};
  //compras Detalle
  Compras(int idC,int noc, int idProvee,string fo, int idcd, int idc, int idprodu,int cntd,float pcu) {
    idCompra=idC;
    no_orden_compra=noc;
    idproveedor=idProvee;
    fecha_orden = fo;
    id_compra_detalle = idcd;
    idcompra = idc;
    idproducto = idprodu;
    cantidad = cntd;
    precio_costo_unitario = pcu;
  };
  //Validaciones compras
  Compras(int idpvdr) {  
    idproveedor =idpvdr;
  };
  
  //Validacion compras_Detalle 
  Compras(int idC,int idP,float pcu) {
  idcompra=idC;
  idproducto=idP;
  precio_costo_unitario =  pcu;
  };
  //--> Eliminar
  Compras(int idC,int idP,int idcd) {
  idcompra=idC;
  idproducto=idP;
  id_compra_detalle=idcd;
  };
  //CRUD
  void crear(){
    //compras
    	int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idCompra);
			string tt = to_string(idproveedor);
      string insert = "INSERT INTO compras(idCompra,no_orden_compra,idproveedor,fecha_orden,fechaingreso) "
				"VALUES('" + t + "','" + no_orden_compra + "','" + tt + "','" + fecha_orden + "','" + fechaingreso + "',  NOW()  )";
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
		bool valor=leerIdCompras();
		if (!valor) {
			return; 
		}
		system("pause");
    //Compras Detalle
    cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(id_compra_detalle);
			string tt = to_string(idcompra);
			string ttt = to_string(idproducto);
			string tttt = to_string(precio_costo_unitario);
			string insert = "INSERT INTO compras_detalle(id_compra_detalle,idcompra,idProducto,cantidad,precio_costo_unitario)"
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
  //Validaciones Compras
  bool leeridProveedores(){
  int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idproveedor);
			string consulta = "SELECT proveedor FROM Proveedores  WHERE idProveedore = '" + t + "'";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				if (mysql_num_rows(resultado) == 0) {
					cout << "No se encontraron resultados con el idProveedor: " << t << endl;
					return false;
				}
				while (fila = mysql_fetch_row(resultado)) {
					cout << "Proveedor: " << fila[0] << endl;
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
  //Validacion Compras_Detalle
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
bool leerIdCompras() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			string t = to_string(idCompra);
			string consulta = "SELECT no_orden_compra FROM ventas  WHERE idcompra = '" + t + "'";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				if (mysql_num_rows(resultado) == 0) {
					cout << "No se encontraron resultados con el idCompra: " << t << endl;
					return false;
				}
				while (fila = mysql_fetch_row(resultado)) {
					cout << "No. Orden de Compra: " << fila[0] << endl;
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
//LEER 
  void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getConectar()) {
			//Tabla COMPRAS
			string consulta = "SELECT c.idcompra,c.no_orden_compra,c.fecha_orden,c.fechaingreso,p.idproveedore,p.proveedor from compras c JOIN proveedores p ON c.idproveedor = p.idproveedore; ";
			const char* x = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), x);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "idCompra: " << fila[0] << endl;
					cout << "No. Orden Compra: " << fila[1] << endl;
					cout << "Fecha Orden: " << fila[2] << endl;
					cout << "Fecha Ingreso: " << fila[3] << endl;
					cout << "_________Proveedores_________" << endl;
					cout << "idProveedor: " << fila[4] << endl;
					cout << "Proveedor: " << fila[5] << endl;			
					cout << "\n";
				}
				cout << "\n";
				cout << "_________________________________" << endl;
			}
			else {
				system("cls");
				cout << "Query Select got problems" << mysql_error(cn.getConectar()) << endl;
			}
			//Tabla compras_detalle
			string consulta2 = "SELECT cd.idcompra_detalle,cd.cantidad,cd.precio_costo_unitario,c.idcompra,c.no_orden_compra,p.idProducto,p.producto from compras_detalle cd JOIN compras c ON cd.idcompra = c.idCompra JOIN productos p ON cd.idProducto = p.idProducto;";
			const char* y = consulta2.c_str();
			q_estado = mysql_query(cn.getConectar(), y);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "idCompra_detalle:  " << fila[0] << endl;
					cout << "Cantidad: " << fila[1] << endl;
					cout << "Precio_Costo_unitario: " << fila[2] << endl;			
					cout << "___________Compras___________" << endl;
					cout << "idCompra: " << fila[3] << endl;
					cout << "No. Orden Compra: " << fila[4] << endl;
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

	}; //DEBO TERMINARLO DESDE AQUI
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

		//Compras detalle
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

		//Compras
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