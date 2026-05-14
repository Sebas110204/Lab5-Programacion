#ifndef ROTACION_CIRCULAR_H
#define ROTACION_CIRCULAR_H

#include "NodoLocutor.h"
#include <string> // Necesario para usar 'string'

using namespace std; // Necesario para no tener que poner std::string

namespace EIF201 {
	class RotacionCircular {
	private:
		NodoLocutor* cola; // CAMBIO CLAVE: Usamos 'cola' para la lista circular
		int          cantidad;

		NodoLocutor* getCabeza() const; // Tu método privado, ¡está perfecto aquí!

	public:
		RotacionCircular();
		~RotacionCircular();

		void insertarAlFinal(const string& nombre);
		void insertarAlInicio(const string& nombre);
		bool insertarDespuesDe(const string& referencia, const string& nuevo_nombre);

		bool existeLocutor(const string& nombre) const;
		int obtenerPosicion(const string& nombre) const;
		string turnoActual() const;

		bool eliminarLocutor(const string& nombre);
		bool eliminarTurnoActual();

		string siguiente();
		void simularTurnos(int n);
		void imprimirRotacion() const;

		int getCantidad() const;
		bool estaVacia() const;
	};
} // namespace EIF201

#endif // ROTACION_CIRCULAR_H