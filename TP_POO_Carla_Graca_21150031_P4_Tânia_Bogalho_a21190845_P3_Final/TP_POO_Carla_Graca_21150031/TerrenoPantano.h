#ifndef TERRENOPANTANO_H_
#define TERRENOPANTANO_H_
#include <iostream>
#include <string>


class Terreno;
class TerrenoPantano : public Terreno
{

private:
	
public:
	TerrenoPantano(string id,Ponto p);
	virtual void agir(Mundo *m);
	virtual Terreno * duplica()const;
	virtual string getAsString()const;


};
#endif
