#pragma once
#include "Hombre.h"
#include "Caja.h"
#include "Esfera.h"
#include"Pared.h"
#include "Disparo.h"
#include "Selector.h"

#include"CaballoN.h"





class interaccion {
public:

	static void rebote(hombre& h, Caja c);
	static bool rebote(Esfera& e, pared p);
	static void rebote(Esfera& e, Caja c);
	static bool rebote(Esfera& e1, Esfera& e2);
	static bool colision(Esfera& e, hombre h);

	static bool colision(disparo& d, pared p);
	static bool colision(disparo& d, Caja c);

	static bool selC(CaballoN& c, Selector s);

	bool sitioCCorrecto(Selector& s, Vector2D p);

	static bool CaballoCorrecto(CaballoN& c, Vector2D v);
};