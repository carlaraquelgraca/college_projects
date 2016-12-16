#include <iostream>
#include <string>
#include <vector>
#include "Jovem.h"
#include "Idoso.h"
#include "MataMosca.h"
#include "Mundo.h"
#include "Interface.h"
#include "Consola.h"
#include "TerrenoNeutro.h"
#include "TerrenoHospital.h"
#include "TerrenoPantano.h"
using namespace std;

int Mundo::minPessoas = 2;

Mundo::~Mundo()
{
	
	removeTerrenos();
	removeSeres();


}

Mundo::Mundo(string n,int l,int c)
{

	nCelL = l;
	nCelC = c;
	nome = n;
	
	nMortos = 0;
    totalIdosos = 0; 
	totalJovens = 0;  
	totalMosquitos = 0;
	nSaudavel = 0;
	nInfectados = 0;
	totalSeres = 0;
	nIteracoes = 0;

}

Mundo::Mundo(const Mundo& m)
{
	criaCopia(m);
}

Mundo& Mundo::operator=(const Mundo &m)
{
		if (this != &m)
		{
			removeSeres();
			removeTerrenos();
			criaCopia(m);
		}
		return *this;
      
}

void Mundo::criaCopia(const Mundo & ob)//cria uma cópia de um objecto mundo e todo o seu conteúdo
{
	
	nCelL = ob.nCelL;
	nCelC = ob.nCelC;
	nMortos = ob.nMortos;
	totalIdosos = ob.totalIdosos;
	totalSeres = ob.totalSeres;
	totalJovens = ob.totalJovens;
	totalMosquitos = ob.totalMosquitos;
	minPessoas = ob.minPessoas;
	nSaudavel = ob.nSaudavel;
	nInfectados = ob.nInfectados;
	completo = ob.completo;
	nCelL = ob.nCelL;
	nCelC = ob.nCelC;
	nMortos = ob.nMortos;

	for (unsigned int i = 0 ; i < ob.terrenos.size() ; i++)
	{
		Terreno * t = ob.terrenos[i]->duplica();
		if(!t)
		{
			removeTerrenos();
			return;
		}
		terrenos.push_back(t);
	}

	for (unsigned int i = 0 ; i < ob.pessoas.size() ; i++)
	{
		Pessoa * p = ob.pessoas[i]->duplica();
		if(!p)
		{
			removePessoas();
			return;
		}
		pessoas.push_back(p);
	}

	for (unsigned int i = 0 ; i < ob.mosquitos.size() ; i++)
	{
		Mosquito * m = ob.mosquitos[i]->duplica();
		if(!m)
		{
			removeMosquitos();
			return;
		}
		mosquitos.push_back(m);
	}
	
}


void Mundo::setNumIdosos(int tIdosos) 
{ 
	totalIdosos = tIdosos;
}

void Mundo::setNumJovens(int tJovens) 
{ 
	totalJovens = tJovens;
}

void Mundo::setNumMosquitos(int tMosquitos) 
{ 
	totalMosquitos = tMosquitos;
}


int Mundo::getmaxLinhas() 
{ 
	return maxCelL; 
}


int Mundo::getmaxColunas() 
{ 
	return maxCelC; 
}

int Mundo::getLinhas() const
{ 
	return nCelL; 
}


int Mundo::getColunas() const
{ 
	return nCelC; 
}

void Mundo::setLinhas(int l)
{
	nCelL = l; 
}

void Mundo::setColunas(int c)
{
	nCelC = c; 
}


string Mundo::getNome() const
{
	return nome;
}

bool Mundo::getCompleto() const
{
	return completo;
}

void Mundo::setCompleto(bool n){
	completo = n;
}

void Mundo::setNome(string n)
{
	nome = n;
}


bool Mundo::criaHospital(int lin,int col)
{
	Ponto p(col, lin);


	if(estarLivre(p,"terreno"))
	{
		terrenos.push_back(new TerrenoHospital("H",p));
		return true;
	} 
	else 
	{
		return false;
	}
}

bool Mundo::criaPantano(int lin,int col)
{
	Ponto p(col, lin);



	if(estarLivre(p,"terreno"))
	{
		terrenos.push_back(new TerrenoPantano("P",p));
		return true;
	} 
	else 
	{
		return false;
	}
	
}


vector<Terreno*> Mundo::getTerrenos() const
{
	return terrenos;
}

vector<Mosquito*> Mundo::getMosquitos() const
{
	return mosquitos;
}

vector<Pessoa*> Mundo::getPessoas() const
{
	return pessoas;
}

bool Mundo::mataMoscas(Ponto p)
{
		for (unsigned int i = 0;i<mosquitos.size();i++)
					{
						if(mosquitos[i]->getPos() == p)
						{
							removeMosquito(mosquitos[i]->getPos());
							return true;
						}
					}
		return false;
}

