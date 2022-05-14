#include "Mundo.h"
#include "freeglut.h"
#include"Interaccion.h"
#include "ETSIDI.h"
#include "EsferaPulsante.h"
#include <math.h>

#define MAX_2 2
#define NP 8

int i = 0;

void Mundo::rotarOjo()
{
	float dist=sqrt(x_ojo*x_ojo+z_ojo*z_ojo);
	float ang=atan2(z_ojo,x_ojo);
	ang+=0.05f;
	x_ojo=dist*cos(ang);
	z_ojo=dist*sin(ang);
}
void Mundo::dibuja()
{
	gluLookAt(x_ojo, y_ojo, z_ojo,  // posicion del ojo
			0.0, y_ojo, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el codigo de dibujo
	//dibujo del suelo

	/*glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
		glColor3ub(255,0,0);
		glVertex3f(-5.0f,0,-5.0f);
		glVertex3f(-5.0f,0,5.0f);
		glColor3ub(255,255,0);
		glVertex3f(5.0f, 0, 5.0f);
		glVertex3f(5.0f,0,-5.0f);
	glEnd();
	glEnable(GL_LIGHTING);*/
	ETSIDI::setTextColor(1, 1, 0);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	ETSIDI::printxy("Pang 1.2", -11, 17);
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
	ETSIDI::printxy("Hernando & Rodriguez-Losada", 3.5, 17);
	
	hombre.dibuja();
	//disp.dibuja();
	//disp.estela();
	//esfera.dibuja();
	//esfera2.dibuja();
	caja.dibuja();
	bonus.dibuja();
	plataforma.dibuja();

	esferas.dibuja();
	disparos.dibuja();


	peonesB.dibuja();
	caballosN.dibuja();

	//caballoN.dibuja();
	//peonB.dibuja();
	selector.dibuja();
}

void Mundo::teclaEspecial(unsigned char key)
{
	
	//caballosN.mueve(key);
	switch (key)
	{
	case GLUT_KEY_LEFT:
		//caballosN.mueve(key);
		break;
	case GLUT_KEY_RIGHT:
		//caballosN.mueve(key);
		break;

	}
}

void Mundo::mueve()
{
	bonus.mueve(0.025f);
	hombre.mueve(0.025f);
	
	
	disparos.mueve(0.025f);
	disparos.colision(caja);
	disparos.colision(plataforma);

	
	

	interaccion::rebote(hombre, caja);
	


	esferas.mueve(0.025f);
	esferas.rebote(caja);
	esferas.rebote(plataforma);
	esferas.rebote();
	esferas.colision(hombre);
	Esfera* aux = esferas.colision(hombre);
	if (aux != 0)
	{
		esferas.eliminar(aux);
		ETSIDI::play("sonidos/impacto.wav");
	}

	
}


void Mundo::teclaMueve(unsigned char key)
{
	Vector2D v= selector.getPos();
	selector.mueve(key);
	caballosN.mueve(key, v);
	
}

void Mundo::inicializa()
{
	x_ojo=0;
	y_ojo=0;
	z_ojo=70;

	//tablero inicial con todos sus componentes:  
	
	

	//PEONES BLANCOS

	/*
		for (int i = 0; i < NP; i++) {
		PeonB* aux = new PeonB(inicio, 13);
		peonesB.agregar(aux);
			inicio += 6;
	}
	*/
	
	//CABALLOS NEGROS
	/*
	int inicioc = -18;
	for (int i = 0; i <= MAX_2; i++)
	{
		
		CaballoN* aux = new CaballoN(inicioc, -22);
		caballosN.agregar(aux);
		inicioc += 31;
	}
	*/
	// Inicializar de este modo todas las piezas para comenzar la partida. 
	for (int i = -22; i <= 20; i++)
	{
		if (i == -16 || i == 14) {
			CaballoN* aux = new CaballoN(i, -22);
			caballosN.agregar(aux);
		}
		if (i == -22 || i == -16 || i == -10 || i == -4 || i == 2 || i == 8 || i == 14 || i == 20)
		{
			PeonB* aux = new PeonB(i, 14);
			peonesB.agregar(aux);
		}
	}
	
	


	bonus.setPos(5.0f, 5.0f);

	plataforma.setPos(-5.0f, 9.0f, 5.0f, 9.0f);

	Esfera* esfera1 = new Esfera(1.5, 2, 4, 5, 15);
	esferas.agregar(esfera1);

	Esfera* esfera2 = new Esfera(2, -2, 4, -5, 15);
	esferas.agregar(esfera2);
	/*
	for (int i = 0; i < 6; i++)
	{
		Esfera* aux = new Esfera(0.5+i*0.25, i, i+1, i, i); 
		//aux->setRadio(0.75 + i * 0.25);
		//aux->setPos(i, i+1);
		//aux->setVel(i, i);
		aux->setColor(250, 0, 200);
		esferas.agregar(aux);
	}
	*/
	
	EsferaPulsante* e3 = new EsferaPulsante;
	e3->setColor(0, 255, 0);
	esferas.agregar(e3);
	
}
	

Mundo::~Mundo()
{
	esferas.destruircontenido();
	disparos.destruirContenido();
}

void Mundo::teclaSeleccion(unsigned char key)
{
	
	//caballosN.mueve(key);
	
		
		
	
		selector.mueve(key);
	
		//caballosN.mueve(key, selector.getPos());
	
	switch (key)
	{
	case '1':
		
		break;
	case '2':
		esferas.agregar(new Esfera(1, 0, 10));
		break;
	case '3':
		esferas.agregar(new Esfera(1.5, 0, 10));
		break;
	case '4':
		esferas.agregar(new Esfera(2, 0, 10));
		break;

	case ' ':
		{
			disparo* d = new disparo();
			Vector2D pos = hombre.getPos();
			d->setPos(pos.x, pos.y);
			if (disparos.agregar(d))
				hombre.setVel(0, 0);
			else delete d;
			ETSIDI::play("sonidos/disparo.wav");
			break;

		}

	case 'p':
		peonesB.seleccionPieza(key);

	}
}
