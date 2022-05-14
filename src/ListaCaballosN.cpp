#include "ListaCaballosN.h"





ListaCaballosN::ListaCaballosN()
{
	numero = 0;
	for (int i = 0; i < MAX_CABALLOS; i++) {
		lista[i] = NULL;//0
	}
}

bool ListaCaballosN::agregar(CaballoN* c)
{
	if (numero >= MAX_CABALLOS) {
		return false;
	}
	else {
		lista[numero] = c;
		numero++;
		return true;
	}
	for (int i = 0; i < numero; i++) {
		if (lista[i] == c);
		return false;
	}
}

void ListaCaballosN::dibuja()
{
	for (int i = 0; i < numero; i++)
	{
		lista[i]->dibuja();

	}
}

void ListaCaballosN::mueve(unsigned char key, Vector2D v)
{

	for (int i = 0; i < numero; i++)
		
		if (v.x == lista[i]->getPos().x && v.y == lista[i]->getPos().y)
		{
			lista[i]->mueve(key); // mover el caballo junto con el selector
			//if (interaccion::CaballoCorrecto(*lista[i], v) && key == 'b')
				//lista[i]->setPos(v);
		}
}


void ListaCaballosN::eliminar(int index)
{
	if (index < 0 || index >= numero)
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
	{
		lista[i] = lista[i + 1];
	}
}

void ListaCaballosN::eliminar(CaballoN* c)
{
	for (int i = 0; i < numero; i++) {
		if (lista[i] == c)
		{
			eliminar(i);
			return;
		}
	}
}

void ListaCaballosN::destruircontenido()
{
	for (int i = 0; i < numero; i++)
		delete(lista[i]);
	numero = 0;
}

int ListaCaballosN::selC(Selector s)
{
	for (int i = 0; i < MAX_CABALLOS; i++)
	{
		if (interaccion::selC(*lista[i], s))
			return i;
		else
			return 0; 
	}
}