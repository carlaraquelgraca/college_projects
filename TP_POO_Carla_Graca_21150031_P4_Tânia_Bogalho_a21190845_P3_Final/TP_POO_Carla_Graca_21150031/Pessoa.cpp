#include <iostream>
#include <string>
#include "Pessoa.h"
#include "Mundo.h"
#include "Ponto.h"
#include "SerVivo.h"
using namespace std;

Pessoa::Pessoa(string id,int num,Ponto p):SerVivo(id,num,p),estado(true)
{
	
}

Pessoa::~Pessoa()
{
}

bool Pessoa::getImune() const
{
	return false;
}


void Pessoa::setImune(bool e)
{
	 
}

bool Pessoa::getEstado() const
{
	return estado;
}


void Pessoa::setEstado(bool e)
{
	 estado = e;
}

string Pessoa::getAsString() const
{
	string inf, im;

	if(estado == true)
	{
		inf = "Saudavel";
	}
	else
		inf = "Infectado";


	ostringstream oss;
	oss << "Estado:\n " << estado ;
	return oss.str();
}

Pessoa * Pessoa::duplica()const
{
	return new Pessoa(*this);
}

void Pessoa:agir(Ponto p) const
{
}


Ponto Pessoa::move(Mundo *mundo)
{
	Ponto ponto(0,0);
	return ponto;
}

void Pessoa::reageInfeccao(Mundo *mundo)
{

}
