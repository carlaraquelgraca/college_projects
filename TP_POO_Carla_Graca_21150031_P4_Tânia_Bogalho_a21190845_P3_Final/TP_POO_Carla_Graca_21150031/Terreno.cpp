#include <iostream>
#include <string>
#include "Terreno.h"
#include "Ponto.h"
#include "Mundo.h"
#include "Consola.h"
using namespace std;

Terreno::Terreno(string identidade,Ponto ponto):id(identidade),p(ponto)
{
}
Terreno::~Terreno()
{
}

string Terreno::getAsString() const{
	ostringstream oss;

	oss << "\tPos: " << p;

	return oss.str();
}

Terreno * Terreno::duplica()const
{

	return new Terreno( *this);
}


string Terreno::getId() const
{
	return id;
}

Ponto Terreno::getPos() 
{
	return p;
}
void Terreno::agir(Mundo *m)
{
}