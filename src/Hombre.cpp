#include"Hombre.h"

hombre::hombre()
{
	sprite.setCenter(1, 0);
	sprite.setSize(2, 2);

	altura = 1.8f;
	aceleracion.y = 0;

}

hombre::~hombre()
{
	
}

float hombre::getAltura()
{
	return altura;

}

Vector2D hombre::getPos()
{
	return posicion;
}


void hombre::dibuja()
{
glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	//glutSolidSphere(altura, 20, 20);
	//gestion de direccion y animacion
	if (velocidad.x > 0.01)sprite.flip(false, false);
	if (velocidad.x < -0.01)sprite.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		sprite.setState(0);
	else if (sprite.getState() == 0)
		sprite.setState(1, false);
	sprite.draw();
	glPopMatrix();


}
void hombre::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * (0.5f * t * t);
	velocidad = velocidad + aceleracion * t;
	sprite.loop();
}






