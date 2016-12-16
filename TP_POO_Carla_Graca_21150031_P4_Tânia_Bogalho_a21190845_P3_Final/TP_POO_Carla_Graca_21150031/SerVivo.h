#ifndef SERVIVO_H_
#define SERVIVO_H_
#include <iostream>
#include <string>
#include "Ponto.h"
using namespace std;

class Mundo;
class Ponto;
class Consola;

class SerVivo
{
private:
	
	
	string id;
	int num;
	Ponto p;//composi��o
	string direccao;
	static int ordem;
	int tempoVida;
	
    
public:
	
    SerVivo(string letra,int n,Ponto p);
	virtual ~SerVivo();//destr�i os objectos dsa classes derivadas correspondente atrav�s de polimorfismo
    ////fun��es get
    string getId() const;
	void setId(int id);
	int getNum() const;
	void setNum(int id);
    Ponto getPos(); //Interface recebe ponteiro ou referencia para jogo; os terrenos v�o agir consoante os seres que t�m em cima. s�o os terrenos que v�o agir consoante o ser e n�o o ser que vai agir consoante o terreno que tem em baixo.
	virtual Ponto move(Mundo *mundo);
	virtual string getAsString() const;
	int getTempoVida() const;
	void setTempoVida(int tv);
	static void setOrdem(int ordem);
	static int getOrdem();
    void setPos(Ponto newP); 
	

};


#endif