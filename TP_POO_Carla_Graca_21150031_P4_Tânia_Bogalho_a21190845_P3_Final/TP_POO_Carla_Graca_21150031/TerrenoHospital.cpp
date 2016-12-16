#include <iostream>
#include <string>
#include "Terreno.h"
#include "TerrenoHospital.h"
#include "Ponto.h"
#include "SerVivo.h"
#include "Mundo.h"
#include "Consola.h"
using namespace std;

TerrenoHospital::TerrenoHospital(string identidade,Ponto ponto):Terreno(identidade,ponto)
{
	
}


string TerrenoHospital::getAsString() const
{
	ostringstream oss;

	oss<< getId();

	return oss.str();
}

Terreno * TerrenoHospital::duplica()const
{

	return new TerrenoHospital(*this);
}

void TerrenoHospital::agir(Mundo *m) //se existir mosquito na posição do hospital elimina-o, se existir uma pessoa infectada,torna-a saudável
{
	Mosquito *mosq = m->pesquisaMosquitoObj(getPos());
	Pessoa *pes = m->pesquisaPessoaObj(getPos());
	
	if(mosq != 0)
	{
		m->removeMosquito(getPos());
		m->setNumMosquitos(m->getNumMosquitos() - 1);
		m->setTotalSeres(m->getTotalSeres() - 1);
	}

	if(pes != 0)
	{
		if(pes->getEstado() == false)
		{
			pes->setEstado(true);
			m->setNSaudavel(m->getNSaudavel() + 1);
		}
	}
	
}

