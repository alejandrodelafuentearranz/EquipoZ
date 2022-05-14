#include "EsferaPulsante.h"

EsferaPulsante::EsferaPulsante()
{
	pulso = 0.5f;
	radio_max = 2.0f;
	radio_min = 0.5f;
	aceleracion = 0;
	posicion.y = 5;
}

void EsferaPulsante::mueve(float t)
{

	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	if (radio > radio_max)
		pulso = -pulso;
	if (radio < radio_min)
		pulso = -pulso;
	radio += pulso * t;
	rojo = radio * 255;
	verde = 255 - radio * 100;
	azul = 100 + radio * 50;
}

