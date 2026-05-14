#include "RotacionCircular.h"
#include <iostream>

using namespace std;

namespace EIF201 {

	RotacionCircular::RotacionCircular()
		: cola(nullptr), cantidad(0) {
	}

	NodoLocutor* RotacionCircular::getCabeza() const {
		return (cola != nullptr) ? cola->siguiente : nullptr;
	}

	RotacionCircular::~RotacionCircular() {
		if (cola == nullptr) {
			return; // lista vacía
		}

		NodoLocutor* cabeza = cola->siguiente; // cabeza de la lista
		cola->siguiente = nullptr; // romper el ciclo para facilitar eliminación
		NodoLocutor* actual = cabeza;
		while (actual != nullptr) {
			NodoLocutor* temp = actual->siguiente; // guardar siguiente antes de eliminar
			delete actual;
			actual = temp;
		}
		cola = nullptr;
		cout << "[RotacionCircular destruida]" << endl;
	}

	void RotacionCircular::insertarAlFinal(const string& nombre) {
		NodoLocutor* nuevo = new NodoLocutor(nombre);
		if (cola == nullptr) {
			nuevo->siguiente = nuevo; // apunta a sí mismo
			cola = nuevo;
		}
		else {
			nuevo->siguiente = cola->siguiente; // nuevo apunta a la cabeza actual
			cola->siguiente = nuevo; // antigua cola apunta al nuevo
			cola = nuevo; // nuevo es la nueva cola
		}
		cantidad++;
	}

	void RotacionCircular::insertarAlInicio(const string& nombre) {
		NodoLocutor* nuevo = new NodoLocutor(nombre);
		if (cola == nullptr) {
			nuevo->siguiente = nuevo; // apunta a sí mismo
			cola = nuevo;
		}
		else {
			nuevo->siguiente = cola->siguiente; // nuevo apunta a la cabeza actual
			cola->siguiente = nuevo; // antigua cola apunta al nuevo
			// cola no cambia: el nuevo es la nueva cabeza, pero la cola sigue igual
		}
		cantidad++;
	}

	bool RotacionCircular::insertarDespuesDe(const string& referencia, const string& nuevo_nombre) {
		if (cola == nullptr) {
			return false; // lista vacía
		}

		NodoLocutor* cabeza = getCabeza();
		NodoLocutor* actual = cabeza;

		do {
			if (actual->nombre == referencia) {
				NodoLocutor* nuevo = new NodoLocutor(nuevo_nombre);
				nuevo->siguiente = actual->siguiente; // nuevo apunta al siguiente del actual
				actual->siguiente = nuevo; // actual apunta al nuevo

				if (actual == cola) {
					cola = nuevo; // si insertamos después de la cola, el nuevo es la nueva cola
				}

				// Estos van afuera del if (actual == cola)
				cantidad++;
				return true;
			}
			actual = actual->siguiente; // avanzar al siguiente nodo

		} while (actual != cabeza);

		return false; // no encontrado
	}

	int RotacionCircular::obtenerPosicion(const string& nombre) const {
		if (cola == nullptr) {
			return -1; // lista vacía
		}

		NodoLocutor* cabeza = getCabeza();
		NodoLocutor* actual = cabeza;
		int pos = 0;

		do {
			if (actual->nombre == nombre) {
				return pos;
			}
			actual = actual->siguiente;
			pos++;

		} while (actual != cabeza);

		return -1; // no encontrado
	}

	string RotacionCircular::turnoActual() const {
		if (cola == nullptr) {
			return ""; // lista vacía
		}
		return getCabeza()->nombre; // la cabeza es el turno actual
	}

	bool RotacionCircular::eliminarLocutor(const string& nombre) {
		if (cola == nullptr) {
			return false; // lista vacía
		}

		NodoLocutor* cabeza = getCabeza();
		NodoLocutor* actual = cabeza;
		NodoLocutor* previo = cola; // inicialmente, el nodo previo es la cola (último nodo)

		do {
			if (actual->nombre == nombre) {
				if (actual == cola && actual == cabeza) {
					// único nodo en la lista
					cola = nullptr;
				}
				else {
					previo->siguiente = actual->siguiente; // el nodo previo salta al siguiente del actual
					if (actual == cola) cola = previo;
				}
				delete actual;
				cantidad--;
				return true;
			}
			previo = actual;
			actual = actual->siguiente;

		} while (actual != cabeza);

		return false; // no encontrado
	}

	bool RotacionCircular::eliminarTurnoActual() {
		if (cola == nullptr) {
			return false; // lista vacía
		}
		return eliminarLocutor(getCabeza()->nombre); // elimina la cabeza actual
	}

	string RotacionCircular::siguiente() {
		if (cola == nullptr) {
			return ""; // lista vacía
		}
		cola = cola->siguiente; // avanzar la cola al siguiente nodo
		return getCabeza()->nombre; // la nueva cabeza es el turno actual
	}

	void RotacionCircular::simularTurnos(int n) {
		if (cola == nullptr) {
			cout << "Sin locutores en rotacion." << endl;
			return;
		}
		for (int i = 1; i <= n; i++) {
			cout << "Turno " << i << ": " << siguiente() << endl;
		}
	}

	void RotacionCircular::imprimirRotacion() const {
		if (cola == nullptr) {
			cout << "Rotacion vacia." << endl;
			return;
		}

		NodoLocutor* cabeza = getCabeza();
		NodoLocutor* actual = cabeza;

		cout << "Rotacion: ";
		do {
			cout << actual->nombre;
			actual = actual->siguiente;
			if (actual != cabeza) {
				cout << " -> ";
			}
		} while (actual != cabeza);
		cout << " -> (inicio)" << endl;
	}

	int RotacionCircular::getCantidad() const {
		return cantidad;
	}

	bool RotacionCircular::estaVacia() const {
		return cola == nullptr;
	}

} // namespace EIF201