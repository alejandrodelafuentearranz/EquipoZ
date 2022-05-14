#include"CoordinadorPang.h"

CoordinadorPang::CoordinadorPang()
{
	estado = INICIO;
}

CoordinadorPang::~CoordinadorPang()
{
}

void CoordinadorPang::teclaEspecial(unsigned char key)
{
	if (estado == JUEGO)
		mundo.teclaEspecial(key);

}

void CoordinadorPang::teclaSeleccion(unsigned char key)
{
}

void CoordinadorPang::teclaMueve(unsigned char key)
{
}

void CoordinadorPang::tecla(unsigned char key)
{
	if (estado == INICIO) {
		mundo.inicializa();
		if (key == 'e')
			estado = JUEGO;
		else if (key == 's')
			exit(1);
	}
	else if (estado == JUEGO) {
		//SELECCIÓN PIEZA
			mundo.teclaSeleccion(key);

			if (key == 'o')
			{
				estado = MUEVE;

			}
	}
	else if (estado == MUEVE)
	{
		mundo.teclaMueve(key);
		//if (key == 'o')
			//mundo.setPos();
		//else 
		if (key == 'b')
			estado = JUEGO;
	}

}

void CoordinadorPang::mueve()
{
	if (estado == JUEGO)
		mundo.mueve(); 
}

void CoordinadorPang::dibuja()
{ 
	// Codigo para escribir arriba del todo 
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("Pang 1.1", -10, 17);
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
	ETSIDI::printxy("Hernando & Rodriguez-Losada", -10, 16.4);


	if (estado == INICIO)

	{//CODIGO PARA PINTAR UNA PANTALLA NEGRA CON LETRAS
		gluLookAt(0, 7.5, 30, // posicion del ojo
			0.0, 7.5, 0.0, // hacia que punto mira (0,7.5,0)
			0.0, 1.0, 0.0); // definimos hacia arriba (eje Y)
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("Pang 1.1", -5, 8);
		ETSIDI::setTextColor(1, 1, 1);
		ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
		ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);
		ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
		ETSIDI::printxy("Hernando & Rodriguez-Losada", 2, 1);
	}
	else if (estado == JUEGO||estado==MUEVE)
		mundo.dibuja();
	

}


