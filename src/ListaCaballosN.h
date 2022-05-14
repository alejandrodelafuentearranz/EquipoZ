#pragma once
#include "CaballoN.h"
#include "Interaccion.h"
#include "Selector.h"
#include "vector2D.h"

#define MAX_CABALLOS 2
class ListaCaballosN
{
	private:
		int numero;
		CaballoN* lista[MAX_CABALLOS];

	public:

		ListaCaballosN();
		int getNumero() { return numero; };

		bool agregar(CaballoN* c);
		void dibuja();
		void mueve(unsigned char key, Vector2D v);


		void eliminar(int index);
		void eliminar(CaballoN* e);


		void destruircontenido();

		int selC(Selector s);

	};


