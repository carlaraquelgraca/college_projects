#ifndef TERRENONEUTRO_H_
#define TERRENONEUTRO_H_
#include <iostream>
#include <string>


class Terreno;

class TerrenoNeutro : public Terreno{

private:
	

public:
	TerrenoNeutro(string id,Ponto p);
	virtual void agir(Mundo *m);
	virtual Terreno * duplica()const;
	virtual string getAsString()const;

};
#endif