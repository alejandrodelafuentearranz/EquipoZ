#include "CaballoN.h"
#include "ETSIDI.h"


CaballoN::CaballoN(float x, float y)
{
	posicion.x = x;  //13
	posicion.y = y; // -22
}
CaballoN::~CaballoN()
{
}

void CaballoN::dibuja()
{

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/caballo.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	/*
	* glTexCoord2d(0, 1); glVertex3f(-12, -12, 1);
	glTexCoord2d(1, 1); glVertex3f(12, -12 ,1);
	glTexCoord2d(1, 0); glVertex3f(12, 12, 1);
	glTexCoord2d(0, 0); glVertex3f(-12, 12, 1);
	*/
	glTexCoord2d(0, 1); glVertex3f(posicion.x, posicion.y, 1);
	glTexCoord2d(1, 1); glVertex3f(posicion.x + 3, posicion.y, 1);
	glTexCoord2d(1, 0); glVertex3f(posicion.x + 3, posicion.y + 3, 1);
	glTexCoord2d(0, 0); glVertex3f(posicion.x, posicion.y + 3, 1);



	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);



}

void CaballoN::mueveC(unsigned char key)
{
	
	switch (key)
	{
	case '1':
		posicion.x = posicion.x + 6;
		posicion.y = posicion.y + +6;
		setPos(posicion.x, posicion.y);
		break;
	}
	
}

/*void CaballoN::mueve(float t)
{
	//posicion.x = posicion.x + 6;
	//posicion.y = posicion.y + 12;
}
*/
