#ifndef PESSOA_H_
#define PESSOA_H_
#include <iostream>
#include "SerVivo.h"
using namespace std;


class Pessoa : public SerVivo{

private:
	

	bool estado;// true é saudável que é cor verde, false é infectado que é cor vermelha

public:
	Pessoa(string id,int num,Ponto p);
	~Pessoa();
	void agirHospital(Mundo *m);
	virtual Pessoa * duplica()const;
	virtual bool getImune() const;
	virtual void setImune(bool im);
	virtual Ponto move(Mundo *mundo);
	virtual string getAsString() const;
	void agirPantano(Mundo *m);
	bool getEstado() const;
    void setEstado(bool inf);
	virtual void reageInfeccao(Mundo *mundo);
	virtual void agir(Mundo m) const ;
};




#endif