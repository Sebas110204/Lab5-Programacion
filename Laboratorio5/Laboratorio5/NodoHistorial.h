#ifndef NODO_HISTORIAL_H
#define NODO_HISTORIAL_H

#include <iostream>
#include <string>
using namespace std;


namespace EIF201 {

	struct NodoHistorial {
		string    cancion;
		NodoHistorial* siguiente;
		NodoHistorial* anterior;

		NodoHistorial(const string& c)
			: cancion(c), siguiente(nullptr), anterior(nullptr) {
			cout << "[NodoHistorial creado: " << c << "]" << endl;
		}

		~NodoHistorial() {
			cout << "[NodoHistorial destruido: " << cancion << "]" << endl;
		}
	};
}// namespace EIF201
#endif // NODO_HISTORIAL_H


