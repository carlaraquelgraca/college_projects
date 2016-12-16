#include <iostream>
#include <string>
#include "Terreno.h"
#include "TerrenoNeutro.h"
#include "Ponto.h"
#include "SerVivo.h"
#include "Mundo.h"
using namespace std;

TerrenoNeutro::TerrenoNeutro(string identidade,Ponto ponto):Terreno(identidade,ponto)
{
}

Terreno * TerrenoNeutro::duplica()const
{

	return new TerrenoNeutro(*this);
}

string TerrenoNeutro::getAsString() const
{
	ostringstream oss;

		oss << " ";
	return oss.str();
}

void TerrenoNeutro::agir(Mundo *m)
{
}