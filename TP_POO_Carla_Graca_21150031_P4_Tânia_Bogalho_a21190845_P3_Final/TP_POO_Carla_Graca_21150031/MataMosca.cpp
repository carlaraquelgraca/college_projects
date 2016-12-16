#include <iostream>
#include <string>
#include "Pessoa.h"
#include "Ponto.h"
#include "MataMosca.h"
#include "Mundo.h"
using namespace std;

int Idoso::tempoInfI = 6;// o tempo de infecção de jovens, tempode infecção de idosos e tempo de imunidade são comuns a todos os objectos da classe mundo e não precisam de existir mundos para serem configurados 

MataMosca::MataMosca(string letra,int num,Ponto p):Pessoa(letra,num,p)
{

	
}

MataMosca::~MataMosca()
{
}

void MataMosca:agir(Mundo m) const
{
	m->
}