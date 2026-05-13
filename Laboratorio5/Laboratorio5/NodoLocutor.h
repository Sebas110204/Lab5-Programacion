#pragma once

#include <iostream>
#include <string>

using namespace std;

namespace EIF201 {
	struct NodoLocutor {
		string    nombre;
		NodoLocutor* siguiente;

		NodoLocutor(const string& n)
			: nombre(n), siguiente(nullptr) {
			cout << "[NodoLocutor creado: " << n << "]" << endl;
		}
		~NodoLocutor() {
			cout << "[NodoLocutor destruido: " << nombre << "]" << endl;
		}
	};
} // namespace EIF201
