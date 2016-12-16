#ifndef INTERFACE_H_
#define INTERFACE_H_
#include <iostream>
#include <string>
#include "Ponto.h"
#include "Consola.h"
#include "Mundo.h"
using namespace std;

class Consola;
class Simulador;
class Mundo;

class Interface {

	private:
		Consola c;//pode ser sem ponteiro pq n se altera informação
		Simulador *s;//o interface capta a vontade do simulador,

	public:
		Interface(Simulador *sim);//o interface está associado ao simulador
		virtual ~Interface();
		void desenhaTracos();
		void mostraTabuleiro(Simulador *s);
		Consola getConsola() const;
		void configInit();
		void printCompleto(Mundo *m);
		void desenhaLC(int l,int c);
		void desenhaCelula(Mundo *m,int lin,int col);
		static int aleat( int inf, int sup);


   };
#endif