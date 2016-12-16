#include <iostream>
#include <string>
#include "Pessoa.h"
#include "Ponto.h"
#include "Idoso.h"
#include "Mundo.h"
using namespace std;

int Idoso::tempoInfI = 6;// o tempo de infecção de jovens, tempode infecção de idosos e tempo de imunidade são comuns a todos os objectos da classe mundo e não precisam de existir mundos para serem configurados 

Idoso::Idoso(string letra,int num,Ponto p):Pessoa(letra,num,p)
{

	setTempoVida(14);
}

Idoso::~Idoso()
{
}

void Idoso::setTempoInfI(int tI)
{
	tempoInfI = tI;
}

int Idoso::getTempoInfI()
{
	return tempoInfI;
}

string Idoso::getAsString()const
{
	ostringstream oss;

	if(getNum() < 10)
		oss << "I" << "0" << getNum();
	else
		oss << "I" << getNum();
	return oss.str();
}

Pessoa * Idoso::duplica()const
{
	return new Idoso(*this);
}

Ponto Idoso::move(Mundo *mundo)//movimento do idoso
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

void Idoso::reageInfeccao(Mundo *mundo)//idoso morre após passar tempo de infecção
{

	if(mundo->getNIteracoes() > tempoInfI)
		setTempoVida(0);
}

bool Idoso::getImune() const
{
	return false;
}

void Idoso::setImune()
{
}

