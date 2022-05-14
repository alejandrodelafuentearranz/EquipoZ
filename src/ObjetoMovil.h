#pragma once
#include "vector2D.h"

class ObjetoMovil {
protected: 
	Vector2D posicion;
	Vector2D aceleracion;
	Vector2D velocidad;
	Vector2D origen;
	
public: 

	virtual void mueve(unsigned char t);  

	Vector2D getPos();

	void setPos(Vector2D pos);

	void setPos(float x, float y);

	void setVel(float vx, float vy);

	void setVel(Vector2D vel);
 };
