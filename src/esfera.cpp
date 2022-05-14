#include "Esfera.h"
// #include "freeglut.h"

Esfera::Esfera()
{
	rojo = verde = azul = 255; //blanco
	radio = 1.0f;
	aceleracion.y = -9.8f;
}

Esfera::Esfera(float r, float x, float y, float vx, float vy)
{
	radio = r;	
	posicion.x = x;
	posicion.y = y;
	velocidad.x = vx;
	velocidad.y = vy;
}



Esfera::~Esfera()
{
}

void Esfera::dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}


/*
* Vector2D Esfera::getPos()
{
	return posicion;
}
void Esfera::setPos(float posx, float posy)
{
	posicion.x = posx;
	posicion.y = posy;
	
}

void Esfera::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}
*/

void Esfera::setColor(unsigned char r, unsigned char v, unsigned char a)
{
	rojo = r;
	verde = v;
	azul = a;

}

void Esfera::setRadio(float r)
{
	radio = r;
}


