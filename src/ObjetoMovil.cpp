#include"ObjetoMovil.h"

void ObjetoMovil::mueve(unsigned char t)
{
	
	
	switch (t) {
	case '8':
		posicion.y = posicion.y + 6;
		if (posicion.y >= 20)
			posicion.y = 20;
		break;
	case '4':
		posicion.x = posicion.x - 6;
		if (posicion.x <= -22)
			posicion.x = -22;
		break;
	case'2':
		posicion.y = posicion.y - 6;
		if (posicion.y <= -22)
			posicion.y = -22;
		break;
	case '6':
		posicion.x = posicion.x + 6;
		if (posicion.x >= 20)
			posicion.x = 20;
		break;
	}




}

/*
void ObjetoMovil::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	
}
*/

Vector2D ObjetoMovil::getPos()	
{
	Vector2D v; 
	v.x = posicion.x;
	v.y = posicion.y;
	return v;
}

void ObjetoMovil::setPos(Vector2D pos) {
	posicion.x = pos.x;
	posicion.y = pos.y;
}

void ObjetoMovil::setPos(float x, float y) {
	posicion.x = x;
	posicion.y = y;
}

void ObjetoMovil::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

void ObjetoMovil::setVel(Vector2D vel)
{
	velocidad.x = vel.x;
	velocidad.y = vel.y;
}
