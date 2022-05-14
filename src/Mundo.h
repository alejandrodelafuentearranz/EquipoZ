#pragma once
#include "Hombre.h"
#include "Disparo.h"
#include "Caja.h"
#include "Esfera.h"
#include "Pared.h"
#include "Bonus.h"
#include "ListaEsferas.h"
#include "ListaDisparos.h"

#include  "ListaPeonesB.h"
#include "ListaCaballosN.h"

#include "EsferaPulsante.h"

#include "CaballoN.h"
#include "PeonB.h"
#include "Selector.h"




class Mundo
{

private:
	float x_ojo;
	float y_ojo;
	float z_ojo;
	

	ListaPeonesB peonesB;
	ListaCaballosN caballosN;

	ListaEsferas esferas; 
	ListaDisparos disparos;
	hombre hombre;
	//disparo disp;
	disparo estela;
	Caja caja;
	Esfera esfera, esfera2;
	pared plataforma;
	Bonus bonus; 
	PeonB peonB;
	CaballoN caballoN;
	Selector selector;

public: 
	
	virtual~Mundo();
	void teclaSeleccion(unsigned char key);
	void teclaMueve(unsigned char key);
	void inicializa();
	void rotarOjo();
	void mueve();
	void dibuja();

	void teclaEspecial(unsigned char key);
	

};