bool Mundo::acrescentaPessoa()//cria nova pessoa
{
	Ponto p(0,0);
	int num;

	
			if(novaPosAleat(p,"pessoa"))
			{
				int aleat = rand()%2 + 1;

				if(aleat == 1)
				{
					SerVivo::setOrdem(SerVivo::getOrdem() + 1);
					num = SerVivo::getOrdem();
					pessoas.push_back(new Jovem("J",num,p));

					totalJovens = totalJovens + 1;
					totalSeres = totalSeres + 1;
					nSaudavel = nSaudavel + 1;
					
					

					
					return true;
				} 
				else 
				{
					SerVivo::setOrdem(SerVivo::getOrdem() + 1);
					num = SerVivo::getOrdem();
					pessoas.push_back(new Idoso("I",num,p));
					totalIdosos = totalIdosos + 1;
					totalSeres = totalSeres + 1;
					nSaudavel = nSaudavel + 1;

						

					return true;
				}
			}
			else
			{
				return false;
			}
		
	
}

bool Mundo::acrescentaJovem()//cria novo jovem
{
	Ponto p(0,0);
	int num;

	if(novaPosAleat(p,"pessoa"))
	{
		SerVivo::setOrdem(SerVivo::getOrdem() + 1);
		num = SerVivo::getOrdem();
		pessoas.push_back(new Jovem("J",num,p));
		totalJovens = totalJovens + 1;
		nSaudavel = nSaudavel + 1;

		return true;
	} 
	else 
	{
		return false;
	}
}

bool Mundo::acrescentaMataMoscas()
{
	Ponto p(0,0);
	int num;

	if(novaPosAleat(p,"pessoa"))
	{
		SerVivo::setOrdem(SerVivo::getOrdem() + 1);
		num = SerVivo::getOrdem();
		pessoas.push_back(new MataMosca("MM",num,p));
		totalJovens = totalJovens + 1;
		nSaudavel = nSaudavel + 1;

		
		return true;
	} 
	else 
	{
		return false;
	}
}

bool Mundo::acrescentaIdoso()//cria novo idoso
{
	Ponto p(0,0);
	int num;

	if(novaPosAleat(p,"pessoa"))
	{
		SerVivo::setOrdem(SerVivo::getOrdem() + 1);
		num = SerVivo::getOrdem();
 		pessoas.push_back(new Idoso("I",num,p));
		totalIdosos = totalIdosos + 1;
		nSaudavel = nSaudavel + 1;


		return true;
	} 
	else 
	{
		return false;
	}
	
}

bool Mundo::acrescentaMosquito()//cria novo mosquito
{
	Ponto p(0,0);
	int num;

	if(novaPosAleat(p,"mosquito"))
	{
		SerVivo::setOrdem(SerVivo::getOrdem() + 1);
		num = SerVivo::getOrdem();
		mosquitos.push_back(new Mosquito("M",num,p));
		totalMosquitos = totalMosquitos + 1;
		return true;
	} 
	else 
	{
		return false;
	}
}

 int Mundo::getDimCelula()
{
 return dimCelula;
}

 void Mundo::setMinPessoas(int p)
 {
	 minPessoas = p;
 }

 void Mundo::setNInfectados(int nInf)
 {
	 nInfectados = nInf;
 }

 int Mundo::getMinPessoas()
 {
	 return minPessoas;
 }

 void Mundo::setTotalSeres(int s)
 {
	 totalSeres = s;
 }

bool Mundo::dentroDosLimites (Ponto p) 
{
		return p.getX() >= 0 && p.getX() < nCelL && p.getY() >= 0 && p.getY() < nCelC;
}

bool Mundo::estarLivre(Ponto p,string tipo)//verifica se existe algum ser num determinado ponto
{
	if(!dentroDosLimites(p)) 
	{
	return false;
	}
	
	 if(tipo == "pessoa")
	 {
        if(pesquisaPessoa(p) == "   ")
              return true;
	 }

	 if(tipo == "mosquito")
	 {
        if(pesquisaMosquito(p) == "   ")
              return true;
	 }

	  if(tipo == "terreno")
	 {
        if(pesquisaTerreno(p) == "   ")
              return true;
	 }
            
	return false;
}

int Mundo::getTotalSeres() const
{
	return totalSeres;
} 

int Mundo::getNumIdosos() const
{
	return totalIdosos;
}

int Mundo::getNumJovens() const
{
	return totalJovens;
}

int Mundo::getNumMosquitos() const
{
	return totalMosquitos;
}

int Mundo::getNumPessoas() const
{
	return totalIdosos + totalJovens;
}


