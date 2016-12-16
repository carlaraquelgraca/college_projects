#ifndef MOSQUITO_H_
#define MOSQUITO_H_
#include <iostream>
#include "SerVivo.h"

class Pessoa;
class Mosquito: public SerVivo
{

private:
	
public:
	Mosquito(string id,int num,Ponto p);	
	void agirHospital(Mundo *m);
	virtual string getAsString() const;
	virtual Ponto move(Mundo *mundo);
	void agirPantano(Mundo *m);
	virtual Mosquito * duplica()const;


};

#endif