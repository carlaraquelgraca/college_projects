#ifndef IDOSO_H_
#define IDOSO_H_
#include <iostream>
#include "Pessoa.h"
using namespace std;


class Mundo;
class Ponto;
class SerVivo;

class Idoso : public Pessoa
{

private:
		static int tempoInfI;
		

public:
	Idoso(string id,int num,Ponto p);
	~Idoso();
	static void setTempoInfI(int infI);
	static int getTempoInfI();
	virtual string getAsString() const;
	virtual Pessoa * duplica()const;
	virtual Ponto move(Mundo *mundo);
	virtual void reageInfeccao(Mundo *mundo);
	virtual bool getImune() const;
	virtual void setImune();




};
#endif 