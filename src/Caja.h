#pragma once
#include "Pared.h"

class Caja {
private: 
	pared suelo;
	pared techo;
	pared der;
	pared izq;
public:
	Caja();
	virtual~Caja();

	
	
	void dibuja();
	friend class interaccion;

};
