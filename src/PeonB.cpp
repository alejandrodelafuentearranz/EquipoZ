#include "PeonB.h"
#include "freeglut.h"

/*
PeonB::PeonB()
{
	posicion.x = 1.5;
	posicion.y = 13;
}
*/

PeonB::PeonB(float px, float py)
{
	posicion.x = px;
	posicion.y = py;
}


PeonB::~PeonB()
{
}

void PeonB::dibuja()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/peonB.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(posicion.x, posicion.y, 1);
	glTexCoord2d(1, 1); glVertex3f(posicion.x + 3, posicion.y, 1);
	glTexCoord2d(1, 0); glVertex3f(posicion.x + 3, posicion.y + 3, 1);
	glTexCoord2d(0, 0); glVertex3f(posicion.x, posicion.y + 3, 1);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}
