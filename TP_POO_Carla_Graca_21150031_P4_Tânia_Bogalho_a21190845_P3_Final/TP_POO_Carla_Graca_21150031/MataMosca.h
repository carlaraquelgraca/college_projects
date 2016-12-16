#ifndef MATAMOSCA_H_
#define MATAMOSCA_H_
#include <iostream>
#include <string.h>
#include "Pessoa.h"
class Ponto;
class Pessoa;

class MataMosca : public Pessoa
{
private:
	
public:
    MataMosca(string id,int num,Ponto p);
	~MataMosca();
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
	virtual void agir(Mundo m) const ;

   

};
#endif