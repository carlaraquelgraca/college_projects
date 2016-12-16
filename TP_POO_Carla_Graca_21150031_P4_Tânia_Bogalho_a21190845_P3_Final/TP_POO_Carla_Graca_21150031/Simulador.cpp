#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include "Simulador.h"
//#include "Mundo.h"
#include "Interface.h"
#include "Consola.h"
using namespace std;

Simulador::Simulador()
{
	mActivo = 0;
}

Simulador::~Simulador()
{
	for( unsigned int i = 0 ; i < mundos.size() ; i++)
	{

				delete mundos[i];
	}

	mundos.clear();
}

void Simulador::leComando(Interface &inter)//le os comandos introduzidos pelo utilizador
{

	string nome, comando, str, novo, outro;                 
	int  lin, col,nseres;              
	istringstream instream;   
	string nomeFich,comandosFich;
	Consola c = inter.getConsola();
	int tamanho = 0;
	int verifica = 0 , verifica2 = 0;
	string destino, origem;
	int tempo;


	getline(cin, comando);

	//COMANDO MUNDO
	if(comando.find("mundo") == 0) 
	{ 
		if(contaComandos(comando)!=4)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}


		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> nome >> lin >> col;

		if(lin>Mundo::getmaxLinhas() || col>Mundo::getmaxColunas())
		{
			cout << "Numero de linhas ou colunas invalidas!Prima uma tecla para continuar...";
			cin.get();
			return;
		}

		criaMundo(nome,lin,col);
		mActivo = mundos[mundos.size()-1];

		c.clrscr();
		inter.mostraTabuleiro(this);
	}
	//COMANDO CRIACOPIA
	else if(comando.find("criacopia") == 0) 
	{ 
		if(contaComandos(comando)!=3)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}

		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> novo >> outro; 

		if(mActivo !=0 )//se existir algum objecto associado ao ponteiro
		{
				verifica = pesquisaMundo(outro);	//Verificação se o mundo existe
				if(verifica != -1)	//Se encontrar o mundo ao qual se pretende criar uma copia
				{
					Mundo *m2 = new Mundo(*(mundos[verifica]));// tem de se criar a copia desta maneira porque senão eles ficam associados e quando se muda um,também se muda o outro

					m2->setNome(novo);
					mundos.push_back(m2);
				}
				else
				{
				cout << "Não existe mundo com esse nome!Prima uma tecla para continuar...";
				c.getch();
				}
		}
		else
		{
			cout << "Mundo ainda não foi criado!Prima uma tecla para continuar..." << endl;
			c.getch();
		}

		c.clrscr();
		inter.mostraTabuleiro(this);
	}
	//COMANDO ATRIBUI
	else if(comando.find("atribui") == 0) 
	{ 

		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> destino >> origem; 

		if(mActivo != 0)//se existir algum objecto associado ao ponteiro
		{

				verifica = pesquisaMundo(origem);
				if(verifica != -1)	//Se encontrar o mundo origem
				{

					verifica2 = pesquisaMundo(destino);
					if(verifica2 != -1)
					{				
						mundos[verifica2] = mundos[verifica];
					}
					else
					{
						cout << "Não existe mundo com esse nome destino!Prima uma tecla para continuar...";
						c.getch();
					}
				}
				else
				{
				cout << "Não existe mundo com esse nome de origem!Prima uma tecla para continuar...";
				c.getch();
				}
		}
		else
		{
			cout << "Mundo ainda não foi criado!Prima uma tecla para continuar..." << endl;
			c.getch();
		}
			c.clrscr();
		inter.mostraTabuleiro(this);

	}
	//COMANDO APAGA
	else  if(comando.find("apaga") == 0) 
	{ 

		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> nome; 

		if(mActivo != 0)	//Se o mundo com o nome escrito na linha de comandos existir
		{
			if(mActivo->getNome() == nome)
			{
				cout << "Impossivel apagar o mundo actual!Prima uma tecla para continuar";
				c.getch();
			}
			else
			{
				verifica = pesquisaMundo(nome);	//pesquisa mundo cm o nome pedido
				if(verifica != -1) //Se o mundo for encontrado apaga-o do vector de mundos
				{
					removeMundo(verifica);	
					mundos.size();
					
				}
			}
			
		}
		else
		{
			cout << "Mundo ainda não foi criado!Prima uma tecla para continuar..." << endl;
			c.getch();
		}

		if(mundos.empty())
			SerVivo::setOrdem(0);

			c.clrscr();
		inter.mostraTabuleiro(this);
	}
	//COMANDO SIMULA
	else if (comando.find("simula") == 0)
	{
		if(contaComandos(comando)!=2)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}


		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> nome;


		for(unsigned int i=0; i< mundos.size(); i++)
		{
			if(mundos[i]->getNome() == nome)
				mActivo = mundos[i];
		}

			c.clrscr();
		inter.mostraTabuleiro(this);

	}
	//COMANDO CRIAI
	else if (comando.find("criai") == 0)
	{
		if(contaComandos(comando)!=2)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}


		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> nseres; 

		if(mActivo != 0)
		{
			tamanho = mActivo->getLinhas()*mActivo->getColunas();


			if(mActivo->getNumPessoas() + /*mActivo->getPessoas().size()*/ + nseres > tamanho)
			{
				cout << "Impossível criar  Idosos!Numero demasiado grande para tamanho do mundo ou mundo cheio!Prima uma tecla para continuar...";
				c.getch(); // só cria se for menor ou igual ao tamanho do mundo ou vai criando até não poder mais?
			}
			else
			{
				for(int i = 0;i < nseres; i++)
				{
					mActivo->acrescentaIdoso();
					mActivo->setTotalSeres(mActivo->getTotalSeres() + 1);
				}
			}

		}
		else
		{
			cout << "Mundo ainda não foi criado!Prima uma tecla para continuar..." << endl;
			c.getch();
		}
			c.clrscr();
		inter.mostraTabuleiro(this);

	}
	//COMANDO LOAD
	else if (comando.find("load") == 0)
	{
			
			if(contaComandos(comando)!=2)
			{
				cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
				cin.get();
				return;
			}

			instream.clear(); // Limpa de erros anteriores possíveis. 
			instream.str(comando);     
			instream >> ws;
			instream>> str >> nomeFich; 

			leFicheiro(nomeFich);

				c.clrscr();
				inter.mostraTabuleiro(this);

		}
	//COMANDO IMUN ->define o tempo de imunidade de um jovem
	else if (comando.find("imun") == 0)
	{

		if(contaComandos(comando)!=2)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}

		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> tempo; 

		Jovem::setTempoImunidade(tempo);
			c.clrscr();
		inter.mostraTabuleiro(this);

	}

	//COMANDO INFEJ ->define o tempo de duração da infecção num jovem
	else if (comando.find("infej") == 0)
	{

		if(contaComandos(comando)!=2)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}

		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> tempo; 

		Jovem::setTempoInfJ(tempo);
			c.clrscr();
		inter.mostraTabuleiro(this);

	}
	//COMANDO INFEI ->define o tempo de duração da infecção num idoso
	else if (comando.find("infei") == 0)
	{

		if(contaComandos(comando)!=2)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}

		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> tempo; 

		Idoso::setTempoInfI(tempo);
			c.clrscr();
		inter.mostraTabuleiro(this);
	}

	//COMANDO MINIMOPESSOAS
	else if (comando.find("minimodepessoas") == 0)
	{
		int  minimo = 0;

		if(contaComandos(comando)!=2)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}

		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> minimo;
		Mundo::setMinPessoas(minimo);
			c.clrscr();
		inter.mostraTabuleiro(this);
	}

		//COMANDO CRIAJ
	else if (comando.find("criamata") == 0)
	{
		if(contaComandos(comando)!=2)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}


		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> nseres; 


		if(mActivo != 0)
		{
			tamanho = mActivo->getLinhas()*mActivo->getColunas();


			if(mActivo->getNumPessoas()/*mActivo->getPessoas().size()*/ + nseres > tamanho)
			{
				cout << "Impossível criar  Mata Msocas!Numero demasiado grande para tamanho do mundo ou mundo cheio!Prima uma tecla para continuar...";
				c.getch(); // só cria se for menor ou igual ao tamanho do mundo ou vai criando até não poder mais?
			}
			else
			{
				for(int i = 0;i < nseres; i++)
				{
					mActivo->acrescentaMataMoscas();
					mActivo->setTotalSeres(mActivo->getTotalSeres() + 1);	

				}
			}

		}
		else
		{
			cout << "Mundo ainda não foi criado!Prima uma tecla para continuar..." << endl;
			c.getch();
		}

			c.clrscr();
		inter.mostraTabuleiro(this);

	}

	//COMANDO CRIAJ
	else if (comando.find("criaj") == 0)
	{
		if(contaComandos(comando)!=2)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}


		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> nseres; 


		if(mActivo != 0)
		{
			tamanho = mActivo->getLinhas()*mActivo->getColunas();


			if(mActivo->getNumPessoas()/*mActivo->getPessoas().size()*/ + nseres > tamanho)
			{
				cout << "Impossível criar  Jovens!Numero demasiado grande para tamanho do mundo ou mundo cheio!Prima uma tecla para continuar...";
				c.getch(); // só cria se for menor ou igual ao tamanho do mundo ou vai criando até não poder mais?
			}
			else
			{
				for(int i = 0;i < nseres; i++)
				{
					mActivo->acrescentaJovem();
					mActivo->setTotalSeres(mActivo->getTotalSeres() + 1);	

				}
			}

		}
		else
		{
			cout << "Mundo ainda não foi criado!Prima uma tecla para continuar..." << endl;
			c.getch();
		}

			c.clrscr();
		inter.mostraTabuleiro(this);

	}

	//COMANDO CRIAM
	else if (comando.find("criam") == 0)
	{
		if(contaComandos(comando)!=2)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}


		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> nseres; 


		if(mActivo != 0)
		{

			tamanho = mActivo->getLinhas()*mActivo->getColunas();



			if(  mActivo->getNumMosquitos()/*mActivo->getMosquitos().size()*/ + nseres > tamanho)
			{
				cout << "Impossível criar  Mosquitos!Numero demasiado grande para tamanho do mundo ou mundo cheio!Prima uma tecla para continuar...";
				c.getch(); // só cria se for menor ou igual ao tamanho do mundo ou vai criando até não poder mais?
			}
			else
			{
				for(int i = 0;i < nseres; i++)
				{
					mActivo->acrescentaMosquito();
					mActivo->setTotalSeres(mActivo->getTotalSeres() + 1);

				}
			}

		}
		else
		{
			cout << "Mundo ainda não foi criado!Prima uma tecla para continuar...";
			c.getch();
		}

			c.clrscr();
		inter.mostraTabuleiro(this);
	}

	//COMANDO MATASV -> mata todos os seres vivos do mundo
	else if (comando.find("matasv") == 0)
	{

		if(contaComandos(comando)!=1)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}

		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str;
		if(mActivo != 0)
		{
			mActivo->removeSeres();
			mActivo->setTotalSeres(0);
			mActivo->setNumIdosos(0);
			mActivo->setNumJovens(0);
			mActivo->setNumMosquitos(0);
			mActivo->setNSaudavel(0);
			mActivo->setNInfectados(0);
			
		}
		else
		{
			cout << "Mundo ainda não foi criado!Prima uma tecla para continuar..." << endl;
			c.getch();
		}

		c.clrscr();
		inter.mostraTabuleiro(this);
	}

	//COMANDO HOSPITAL -> cria e acrescenta um hospital na posição indicada
	else if (comando.find("hospital") == 0)
	{
		if(contaComandos(comando)!=3)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}


		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str  >> lin >> col;; 

		if(lin>Mundo::getmaxLinhas() || col>Mundo::getmaxColunas())
		{
			cout << "Numero de linhas ou colunas invalidas!Prima uma tecla para continuar...";
			cin.get();
			return;
		}


		if(mActivo!=0)
		{
			tamanho = mActivo->getLinhas()*mActivo->getColunas();
			if(!(mActivo->criaHospital(lin,col)))
			{	
				if( tamanho == mActivo->getTerrenos().size())
					cout << "Impossível criar mais Terrenos!Mundo cheio!Prima uma tecla para continuar...";
				else
					cout << "Impossivel criar Hospital na posição indicada!Prima uma tecla para continuar...";

				c.getch();
			}
		}
		else
		{
			cout << "Mundo ainda não foi criado!Prima uma tecla para continuar...";
			c.getch();
		}

		c.clrscr();
		inter.mostraTabuleiro(this);
	}

	//COMANDO PANTANO -> cria e acrescenta um hospital na posição indicada
	else if (comando.find("pantano") == 0)
	{
		if(contaComandos(comando)!=3)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}


		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str  >> lin >> col;; 

		if(lin>Mundo::getmaxLinhas() || col>Mundo::getmaxColunas())
		{
			cout << "Numero de linhas ou colunas invalidas!Prima uma tecla para continuar...";
			cin.get();
			return;
		}

		if(mActivo!=0)
		{
			tamanho = mActivo->getLinhas()*mActivo->getColunas();
			if(!(mActivo->criaPantano(lin,col)))
			{	
				if( tamanho == mActivo->getTerrenos().size())
					cout << "Impossível criar mais Terrenos!Mundo cheio!Prima uma tecla para continuar...";
				else
					cout << "Impossivel criar Pantano na posição indicada!Prima uma tecla para continuar...";

				c.getch();
			}
		}
		else
		{
			cout << "Mundo ainda não foi criado!Prima uma tecla para continuar...";
			c.getch();
		}

		c.clrscr();
		inter.mostraTabuleiro(this);

	}

	//COMANDO COMPLETO
	else if(comando.compare("completo") == 0)
	{
		mActivo->setCompleto(true);
		c.clrscr();
		inter.mostraTabuleiro(this);
	}


	//COMANDO SIMPLES
	else if(comando.compare("simples") == 0)
	{
		mActivo->setCompleto(false);
		c.clrscr();
		inter.mostraTabuleiro(this);
	}

	//COMANDO PROX
	else if(comando.compare("prox") == 0)
	{

		mActivo->agir();
		mActivo->setNIteracoes(mActivo->getNIteracoes() + 1);
		c.clrscr();
		inter.mostraTabuleiro(this);
	}

	//COMANDO EXEC
	else if(comando.find("exec") == 0)
	{
		int nIter;

		if(contaComandos(comando)!=2)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}

		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> nIter;


		for(int i=0; i< nIter;i++)
			mActivo->agir();

		mActivo->setNIteracoes(mActivo->getNIteracoes() + nIter);

		c.clrscr();
		inter.mostraTabuleiro(this);


	}

	//COMANDO SAIR
	else if (comando.compare("sair") == 0)
	{
		exit(0);
	}

	else
	{
	cout << "Comando nao existe!Prima uma tecla para continuar...";
	c.getch();
	c.clrscr();
	inter.mostraTabuleiro(this);
	}
}

