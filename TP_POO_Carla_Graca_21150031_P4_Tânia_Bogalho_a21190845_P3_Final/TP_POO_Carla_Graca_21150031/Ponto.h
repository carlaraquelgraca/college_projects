#ifndef PONTO_H_
#define PONTO_H_
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Ponto{

private:
	int x;
	int y;
	
public:

	Ponto(int xx = 0, int yy = 0);
	int getX() const;
	int getY() const;
	void setX(int x);
	void setY(int y);
	string getAsString() const;
	~Ponto();
};

//declara��o do operador bin�rio == como fun��o global
bool operator==(const Ponto & a, const Ponto & b);

//declara��o do operador bin�rio != como fun��o global
bool operator!=(const Ponto & a, const Ponto & b);

ostream & operator<<( ostream & saida, const Ponto & ob);
#endif