//#include <iostream>
//#include "Jogo.h"
//#include "Mundo.h"
//
//Jogo::Jogo()
//{
//	string comando;
//
//  comando = i.leComando();
//  trataComando(comando);
//}
//
//void Jogo::trataComando(string comando)
//{
//			string nome, str;                 // Where to store each line.
//			int  lin, col;              // Somewhere to put the ints.
//			istringstream instream;   // Declare an input string stream
//
//			
//        if(comando.find("mundo") == 0) 
//		 { // Reads line into s
//			 
//			instream.clear();
//			instream.str(comando);     // Reset from possible previous errors. 
//			instream >> ws;
//			instream>> str >> nome >> lin >> col; 
//			
//			
//			criaMundo();
//
//		}
//	/*	else if (comando.find("criai") == 0)
//		{
//			if (m);
//			m.adicionaSerVivo('I');
//			else
//				cout << "Mundo ainda não foi criado!Crie o mundo primeiro!" << endl;
//			
//		}*/
//		else if (comando.compare("sair") == 0)
//		{
//		exit(0);
//		}
//}
//
//Jogo::carregaMundo()
//{
//
//}
//
//void Jogo::criaMundo()
//{
//  Mundo m = new Mundo(nome,lin,col);
//}