#include "ListaPeonesB.h"
ListaPeonesB::ListaPeonesB()
{
	numero = 0;
	for (int i = 0; i < MAX_PEONES; i++) {
		lista[i] = NULL;//0
	}
}

bool ListaPeonesB::agregar(PeonB* p)
{
	if (numero >= MAX_PEONES) {
		return false;
	}
	else {
		lista[numero] = p;
		numero++;
		return true;
	}
	for (int i = 0; i < numero; i++) {
		if (lista[i] == p);
		return false;
	}
}

void ListaPeonesB::dibuja()
{
	for (int i = 0; i < numero; i++)
	{
		lista[i]->dibuja();

	}
}

void ListaPeonesB::mueve(unsigned char key, int s)
{
		lista[s]->mueve(key);
}

int ListaPeonesB::seleccionPieza(unsigned char key)
{
	for (int i = 0; i < MAX_PEONES; i++) {
		if (key == i)
			return i;
	}
	return 0;

}

void ListaPeonesB::eliminar(int index)
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

void ListaPeonesB::eliminar(PeonB* e)
{
	for (int i = 0; i < numero; i++) {
		if (lista[i] == e)
		{
			eliminar(i);
			return;
		}
	}
}

void ListaPeonesB::destruircontenido()
{
	for (int i = 0; i < numero; i++)
		delete(lista[i]);
	numero = 0;
}