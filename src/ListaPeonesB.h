#pragma once
#include "PeonB.h"
#include <stdlib.h>



#define MAX_PEONES 8


class ListaPeonesB {
private:
	int seleccion;
	int numero;
	PeonB* lista[MAX_PEONES];

public:

	ListaPeonesB();
	int getNumero() { return numero; };

	bool agregar(PeonB* p);
	void dibuja();
	void mueve(unsigned char key, int s);

	int seleccionPieza(unsigned char key);

	void eliminar(int index);
	void eliminar(PeonB* e);


	void destruircontenido();

};