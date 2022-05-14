#pragma once
#include "ObjetoMovil.h"
#include "ETSIDI.h"

class PeonB : public ObjetoMovil
{
public:
	//PeonB();
	
	PeonB(float px=0.0, float py=0.0);
	virtual ~PeonB();

	void dibuja();
	//void mueve()

};