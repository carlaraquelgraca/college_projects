#ifndef MUNDO_H_
#define MUNDO_H_
#include <iostream>
#include <string>
#include <vector>
#include "SerVivo.h"
#include "Idoso.h"
#include "Jovem.h"
//#include "Interface.h"
#include "Terreno.h"
#include "Ponto.h"
using namespace std;


class Mundo 
{

private: 

	/*Interface i;*/
	//Mapa *mapa;
	string nome;
    static int minPessoas;             //número minimo de pessoas
	int nSaudavel;
	int nInfectados;
	static const int maxCelL = 50;
	static const int maxCelC = 100;
	static const int dimCelula = 3;
	int nIteracoes;
	bool completo;
	int nCelL;
	int nCelC;
	int nMortos;
    int totalIdosos;        //numero total de Idosos
	int totalJovens;
	int totalMosquitos;
	int totalSeres;
	//vector<SerVivo*> seres; //em vez de seres vivos ter Mosquito e pessoas??
	vector<Pessoa*> pessoas;
	vector<Mosquito*> mosquitos;
	vector<Terreno*> terrenos;
	void criaCopia(const Mundo & m);
	
	//Para eliminar do vector não fazer i++ pq o index desloca-se.Deve haver uma variável q indica se o ser está vivo ou morto

public:
	Mundo(string nome,int linha,int coluna);
	Mundo();
	~Mundo();
	//construção por cópia e atribuição
	Mundo(const Mundo &m);
	Mundo& operator=(const Mundo &m);
	

    //funções get
	static int getmaxLinhas();
	static int getmaxColunas();
	bool criaHospital(int l,int c);
	bool criaPantano(int l,int c);
	bool acrescentaPessoa();
    int getLinhas() const;
	int getColunas() const;
	vector<SerVivo *> getSeres() const;
	vector<Terreno *> getTerrenos() const;
	vector<Mosquito *> getMosquitos() const;
	vector<Pessoa *> getPessoas() const;
    static int getMinPessoas();
	static void setMinPessoas(int min);
	int getTotalSeres() const;
	string getNome() const;
	int getNumMosquitos() const;
	int getNumIdosos() const;
	int getNMortos() const;
	int getNumJovens() const;
	int getNumPessoas() const;
	int getNSaudavel() const;
	int getNInfectados() const;
	int getNIteracoes() const;
	bool getCompleto() const;
	void setCompleto(bool n);
	void criaNovoSer(string id);
	static int getDimCelula();

	//funções set
	void setLinhas(int l);
	void setColunas(int c);
	void setNumIdosos(int idosos);
	void setNumMosquitos(int mosquitos);
	void setNumJovens(int jovens);
	void setNome(string nome);
	void setNIteracoes(int it);
	void setNSaudavel(int ns);
	void setNInfectados(int nInf);
	void agir();
	bool adicionaSerVivo(string tipo,int nSeres);
	void moveSeres();
	bool estarLivre(Ponto p, string tipo);
	void simular();
	int aleat(int lim); 
	void setTotalSeres(int seres);
	bool novaPosAleat(Ponto &p, string tipo);
	void preencheTabuleiro();
	void eliminaMortos();
	string pesquisaPessoa(Ponto p) const;
	string pesquisaMosquito(Ponto p) const;
	string pesquisaTerreno(Ponto p) const;
	Pessoa *pesquisaPessoaObj(Ponto p)const;
	Mosquito *pesquisaMosquitoObj(Ponto p)const;
	bool acrescentaJovem();
	bool acrescentaIdoso();
	bool acrescentaMosquito();
	bool acrescentaMataMoscas();
	bool removeMosquito(Ponto pos);
	bool removePessoa(Ponto pos);
	bool removeSeres();
	bool removeTerrenos();
	bool removePessoas();
	bool removeMosquitos();
	bool dentroDosLimites (Ponto p); 
	bool mataMoscas(Ponto p);
	virtual Mundo * duplica()const;
};

#endif

