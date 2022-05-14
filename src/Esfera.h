#pragma once
#include"ObjetoMovil.h"

#include "vector2D.h"

class Esfera : public ObjetoMovil
{
protected: 
	unsigned char rojo;
	unsigned char verde;
	unsigned char azul;
	float radio;
	

public:
	 
	Esfera();
	Esfera(float r, float x=0.0, float y=0.0, float vx=0.0, float vy=0.0);
	virtual ~Esfera();
	void setColor(unsigned char r, unsigned char v, unsigned char a);
	void setRadio(float r);
	
	void dibuja(); 
	
	
	friend class interaccion;

};