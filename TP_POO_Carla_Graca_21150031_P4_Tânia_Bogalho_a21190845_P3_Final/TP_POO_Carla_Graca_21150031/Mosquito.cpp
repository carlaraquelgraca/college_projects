#include <iostream>
#include <string>
#include "Mosquito.h"
#include "Terreno.h"
#include "Pessoa.h"
using namespace std;

Mosquito::Mosquito(string letra,int num,Ponto p):SerVivo(letra,num,p)
{
	setTempoVida(10);
}

Ponto Mosquito::move(Mundo *m)//movimento do mosquito
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


string Mosquito::getAsString() const
{
	ostringstream oss;

	if( getNum() < 10)
		oss << "M" << "0" << getNum();
	else
		oss << "M" << getNum();
	return oss.str();
}

Mosquito * Mosquito::duplica()const
{
	return new Mosquito(*this);
}
