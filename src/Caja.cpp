#pragma once
#include "Caja.h"
#include "Pared.h"
#include "ETSIDI.h"
#include "freeglut.h"


Caja::Caja()
{
	suelo.setColor(0, 100, 0);
	suelo.setPos(-10.0f, 0, 10.0f, 0);

	techo.setColor(0, 100, 0);
	techo.setPos(-10.0f, 15.0f, 10.0f, 15.0f);

	der.setColor(0, 150, 0);
	der.setPos(-10.0f, 0, -10.0f, 15.0f);

	izq.setColor(0, 150, 0);
	izq.setPos(10.0f, 0, 10.0f, 15.0f);
	
}

Caja::~Caja()
{
}

void Caja::dibuja()
{
	suelo.dibuja();
	techo.dibuja();
	der.dibuja();
	izq.dibuja();
	//dibujo del fondo
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/tablero.4.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex3f(-24, -24, 0);
	glTexCoord2d(1, 1); glVertex3f(24, -24, 0);
	glTexCoord2d(1, 0); glVertex3f(24, 24, 0);
	glTexCoord2d(0, 0); glVertex3f(-24, 24, 0);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}