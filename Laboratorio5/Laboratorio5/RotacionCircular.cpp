#include "RotacionCircular.h"


namespace EIF201 {
	RotacionCircular::RotacionCircular()
		:cola(nullptr), cantidad(0) {
	}

	NodoLocutor* RotacionCircular::getCabeza() const {
		return (cola != nullptr) ? cola->siguiente : nullptr;
	}

	RotacionCircular::~RotacionCircular() {
		if (cola == nullptr) {
			return; //lista vacía
		}
	}
}