Mundo* Simulador::getMundoActivo() const
{
	return mActivo;
}

void Simulador::setMundoActivo(Mundo *m)
{
	mActivo = m;
}


void Simulador::jogoLoop()
{

	Interface inter(this);

	while(1)
	{

		leComando(inter);

	}

}


void Simulador::removeMundo(int pos)
{
	mundos[pos]->removeSeres();
	delete mundos[pos];
	mundos.erase(mundos.begin() + pos);
}

void Simulador::criaMundo(string nome, int lCel, int cCel)
{
	mundos.push_back(new Mundo(nome,lCel,cCel));

}

int Simulador::contaComandos(string comando)
{
	int contaComando;

	if (comando.at(0)==' ')
		contaComando=0;
	else 
		contaComando=1;

	for(unsigned int i=1; i<comando.length() ;i++)
		if (comando[i] != ' ' && comando[i-1] == ' ')
			contaComando++;

	return contaComando;
}



int Simulador::pesquisaMundo(string nome)
{
	for (unsigned int i = 0 ; i < mundos.size() ; i++ )
		if (mundos[i]->getNome()== nome)
			return i;
	return -1;
}


void Simulador::leComandoTXT(string comando)
{
	string nome, str, novo, outro;                 // Where to store each line.
	int  lin, col,nseres;              // Somewhere to put the ints.
	string nomeFich,comandosFich;
	istringstream instream;   // Declare an input string stream
	Consola c;
	int tamanho = 0;
	int verifica = 0 , verifica2 = 0;
	string destino, origem;
	int tempo;
	

	  if(comando.find("mundo") == 0) 
	{ 
		if(contaComandos(comando)!=4)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}


		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> nome >> lin >> col;

		if(lin>Mundo::getmaxLinhas() || col>Mundo::getmaxColunas())
		{
			cout << "Numero de linhas ou colunas invalidas!Prima uma tecla para continuar...";
			cin.get();
			return;
		}

		criaMundo(nome,lin,col);
		mActivo = mundos[mundos.size()-1];

	}

	//COMANDO CRIAI
	else if (comando.find("criai") == 0)
	{
		if(contaComandos(comando)!=2)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}


		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> nseres; 

		if(mActivo != 0)
		{
			tamanho = mActivo->getLinhas()*mActivo->getColunas();


			if(mActivo->getNumPessoas() + /*mActivo->getPessoas().size()*/ + nseres > tamanho)
			{
				cout << "Impossível criar  Idosos!Numero demasiado grande para tamanho do mundo ou mundo cheio!Prima uma tecla para continuar...";
				c.getch(); // só cria se for menor ou igual ao tamanho do mundo ou vai criando até não poder mais?
			}
			else
			{
				for(int i = 0;i < nseres; i++)
				{
					mActivo->acrescentaIdoso();
					mActivo->setTotalSeres(mActivo->getTotalSeres() + 1);	
				}
			}

		}
		else
		{
			cout << "Mundo ainda não foi criado!Prima uma tecla para continuar..." << endl;
			c.getch();
		}


	}
	else if (comando.find("imun") == 0)
	{

		if(contaComandos(comando)!=2)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}

		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> tempo; 


	}

	//COMANDO INFEJ ->define o tempo de duração da infecção num jovem
	else if (comando.find("infej") == 0)
	{

		if(contaComandos(comando)!=2)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}

		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> tempo; 



	}
	//COMANDO INFEI ->define o tempo de duração da infecção num idoso
	else if (comando.find("infei") == 0)
	{

		if(contaComandos(comando)!=2)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}

		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> tempo; 

	}

	//COMANDO MINIMOPESSOAS
	else if (comando.find("minimodepessoas") == 0)
	{
		int  minimo = 0;

		if(contaComandos(comando)!=2)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}

		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> minimo;
		Mundo::setMinPessoas(minimo);
	}

	//COMANDO CRIAJ
	else if (comando.find("criaj") == 0)
	{
		if(contaComandos(comando)!=2)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}


		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> nseres; 


		if(mActivo != 0)
		{
			tamanho = mActivo->getLinhas()*mActivo->getColunas();


			if(mActivo->getNumPessoas()/*mActivo->getPessoas().size()*/ + nseres > tamanho)
			{
				cout << "Impossível criar  Jovens!Numero demasiado grande para tamanho do mundo ou mundo cheio!Prima uma tecla para continuar...";
				c.getch(); // só cria se for menor ou igual ao tamanho do mundo ou vai criando até não poder mais?
			}
			else
			{
				for(int i = 0;i < nseres; i++)
				{
					mActivo->acrescentaJovem();
					mActivo->setTotalSeres(mActivo->getTotalSeres() + 1);
				}
			}

		}
		else
		{
			cout << "Mundo ainda não foi criado!Prima uma tecla para continuar..." << endl;
			c.getch();
		}

	}

	//COMANDO CRIAM
	else if (comando.find("criam") == 0)
	{
		if(contaComandos(comando)!=2)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}


		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str >> nseres; 


		if(mActivo != 0)
		{

			tamanho = mActivo->getLinhas()*mActivo->getColunas();



			if(  mActivo->getNumMosquitos()/*mActivo->getMosquitos().size()*/ + nseres > tamanho)
			{
				cout << "Impossível criar  Mosquitos!Numero demasiado grande para tamanho do mundo ou mundo cheio!Prima uma tecla para continuar...";
				c.getch(); // só cria se for menor ou igual ao tamanho do mundo ou vai criando até não poder mais?
			}
			else
			{
				for(int i = 0;i < nseres; i++)
				{
					mActivo->acrescentaMosquito();
					mActivo->setTotalSeres(mActivo->getTotalSeres() + 1);
				}
			}

		}
		else
		{
			cout << "Mundo ainda não foi criado!Prima uma tecla para continuar...";
			c.getch();
		}

		

	}

	//COMANDO HOSPITAL -> cria e acrescenta um hospital na posição indicada
	else if (comando.find("hospital") == 0)
	{
		if(contaComandos(comando)!=3)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}


		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str  >> lin >> col;; 

		if(lin>Mundo::getmaxLinhas() || col>Mundo::getmaxColunas())
		{
			cout << "Numero de linhas ou colunas invalidas!Prima uma tecla para continuar...";
			cin.get();
			return;
		}


		if(mActivo!=0)
		{
			tamanho = mActivo->getLinhas()*mActivo->getColunas();
			if(!(mActivo->criaHospital(lin,col)))
			{	
				if( tamanho == mActivo->getTerrenos().size())
					cout << "Impossível criar mais Terrenos!Mundo cheio!Prima uma tecla para continuar...";
				else
					cout << "Impossivel criar Hospital na posição indicada!Prima uma tecla para continuar...";

				c.getch();
			}
		}
		else
		{
			cout << "Mundo ainda não foi criado!Prima uma tecla para continuar...";
			c.getch();
		}
	}

	//COMANDO PANTANO -> cria e acrescenta um hospital na posição indicada
	else if (comando.find("pantano") == 0)
	{
		if(contaComandos(comando)!=3)
		{
			cout<<"Numero de comandos invalidos!Prima uma tecla para continuar...";
			cin.get();
			return;
		}


		instream.clear(); // Limpa de erros anteriores possíveis. 
		instream.str(comando);     
		instream >> ws;
		instream>> str  >> lin >> col;; 

		if(lin>Mundo::getmaxLinhas() || col>Mundo::getmaxColunas())
		{
			cout << "Numero de linhas ou colunas invalidas!Prima uma tecla para continuar...";
			cin.get();
			return;
		}

		if(mActivo!=0)
		{
			tamanho = mActivo->getLinhas()*mActivo->getColunas();
			if(!(mActivo->criaPantano(lin,col)))
			{	
				if( tamanho == mActivo->getTerrenos().size())
					cout << "Impossível criar mais Terrenos!Mundo cheio!Prima uma tecla para continuar...";
				else
					cout << "Impossivel criar Pantano na posição indicada!Prima uma tecla para continuar...";

				c.getch();
			}
		}
		else
		{
			cout << "Mundo ainda não foi criado!Prima uma tecla para continuar...";
			c.getch();
		}


	}
}


void Simulador::leFicheiro(string ficheiro)
{
	string line;
	ifstream fich(ficheiro.c_str());
	
	if (fich.is_open())	//Se abriu sem problemas
	{
		while (fich.good())	//Enquanto houver coisas para ler
		{
			getline(fich,line);
			leComandoTXT(line);
		}
		fich.close();
	}
	else 
	{
		cout << "\nImpossivel abrir o ficheiro!" << ficheiro << "'\n";
		exit(EXIT_FAILURE);
	}

}
