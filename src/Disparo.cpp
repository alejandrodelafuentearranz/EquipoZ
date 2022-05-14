#include "Disparo.h"	

disparo::disparo()
{
	radio = 0.25;
	//posicion.x = 0;
	//posicion.y = -5;
	radio = 0.25f;
	aceleracion.y = 0;
	velocidad.y = 2;
	alturaest = 0;
}

disparo::~disparo()
{
}

void disparo::dibuja()
{
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glPopMatrix();

	glBegin(GL_LINES);
	glVertex3d(origen.x, origen.y , 0);
	glVertex3d(posicion.x, posicion.y, 0);
	glEnd();
}


void disparo::estela()
{
	/*
	glColor3f(0.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.25f, alturaest, 20, 20);
	glPopMatrix();

	glBegin(GL_LINES);
	glVertex3d(origen.x, origen.y -5, 0);
	glVertex3d(posicion.x, posicion.y, 0);
	glEnd();
	*/
}





Vector2D disparo::getPos()
{
	return posicion;
}

void disparo::setPos(Vector2D pos)
{
	posicion.x = pos.x;
	posicion.y = pos.y;
}




void disparo::setPos(float x, float y){
posicion.x = origen.x  = x;
posicion.y = origen.y = y;
}


float disparo::getRadio()
{

	return radio;
}





