#include "Selector.h"

Selector::Selector(float r, float px, float py)
{
	radio = r;
	posicion.x = px;
	posicion.y = py;
	rojo = verde = azul = 255; //blanco
	radio = 1.0f;
}

Selector::~Selector()
{
}

void Selector::dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}

Vector2D Selector::seleccion(unsigned char key)
{
	/*
	Vector2D pieza;
	if (key == 's') {
		pieza.x= getPos().x
	}
	*/
	return (0,0);
}
