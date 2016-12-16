#ifndef SIMULADOR_H
#define SIMULADOR_H
#include <vector>
#include <string>
#include <iostream>
//#include <sstream>
//#include <istream>
using namespace std;

class Mundo;
class Interface;

class Simulador
{

	vector<Mundo*> mundos;
	Mundo *mActivo;//começa a null e qnd cria o mundo e acrescenta ao vector depois seria mundos[0];colocar função para pesquisar mundo pelo nome
	

public:

	Simulador();
	virtual ~Simulador(void);



	bool carregaMundo(string nomeFich);
	void salvaMundo(string nome);

	void criaMundo(string nome, int lCel, int cCel);
	void atribuiMundo(string mDestino,string mOrigem);
	void removeMundo(int pos);	
	int contaComandos(string comando);
	void leComando();
	void jogoLoop();
	Mundo* getMundoActivo() const;
	void leComando(Interface &inter);
	void leComandoTXT(string comando);
	void setMundoActivo(Mundo *m);
	void leFicheiro(string ficheiro);
	int pesquisaMundo(string nome);
	


};
#endif