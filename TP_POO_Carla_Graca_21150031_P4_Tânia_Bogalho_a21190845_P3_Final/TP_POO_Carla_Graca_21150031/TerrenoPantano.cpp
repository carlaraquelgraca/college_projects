#include <iostream>
#include <string>
#include "Terreno.h"
#include "TerrenoPantano.h"
#include "Ponto.h"
#include "SerVivo.h"
#include "Mundo.h"
#include "Consola.h"
using namespace std;

TerrenoPantano::TerrenoPantano(string identidade,Ponto ponto):Terreno(identidade,ponto)
{
	
}


string TerrenoPantano::getAsString() const
{
	ostringstream oss;

	oss << getId();
	return oss.str();
}

Terreno * TerrenoPantano::duplica()const //cria cópia dos terrenos
{

	return new TerrenoPantano(*this);
}

void TerrenoPantano::agir(Mundo *m) // acrescenta mosquitos a cada nono instante e se houver pessoa na sua posição remove-a se ela estiver infectada
{

	Mosquito *mosq = m->pesquisaMosquitoObj(getPos());
	Pessoa *pes = m->pesquisaPessoaObj(getPos());
	
	if(mosq == 0 && m->getNIteracoes() == 9)
		m->acrescentaMosquito();

	if(pes != 0)
	{
		if(pes->getEstado()== false)
			m->removePessoa(getPos());
	}
}