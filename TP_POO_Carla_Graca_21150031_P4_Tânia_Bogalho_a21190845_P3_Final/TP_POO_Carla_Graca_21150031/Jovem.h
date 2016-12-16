#ifndef JOVEM_H_
#define JOVEM_H_
#include <iostream>
#include <string.h>
#include "Pessoa.h"
class Ponto;
class Pessoa;

class Jovem : public Pessoa
{
private:
		bool imune;
		const static int probabImune = 75;
		static int tempoImune;
		static int tempoInfJ;
		//Jovem coloca a 1 o tempode vida se está vivo e a zero se não está

public:
    Jovem(string id,int num,Ponto p);
	static void setTempoInfJ(int iJ);
	static int getTempoInfJ();
	virtual string getAsString() const;
	static void setTempoImunidade(int tIm);
	static int getTempoImunidade();
	virtual bool getImune() const;
	virtual void setImune(bool im);
	virtual Pessoa * duplica()const;
	virtual Ponto move(Mundo *mundo);
	virtual void reageInfeccao(Mundo *mundo);


   

};
#endif