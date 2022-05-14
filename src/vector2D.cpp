/*#include"vector2D.h"
#include "math.h"


Vector2D::Vector2D(float xv, float yv)
{
	x = xv;
	y = yv;
}

float Vector2D::modulo()
{
		return(float)sqrt((x * x) + (y * y));
}

float Vector2D::argumento()
{
	return (float)atan2(y, x);
}

Vector2D Vector2D::unitario()
{
	Vector2D retorno;
	float mod = modulo();
	if (mod > 0.00001)
	{
		retorno.x /= mod;
		retorno.y /= mod;
	}
	return retorno;
}

Vector2D Vector2D:: operator+ (Vector2D v)
{
	Vector2D resultado;
	resultado.x = x + v.x;
	resultado.y = y + v.y;
	return resultado;
	
}

Vector2D Vector2D::operator-(Vector2D v)
{
	Vector2D res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;
	 

}

/*Vector2D Vector2D::operator+(float real)
{
	Vector2D resultado;
	resultado.x = x + real;
	resultado.y = y+ real;

	return resultado;
}
float Vector2D::operator * (Vector2D v) {
	float a = x * v.x;
	float b = y * v.y;
	return (a + b);
}
Vector2D Vector2D::operator * (float i) {
	Vector2D res;
	res.x = x * i;
	res.y = y * i;
	return res;
}

*/








#include "Vector2D.h"
#include <math.h>
Vector2D::Vector2D(float xv, float yv)
{
	x = xv;
	y = yv;
}
float Vector2D::modulo()
{
	return (float)sqrt(x * x + y * y);
}
float Vector2D::argumento()
{
	return (float)atan2(y, x);
}
Vector2D Vector2D::unitario()
{
	Vector2D retorno(x, y);
	float mod = modulo();
	if (mod > 0.00001)
	{
		retorno.x /= mod;
		retorno.y /= mod;
	}
	return retorno;
}
Vector2D Vector2D::operator - (Vector2D v)
{
	Vector2D res;
	res.x = x - v.x;
	res.y = y - v.y;
	return res;
}
Vector2D Vector2D::operator + (Vector2D v)
{
	Vector2D res;
	res.x = x + v.x;
	res.y = y + v.y;
	return res;
}
float Vector2D::operator * (Vector2D v) {
	float a = x * v.x;
	float b = y * v.y;
	return (a + b);
}
Vector2D Vector2D::operator * (float i) {
	Vector2D res;
	res.x = x * i;
	res.y = y * i;
	return res;
}