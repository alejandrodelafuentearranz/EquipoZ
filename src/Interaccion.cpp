#include "Interaccion.h"
#include "Hombre.h"
#include "Caja.h"
#include "Pared.h"
#include "Esfera.h"

void interaccion::rebote(hombre &h, Caja c)
{
	float xmax = c.suelo.limite2.x;
	float xmin = c.suelo.limite1.x;
	if (h.posicion.x > xmax)h.posicion.x = xmax;
	if (h.posicion.x < xmin)h.posicion.x = xmin;

}

bool interaccion::rebote(Esfera &e, pared p)
{

	Vector2D dir;
	float dif = p.distancia(e.posicion, &dir) - e.radio;
	if (dif <= 0)
	{
		Vector2D v_inicial = e.velocidad;
		e.velocidad = v_inicial - (dir * 2.0 * (v_inicial * dir));
		e.posicion = e.posicion - (dir * dif );
		return true;
	}
	return false;
}

void interaccion::rebote(Esfera &e, Caja c)
{
	rebote(e, c.suelo);
	rebote(e, c.izq);
	rebote(e, c.der);
	rebote(e, c.techo);
}

bool interaccion::rebote(Esfera& e, Esfera& e2)
{
	Vector2D dif = e2.posicion - e.posicion; //Vector que une los centros de las esferas
	float u = dif.modulo(); //Distancia entre centro de las esferas
	float colision = u - (e.radio + e2.radio); //Diferencia entre la distancia del centro de las esferas y la suma de los radios
	if (colision < 0.0f) {
		float v1 = e.velocidad.modulo(); //Modulo velocidad esfera 1
		float v2 = e2.velocidad.modulo(); //Modulo velocidad esfera 2
		float av1 = e.velocidad.argumento(); //Angulo velocidad esfera 1 
		float av2 = e2.velocidad.argumento(); //Angulo velocidad esfera 2
		float adif = dif.argumento(); //Angulo del vector que une los centros de las esferas
		Vector2D desp = (colision / 2 * cos(adif), colision / 2 * sin(adif)); //Cuando colisionan hay que separar las esferas la distancia que se hayan incrustado
		e.posicion = e.posicion + desp; //Desplaza la mitad de la distancia que se ha incrustado
		e2.posicion = e2.posicion + desp; //Desplaza la mitad de la distancia que se ha incrustado
		adif = adif - 3.14159f / 2; //Giro el angulo de referencia (que es el del vector que une los centros) -pi/2
		/*Este giro es para que las esferas tomen la direccion que deben al rebotar*/
		float a1 = av1 - adif; //Giro angulo velocidad esfera 1
		float a2 = av2 - adif; //Giro angulo velocidad esfera 2
		float w1x = v1 * cos(a1); //Componente x velocidad 1 girada
		float w1y = v1 * sin(a1); //Componente y velocidad 1 girada
		float w2x = v2 * cos(a2); //Componente x velocidad 2 girada
		float w2y = v2 * sin(a2); //Componente y velocidad 2 girada
		float v1x = w1x;
		float v2x = w2x;
		float m1 = e.radio; //El enunciado dice que las masas estan relacionadas con los radios
		float m2 = e2.radio;
		float py = m1 * w1y + m2 * w2y; //Conservacion del momento en y
		float ey = m1 * w1y * w1y + m2 * w2y * w2y; //Conservacion de la energia cinetica en y
		float a = m2 * m2 + m1 * m2;
		float b = -2 * py * m2;
		float c = py * py - m1 * ey;
		float discriminante = b * b - 4 * a * c;
		if (discriminante < 0)discriminante = 0;
		float v2y = (-b + sqrt(discriminante)) / (2 * a);
		float v1y = (py - m2 * v2y) / m1;
		float modv1, modv2, fi1, fi2;
		modv1 = sqrt(v1x * v1x + v1y * v1y);
		modv2 = sqrt(v2x * v2x + v2y * v2y);
		fi1 = adif + atan2(v1y, v1x);
		fi2 = adif + atan2(v2y, v2x);
		e.velocidad.x = modv1 * cos(fi1);
		e.velocidad.y = modv1 * sin(fi1);
		e2.velocidad.x = modv2 * cos(fi2);
		e2.velocidad.y = modv2 * sin(fi2);
	}
	return false;
}

bool interaccion::colision(Esfera& e, hombre h)
{
	Vector2D pos = h.getPos(); //la posicion de la base del hombre 
	pos.y += h.getAltura() / 2.0f; //posicion del centro
	float distancia = (e.posicion - pos).modulo();
	if (distancia < e.radio)
		return true;
	return false;
}

bool interaccion::colision(disparo &d, pared p)
	{
		Vector2D dir;
		float dif = p.distancia(d.getPos(), &dir) - d.getRadio();
		if (dif <= 0.0f) return true;
		return false;
	}

bool interaccion::colision(disparo &d, Caja c)
{
	if (colision(d, c.techo)) return true;
	return false;
}

bool interaccion::selC(CaballoN &c, Selector s)
{
	
		Vector2D dif = s.getPos() - c.getPos();
		float u = dif.modulo();
		if (u <= 2.0)
		return true;
		else return false;
		
		
	
}

bool interaccion::sitioCCorrecto(Selector &s, Vector2D p)
{
	if (s.getPos().x == p.x + 6 && s.getPos().y == p.y + 12)
		return true;
	else return false;

	/*
	for (float i = 6; i <= 12; i + 6)
	{
		for (float j = 6; j >= 0; j - 3)
		{

			if (c.getPos().x == p.x + i && c.getPos().y == p.y + j)
				return true;
			else if ((c.getPos().x == p.x + i) && (c.getPos().y == p.y - j))
				return true;
			else if (c.getPos().x == p.x - i && c.getPos().y == p.y + j)
				return true;
			else if ((c.getPos().x == p.x - i) && (p.y - j))
				return true;
			else
				return false;
		}
	}
	*/

}


bool interaccion::CaballoCorrecto(CaballoN& c, Vector2D p)
{
	if (c.getPos().x == p.x + 6 && c.getPos().y == p.y + 12)
		return true;
	else return false;

		/*
		for (float i = 6; i <= 12; i + 6)
		{
			for (float j = 6; j >= 0; j - 3)
			{

				if (c.getPos().x == p.x + i && c.getPos().y == p.y + j)
					return true;
				else if ((c.getPos().x == p.x + i) && (c.getPos().y == p.y - j))
					return true;
				else if (c.getPos().x == p.x - i && c.getPos().y == p.y + j)
					return true;
				else if ((c.getPos().x == p.x - i) && (p.y - j))
					return true;
				else
					return false;
			}
		}
		*/

	}




