#include"bonus.h"
#include "freeglut.h"
#include <stdlib.h>

Bonus::Bonus()
{
	lado = 0.25;
}

Bonus::~Bonus()
{
}

void Bonus::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);   //color aleatorio
	glutSolidCube(lado);
	glPopMatrix();

}



