
#pragma once
#include "vector2D.h"
#include"ObjetoMovil.h"



class disparo : public ObjetoMovil
{
private: 
	float radio;
	float alturaest;

	Vector2D origen;
public:

	disparo();
	virtual ~disparo();

	


	void dibuja();
	
	void estela(); 

	void setPos(Vector2D pos);
	void setPos(float x, float y);
	Vector2D getPos();
	float getRadio();

};