int Mundo::getNMortos() const
{
	
	return nMortos;
}

int Mundo::getNSaudavel() const
{
	
	return nSaudavel;
}

void Mundo::setNSaudavel(int ns) 
{
	
	nSaudavel = ns;
}

int Mundo::getNInfectados() const
{
	return nInfectados;
}

string Mundo::pesquisaPessoa(Ponto p) const// pesquisa pessoa num determinado ponto
{
	string id;

	for (unsigned int i = 0; i < pessoas.size(); i++)
	{
		if((pessoas[i]->getPos() == p))
		{
			//id = pessoas[i]->getId();
			return pessoas[i]->getAsString();
		}
	}
	return "   ";
}

Pessoa *Mundo::pesquisaPessoaObj(Ponto p)const //pesquisa e devolve a pessoa se ela existir num ponto
{
	for ( unsigned int i = 0; i < pessoas.size(); i++){
		if ((pessoas[i]->getPos() == p) )
			return pessoas[i];
	}
	return 0;
}

Mosquito *Mundo::pesquisaMosquitoObj(Ponto p)const//pesquisa e devolve o mosquito se ele existir num ponto
{
	for ( unsigned int i = 0; i < mosquitos.size(); i++){
		if (mosquitos[i]->getPos() == p) 
			return mosquitos[i];
	}
	return 0;
}

string Mundo::pesquisaMosquito(Ponto p) const //pesquisa mosquito num determinado ponto
{
	string id;

	for(unsigned int i = 0; i < mosquitos.size(); i++)
	{
		if ((mosquitos[i]->getPos() == p))
		{
			return mosquitos[i]->getAsString();
		}
	}
	return "   ";
}

string Mundo::pesquisaTerreno(Ponto p) const//pesquisa terreno num determinado ponto
{
	string id;

	for(unsigned int i = 0; i < terrenos.size(); i++)
	{
		if ((terrenos[i]->getPos() == p))
		{
			id = terrenos[i]->getId();
			return id;
		}
	}
	return "   ";
}


bool Mundo::removePessoas()
{
	for (unsigned int i = 0 ; i < pessoas.size() ; i++ )
			delete pessoas[i];

	pessoas.clear();

	if(pessoas.empty())
		return true;
	else
		return false;
}

bool Mundo::removeSeres()
{
	if(removePessoas() && removeMosquitos())
	{
		return true;
	}
	else 
		return false;

}

bool Mundo::removeMosquito(Ponto p)
{
	for(unsigned int i = 0; i< mosquitos.size(); i++)
	{
		if(mosquitos[i]->getPos() == p)
		{
			delete mosquitos[i];
			mosquitos.erase(mosquitos.begin() + i);
			return true;
		}
	}
	
	return false;
	
}

bool Mundo::removePessoa(Ponto p)
{
	for(unsigned int i = 0; i< pessoas.size(); i++)
	{
		if(pessoas[i]->getPos() == p)
		{
			delete pessoas[i];
			pessoas.erase(pessoas.begin() + i);
			return true;
		}
	}
	
	return false;
}

bool Mundo::removeTerrenos()
{
	for(unsigned int i = 0; i < terrenos.size() ; i++)
		delete terrenos[i];

	terrenos.clear();

	if(terrenos.empty())
		return true;
	else
		return false;
}

bool Mundo::removeMosquitos()
{
	
		
	for( unsigned int i = 0 ; i < mosquitos.size() ; i++)
	{

				delete mosquitos[i];
	}

	mosquitos.clear();

	if(mosquitos.empty())
		return true;
	else
		return false;
}


