#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <time.h>
#include "Interface.h"
#include "Simulador.h"
#include "Consola.h"
#include "Mundo.h"
#include "Pessoa.h"
#include "Mosquito.h"
using namespace std;

Interface::Interface(Simulador *sim)
{
	s = sim;
	
	configInit();
}

Interface::~Interface()
{
	delete s;
}



void Interface::desenhaLC(int lin,int col)//desenha as linhas e as colunas
{
	int i,j;
	

	for(i = 1;i<= col;i++)
	{
		if(i%2 != 0 )
			c.gotoxy(Mundo::getDimCelula()*i,1);
		else
			c.gotoxy(Mundo::getDimCelula()*i,2);
		if(i<10)	
			cout << "00" <<i-1;
				else if(i<100)
				cout << "0" << i-1;
				else
				cout << i-1;
	}

	for(j = 1;j<= lin;j++)
	{
		c.gotoxy(0,Mundo::getDimCelula()*j); 
				if(j<10)	
				cout << "00" <<j-1;
				else if(j<100)
				cout << "0" << j-1;
				else
				cout << j-1;
	}
	c.gotoxy(0,Mundo::getDimCelula()*lin + Mundo::getDimCelula()*2);

}
void Interface::desenhaTracos()
{
	for(int i = 0;i< 3;i++)
	{
		cout<<endl;
	}

	for(int i =0 ; i<80;i++)
	{
		cout<< "=";
	}

	cout<<endl;
}

void Interface::desenhaCelula(Mundo *m,int lin,int col)//desenha o mundo e o seu conteúdo
{
	Ponto p(col,lin);
	string pessoa = m->pesquisaPessoa(p); 
	string mosquito = m->pesquisaMosquito(p);
	string terreno = m->pesquisaTerreno(p);
	string vazio = "   ";
	Pessoa *ps = m->pesquisaPessoaObj(p);
	int linha = Mundo::getDimCelula() + lin*Mundo::getDimCelula();
	int coluna = Mundo::getDimCelula() + col*Mundo::getDimCelula();

	for(int i = 0;i< Mundo::getDimCelula();i++)
	{
		c.gotoxy(coluna,linha + i);
		if(!(m->getTerrenos().empty()))
		{
			if(terreno == "H")
				c.setBackgroundColor(c.AMARELO_CLARO);
			else 
				if(terreno == "P")
			c.setBackgroundColor(c.CASTANHO);
		}
		
		cout<<vazio;
	}

	
	if(!(m->getMosquitos().empty()))
	{
	c.setTextColor(c.ROXO);
	c.gotoxy(coluna, linha);
	cout<< mosquito;
	}

	if(!(m->getPessoas().empty()))
	{
		if(ps!=0)
		{
			if(ps->getEstado() == false)
			{
				if(ps->getImune() == true)
					c.setTextColor(c.AZUL);
				else
					c.setTextColor(c.VERMELHO);
				
			}
			else 
					c.setTextColor(c.VERDE);
					
				
			

			c.gotoxy(coluna, linha+1);
			cout<< pessoa;
		}
		
	}
	 
	
}


void Interface::mostraTabuleiro(Simulador *s)//mostra o conteúdo do mundo
{
	int i,j;
	 int col,lin;
	 Mundo *m = s->getMundoActivo();
	
	col = m->getColunas();
	lin = m->getLinhas();
	desenhaLC(lin,col);

	for(i=0;i < lin ;i++)
	{
		for(j=0;j < col ;j++)
		{
			if((i+j)%2==0)
			{
				c.setBackgroundColor(c.BRANCO);
				desenhaCelula(m,i,j);
			}
			else
			{
				c.setBackgroundColor(c.CINZENTO);
				desenhaCelula(m,i,j);
			}
			
		}
		c.setTextColor(c.BRANCO);
	}

	c.setBackgroundColor(c.PRETO);
	desenhaTracos();
	cout<<m->getNome()<<">";
	
	if(m->getCompleto() == true)
		printCompleto(m);
}

void Interface::printCompleto(Mundo *m)//mostra detalhes completos sobre o mundo
{
	c.gotoxy(50, 1);
	cout <<"|Completo|";
	c.gotoxy(50, 3);
	cout <<"Numero de Seres: "<<m->getTotalSeres()<<"\n";
	c.gotoxy(50, 4);
	cout <<"Numero de Jovens: "<<m->getNumJovens()<<"\n";
	c.gotoxy(50, 5);
	cout <<"Numero de Idosos: "<<m->getNumIdosos()<<"\n";
	c.gotoxy(50, 6);
	cout <<"Numero de Mosquitos: "<<m->getNumMosquitos()<<"\n";
	c.gotoxy(50, 7);
	cout <<"Numero de Infectados: "<<m->getNInfectados()<<"\n";
	c.gotoxy(50, 8);
	cout <<"Numero de Saudaveis: "<<m->getNSaudavel()<<"\n";

}

int Interface::aleat(int inf, int sup){
	return rand()%(sup - inf + 1) + inf;
}

void Interface::configInit()// configuração inicial do ecrã
{
	c.setTextSize(8,8);
	c.setScreenSize(50,80);  
	c.setBackgroundColor(Consola::PRETO);
	c.setTextColor(Consola::BRANCO);
}

Consola Interface::getConsola() const
{
	return c;
}


