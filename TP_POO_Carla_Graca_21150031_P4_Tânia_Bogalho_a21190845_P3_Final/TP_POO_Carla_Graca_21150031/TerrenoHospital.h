#ifndef TERRENOHOSPITAL_H_
#define TERRENOHOSPITAL_H_
#include <iostream>
#include <string>


class Terreno;

class TerrenoHospital : public Terreno{

private:
	

public:
	TerrenoHospital(string id,Ponto p);
	virtual void agir(Mundo *m);
	virtual Terreno * duplica()const;
	virtual string getAsString()const;
    



};
#endif
