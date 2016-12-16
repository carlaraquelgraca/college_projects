#ifndef TERRENO_H_
#define TERRENO_H_
#include <iostream>
#include <string>
#include "Mosquito.h"

class Ponto;
class Mosquito;
class SerVivo;
class Mundo;

class Terreno 
{
private:
    string id;
    Ponto p;

    //funções get
    //funções set
public:
	Terreno(string id,Ponto p);
	virtual ~Terreno();
	virtual void agir(Mundo *m);
	Ponto getPos(); 
	virtual Terreno * duplica()const;
	int getCor();
	string getId() const;
	void setCor(int cor);
	void setPos(Ponto newP); 
	virtual string getAsString()const;	
	
};
#endif
