#pragma once

#include "Disparo.h"
#include "Pared.h"
#include "Interaccion.h"
#include "Caja.h"

#define MAX_DISPAROS 10


class ListaDisparos {
private: 
	int numero; 
	disparo * lista[MAX_DISPAROS]; 
public:
	ListaDisparos(); 
	virtual~ListaDisparos();

	bool agregar(disparo* d);
	void dibuja(); 
	void mueve(float t);
	void colision(pared p);
	void colision(Caja c);
	void destruirContenido();


	void eliminar(int index);
	void eliminar(disparo* d);
	float getNumero();
	disparo* operator [](int i);
};