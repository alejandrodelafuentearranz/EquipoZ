#pragma once
#include "Vector2D.h"
#include "ObjetoMovil.h"
#include "ETSIDI.h"

using ETSIDI::SpriteSequence;

class hombre : public ObjetoMovil
{
private:
	float altura;
	SpriteSequence sprite{ "imagenes/pangPlayer.png", 5 };
	

public:
	hombre();
	virtual~hombre();
	
	
	float getAltura();
	 
	Vector2D getPos();

	void dibuja();

	void mueve(float t);
	
	
	friend class interaccion;
};