#include <iostream>
#include <string>
#include "Pessoa.h"
#include "Ponto.h"
#include "Jovem.h"
#include "Mundo.h"
using namespace std;

int Jovem::tempoInfJ = 3;
int Jovem::tempoImune = 4;
//int Jovem::probabImune = 65;

Jovem::Jovem(string letra,int num,Ponto p):Pessoa(letra,num,p),imune(false)
{
	setTempoVida(1);
}

void Jovem::setTempoInfJ(int tJ)
{
	tempoInfJ = tJ;
}

int Jovem::getTempoInfJ()
{
	return tempoInfJ;
}

void Jovem::setTempoImunidade(int tIm)
{
	 tempoImune = tIm;
}

int Jovem::getTempoImunidade()
{
	 return tempoImune;
}

bool Jovem::getImune() const
{
	return imune;
}

void Jovem::setImune(bool im)
{
	imune = im;
}

string Jovem::getAsString()const
{
	ostringstream oss;

	if( getNum() < 10)
		oss << "J" << "0" << getNum();
	else
		oss << "J" << getNum();
	return oss.str();
}

Pessoa * Jovem::duplica()const
{
	return new Jovem(*this);
}

Ponto Jovem::move(Mundo *mundo)
{
	int aleat = rand()%8 + 1;
	Ponto ponto(0,0);

	if(aleat == 1)
	{
		ponto.setX(getPos().getX() + 1);
		ponto.setY(getPos().getY());
	}
	else 
		if(aleat == 2)
		{
			ponto.setX(getPos().getX() - 1);
			ponto.setY(getPos().getY());
		}
	else
		if(aleat == 3)
		{
			ponto.setX(getPos().getX());
			ponto.setY(getPos().getY() + 1);
		}
	else
		if(aleat == 4)
		{
			ponto.setX(getPos().getX());
			ponto.setY(getPos().getY() -  1);
			
		}
	else
		if(aleat == 5)
		{
			ponto.setX(getPos().getX()+ 1);
			ponto.setY(getPos().getY() + 1);
			
		}
	else
		if(aleat == 6)
		{
			ponto.setX(getPos().getX()+ 1);
			ponto.setY(getPos().getY() -  1);
		}
	else
		if(aleat == 7)
		{
			ponto.setX(getPos().getX()- 1);
			ponto.setY(getPos().getY() +  1);
		}
	else
		if(aleat == 8)
		{
			ponto.setX(getPos().getX()- 1);
			ponto.setY(getPos().getY() -  1);
		}

	return ponto;
}

void Jovem::reageInfeccao(Mundo *m)//reacção à infecção do jovem: jovem tem probabilidade de ficar imune após passar tempo de infecção. se passar o tempo de imunidade volta a ficar saudável.se não tiver ficado imune,após tempo de infecção morre
{
	int aleat = rand()%100 +1;

	if(m->getNIteracoes() > tempoImune && imune == true)
	{
		setEstado(true);
		imune = false;
		m->setNSaudavel(m->getNSaudavel() + 1);
	}

	if(m->getNIteracoes() > tempoInfJ && (getEstado() == false))
	{
		if(aleat >=1 && aleat <=probabImune)
		{
			imune = true;
		}
		else if (aleat > probabImune && aleat <= 100)
		{
			setTempoVida(0);
		}
	}
}

