#include "ListaDisparos.h"

ListaDisparos::ListaDisparos()
{
	numero = 0; 
	for (int i = 0; i < MAX_DISPAROS; i++) {
		lista[i] = NULL;//0
	}
}

ListaDisparos::~ListaDisparos()
{
}

bool ListaDisparos::agregar(disparo* d)
{
	if (numero >= MAX_DISPAROS) {
		return false;
	}
	else {
		lista[numero] = d;
		numero++;
		return true;
	}
	for (int i = 0; i < numero; i++) {
		if (lista[i] == d);
		return false;
	}
}

void ListaDisparos::dibuja()
{
	for (int i = 0; i < numero; i++)
	{
		lista[i]->dibuja();
	}
}

void ListaDisparos::mueve(float t)
{
	for (int i = 0; i < numero; i++)
	{
		lista[i]->mueve(t);
	}
}

void ListaDisparos::colision(pared p)
{
	for (int i = 0; i < numero; i++) {
		if (interaccion::colision(*(lista[i]), p))
			lista[i]->setVel(0, 0);
	}
}

void ListaDisparos::colision(Caja c)
{
	for (int i = 0; i < numero; i++)
	{
		if (interaccion::colision(*(lista[i]), c))
			lista[i]->setVel(0, 0);
	}
}

void ListaDisparos::destruirContenido()
{
	for (int i = 0; i < numero; i++)
		delete(lista[i]);
	numero = 0;
}

void ListaDisparos::eliminar(int index)
{
	if ((index < 0) || (index >= numero))return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++) {
		lista[i] = lista[i + 1];
	}
}

void ListaDisparos::eliminar(disparo* d)
{
	for (int i = 0; i < numero; i++) {
		if (lista[i] == d) {
			eliminar(i);
			return;
		}
	}
	
}

float ListaDisparos::getNumero()
{
	return numero;
}

disparo* ListaDisparos::operator[](int i)
{
	if (i >= numero)
		i = numero - 1;
	if (i < 0)
		i = 0;
	return lista[i];
}


