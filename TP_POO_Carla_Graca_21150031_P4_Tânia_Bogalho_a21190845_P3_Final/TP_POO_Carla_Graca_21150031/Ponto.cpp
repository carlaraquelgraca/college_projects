#include <iostream>
#include "Ponto.h"  

Ponto::Ponto(int xx, int yy):x(xx),y(yy)
{
}

Ponto::~Ponto()
{

}


int Ponto::getX() const
{
	return x;
}

int Ponto::getY() const
{
	return y;
}

void Ponto::setX(int x)
{
	this->x = x;
}

void Ponto::setY(int y)
{
	this->y = y;
}

string Ponto::getAsString()const
{
	ostringstream oss;
	oss << "(" << x << " , " << y << ")" ;
	return oss.str();
}

//definição do operador binário == como função global
bool operator==(const Ponto & a, const Ponto & b)
{
	return ((a.getX() == b.getX()) && (a.getY() == b.getY()) );
}

//definição do operador binário != como função global
bool operator!=(const Ponto & a, const Ponto & b)
{
	//return ((a.getX() != b.getX()) || (a.getY() != b.getY()) );
	return !(a == b);
}

ostream & operator<<( ostream & saida, const Ponto & ob)
{
	saida << ob.getAsString();
	return saida;
}

