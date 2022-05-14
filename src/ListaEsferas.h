#pragma once

#include "Esfera.h"
#define MAX_ESFERAS 100
#include "Pared.h"
#include "Caja.h"
#include "Hombre.h"
#include "Interaccion.h"


class ListaEsferas {
private:
	int numero;
	Esfera* lista[MAX_ESFERAS];
public:
	ListaEsferas();
	int getNumero() { return numero; };


	bool agregar(Esfera* e);
	void dibuja();
	void mueve(float t); 

	void rebote(pared p); 
	void rebote();
	void rebote(Caja c);

	void eliminar(int index);
	void eliminar(Esfera*e); 

	Esfera* colision (hombre& h);
	Esfera* operator[](int i);
	
	

	void destruircontenido();
};