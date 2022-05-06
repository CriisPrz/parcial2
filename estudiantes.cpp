#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "ConexionBD.h"



using namespace std;

class Estudiante : Persona {
private: string car;
	   
public:
	Estudiante() {
	}
	Estudiante(string nom, string ape, string dir, int tel, string fn, string ema) : Persona(nom, ape, dir, tel, fn) {
		car = n;
	}

	
	void setCar(string n) { car= n; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setFecha_Nacimiento(int fn) { fecha_nacimiento = fn; }
	//get (mostrar)
	string getCar() { return car; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }
	
	// metodo
	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		
		cn.abrir_conexion();
		string t = to_string(telefono);
		if (cn.getConectar()) {
		string  insertar = "INSERT INTO estudiantes(car,nombres,apellidos,direccion,telefono,fecha_nacimiento) VALUES ('" + car + "','" + nombres + "','" + apellidos + "','" + direccion + "',"+ t +",'" + fecha_nacimiento + "')";
		const char* i = insertar.c_str();
		// executar el query
		q_estado = mysql_query(cn.getConectar(), i);
		if (!q_estado) {
			cout << "Ingreso Exitoso ..." << endl;
		}
		else {
			cout << " xxx Error al Ingresar  xxx" << endl;
		}
		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
	void leer() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		
		if (cn.getConectar()) {
			
			cout << "------------ Datos de Estudiantes ------------" << endl;
			string consulta = "select * from estudiantes";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5]<<"," << fila[6] <<endl;
				}
				
			}
			else {
				cout << " xxx Error al Consultar  xxx" << endl;
			}

		}
		else {
			cout << " xxx Error en la Conexion xxxx" << endl;
		}
		cn.cerrar_conexion();
	}
};
