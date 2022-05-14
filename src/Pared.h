#pragma once
#include"vector2D.h"

class pared {
private:
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	Vector2D limite1;
	Vector2D limite2;
public:
	pared();
	virtual~pared();
	

	void dibuja();
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void setPos(float x1, float y1, float x2, float y2);
	float distancia (Vector2D punto, Vector2D* direccion = 0);
	friend class interaccion;
};