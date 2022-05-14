#pragma once
#include "Esfera.h"
#include "vector2D.h"

class EsferaPulsante : public Esfera
{
protected:

	float pulso;
	float radio_max;
	float radio_min;
public:
	EsferaPulsante();
	void mueve(float t);

};