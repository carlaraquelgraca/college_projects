//#ifndef MAPA_H_
//#define MAPA_H_
//#include <string>
//#include <vector>
//using namespace std;
//
//class Mapa
//{
//	int x;		//Coordenada xx da C�lula
//	int y;		//Coordenada yy da C�lula
//	int cor_celula;
//
//	string tipo;	//O que est� na c�lula. (Cidade, Artefacto, Habitante...)
//	int id;			//Id do que est� na c�lula. (01, 02, ..., 99)
//				
//public:
//
//	Mapa(const int numColuna, const int numLinha, const string tipo = " ", const int id = -1);
//	~Mapa(void);
//
//	/////GETS
//	int getX() const;
//	int getY() const;
//	string getTipo() const;
//	int getID() const;
//
//	/////SETS
//	void setX(const int coord);
//	void setY(const int coord);
//	void setTipo(const string tipo);
//	void setID(const int ID);
//
//	/////Manipula��o
//	int remove(const int id);
//	void insere(const string tipo, const int id);
//};
//#endif