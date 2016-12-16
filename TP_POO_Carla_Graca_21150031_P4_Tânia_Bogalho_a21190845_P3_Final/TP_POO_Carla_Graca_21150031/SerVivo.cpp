#include <iostream>
#include <sstream>
#include "SerVivo.h"
#include "Ponto.h"
#include "Consola.h"
using namespace std;

int SerVivo::ordem = 0;

SerVivo::SerVivo(string letra,int n,Ponto newP):id(letra),num(n),p(newP)
{
	 
}


SerVivo::~SerVivo()
{
}

int SerVivo::getTempoVida() const
{
	return tempoVida;
}

void SerVivo::setTempoVida(int tv)
{
	tempoVida = tv;
}

string SerVivo::getAsString() const
{
	ostringstream oss;
	oss << "Id: " << num;
	return oss.str();
}


int SerVivo::getOrdem()
{
	return ordem;
}

Ponto SerVivo::getPos() 
{
	return p;
}

void SerVivo::setPos(Ponto ponto) 
{
	p = ponto ;
}

void SerVivo::setOrdem(int o)
{
	ordem = o;
}

string SerVivo::getId() const
{
	return id;
}

void SerVivo::setId(int idd)
{
	id = idd;
}

int SerVivo::getNum() const
{
	return num;
}

void SerVivo::setNum(int n)
{
	num = n;
}
Ponto SerVivo::move(Mundo *m)
{
	Ponto(0,0);

	return p;

}