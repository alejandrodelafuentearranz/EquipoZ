#include"ListaEsferas.h"
//#include "Interaccion.h"

ListaEsferas::ListaEsferas()
{
	numero = 0;
	for (int i = 0; i < MAX_ESFERAS; i++) {
		lista[i] = NULL;//0
	}
}


bool ListaEsferas::agregar(Esfera* e)
{
	/**/
	if (numero >= MAX_ESFERAS) {
		return false;
	}
	else {
		lista[numero] = e;
		numero++;
		return true; 
	}
	for (int i = 0; i < numero; i++){
			if (lista[i] == e);
			return false; 
	}
	
}

void ListaEsferas::dibuja()
{
	for (int i = 0; i < numero; i++)
	{
		lista[i]->dibuja();

	}
}

void ListaEsferas::mueve(float t)
{

	for (int i = 0; i < numero; i++)
	{
		lista[i]->mueve(t);

	}
}

void ListaEsferas::rebote(pared p)
{
	for (int i = 0; i < numero; i++)
	{
		interaccion::rebote(*lista[i], p); 
	}
}
	


void ListaEsferas::rebote()
{
	for (int i = 0; i < numero; i++)
	{
		for (int j = 0; j < numero; j++)
		{
			if (i == j)continue;

			interaccion::rebote(*lista[i], *lista[j]);
		}
	}
}

void ListaEsferas::rebote(Caja c)
{
	for (int i = 0; i < numero; i++)
	{
		interaccion::rebote(*lista[i], c);
	}
}

void ListaEsferas::eliminar(int index)
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

void ListaEsferas::eliminar(Esfera*e)
{
	for (int i = 0; i < numero; i++) {
		if (lista[i] == e)
		{
			eliminar(i); 
			return;
		}
	}
}

Esfera* ListaEsferas::colision(hombre& h)
{
	for (int i = 0; i < numero; i++) {
		if (interaccion::colision(*(lista[i]), h)) {
			return lista[i]; 
		}
		return 0; // ninguna esfera ha chocado
	}
	return 0;
}

Esfera* ListaEsferas::operator[](int i)
{
	if (i >= numero)//si me paso, devuelvo la ultima
		i = numero - 1;
	if (i < 0) //si el indice es negativo, devuelvo la primera
		i = 0;
	return lista[i];
}






void ListaEsferas::destruircontenido()
{
	for (int i = 0; i < numero; i++)
		delete(lista[i]);
	numero=0;
}