void Mundo::agir() // o mundo manda agir todos os seu conteúdo
{
	Ponto ponto(0,0);
	int tentativas = 0;
	int aleat = rand()%3 + 1;
	
	while((totalIdosos + totalJovens < minPessoas) && (nSaudavel > 1))
	{
		acrescentaPessoa(); //enquanto o número de pessoas estiver abaixo do mínimo, acrescenta nova pessoa 
	}

	for (unsigned int i = 0; i < terrenos.size(); i++)
	{
		terrenos[i]->agir(this); //manda os terrenos agirem de acordo com os seres sobre eles
	}

	for (unsigned int i = 0; i < mosquitos.size(); i++)
	{
		tentativas = 0;
		if(mosquitos[i]->getTempoVida() == 0)
		{
			if(removeMosquito(mosquitos[i]->getPos()) == true)
			{
				totalMosquitos--;
				totalSeres--;
			}
		}
		else
		{
			mosquitos[i]->setTempoVida(mosquitos[i]->getTempoVida() - 1 );
			do{
				ponto = mosquitos[i]->move(this);
				tentativas++;
				} 
			while (!estarLivre(ponto,"mosquito") && tentativas < 500);

			if(!(tentativas >=500))
				mosquitos[i]->setPos(ponto);
		}
	}


	//selecciona uma das seguintes hipóteses para Pessoa: deslocar-se,reagir à infecção ou infectar
	if(aleat == 1)
	{
		for (unsigned int i = 0; i < pessoas.size(); i++) // pessoa reage à infecção;
		{
		//o mover do idoso é aleatório enquanto que o jovem tem probabilidade.
		//gera posição destino. vê se lá está alguém. se estiver gera nova e assim sucessivamente até não haver sítio para onde ir.
			if(pessoas[i]->getTempoVida() == 0)
			{
				
						if(pessoas[i]->getEstado() == true)
							nSaudavel = nSaudavel - 1;
						else
							nInfectados = nInfectados - 1;

						
					if(pessoas[i]->getId().find("I") == 0)
					{
						totalIdosos--;

					}
					else
					{
						totalJovens--;	
					}

					totalSeres--;
					removePessoa(pessoas[i]->getPos());
				
			}
			else
			{
				if(pessoas[i]->getId().find("I") == 0)
						pessoas[i]->setTempoVida(pessoas[i]->getTempoVida() - 1);

				if(pessoas[i]->getEstado() == false)
					pessoas[i]->reageInfeccao(this);
			}
		}
	}

	else if(aleat == 2)
	{
		for (unsigned int i = 0; i < pessoas.size(); i++)
		{
			tentativas = 0;
		
				if(pessoas[i]->getTempoVida() == 0)
			{
						if(pessoas[i]->getEstado() == true)
							nSaudavel = nSaudavel - 1;
						else
							nInfectados = nInfectados - 1;				

					if(pessoas[i]->getId().find("I") == 0)
					{
						totalIdosos--;
					}
					else
						totalJovens--;	
					
					totalSeres--;
					removePessoa(pessoas[i]->getPos());
				
			}
			else
			{
				if(pessoas[i]->getAsString().find("I") == 0)
					pessoas[i]->setTempoVida(pessoas[i]->getTempoVida() - 1);

				do{
					ponto = pessoas[i]->move(this);
					tentativas++;
					} 
				while(!(estarLivre(ponto,"pessoa")) && tentativas <500);

			if(!(tentativas >= 500))
			{
				pessoas[i]->setPos(ponto);
				for(unsigned int i = 0;i<mosquitos.size();i++)
				{
					if(pessoas[i]->getPos() == mosquitos[i]->getPos())
						pessoas[i]->agir(mosquitos[i]->getPos());
				}
			}
				
			}
		}


		
	}
	else
	if(aleat == 3)
	{
		for (unsigned int i = 0; i < pessoas.size(); i++) //Remove seres mortos e infecta pessoa;
		{
				if(pessoas[i]->getTempoVida() == 0)
			{
				
						if(pessoas[i]->getEstado() == true)
							nSaudavel = nSaudavel - 1;
						else
							nInfectados = nInfectados - 1;

						
						if(pessoas[i]->getId().find("I") == 0)
					{
						totalIdosos--;
					}
					else
						totalJovens--;	
						
						totalSeres--;
						removePessoa(pessoas[i]->getPos());
				
			}
			else
			{
				if(pessoas[i]->getId().find("I") == 0)
				{
					pessoas[i]->setTempoVida(pessoas[i]->getTempoVida() - 1);
				}
				
					if(!estarLivre(pessoas[i]->getPos(),"mosquito"))
					{
						if(!(pessoas[i]->getImune()) && (pessoas[i]->getEstado() == true) )
						{
							pessoas[i]->setEstado(false);
							nSaudavel = nSaudavel - 1;
							nInfectados = nInfectados + 1;
						
							if(pessoas[i]->getTempoVida() > Idoso::getTempoInfI())
								pessoas[i]->setTempoVida(Idoso::getTempoInfI());
						}

					}
					
			}
		}


	}
	

	

}



bool Mundo::novaPosAleat(Ponto &p,string tipo) // cria nova posição aleatória
{
		int tent = 0; // numero tentativas
		Ponto p1;

	do{
		p1 = Ponto(Interface::aleat(0,nCelL-1),Interface::aleat(0,nCelC-1));
		tent++;
	} while (!estarLivre(p1,tipo) && tent < 500);

	if (tent >= 500)
		return false;
	p = p1;
	return true;
}

Mundo * Mundo::duplica()const
{
	Mundo * p = new Mundo( *this);
	return p;
}

int Mundo::getNIteracoes()const
{
	
	return nIteracoes;

}


void Mundo::setNIteracoes(int nIt)
{
	
	 nIteracoes = nIt;
	
}


