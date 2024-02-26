#pragma once
#include <pRNG.h>

using  namespace std;

class Individuo
{
	public:
		int genes;
	
		int* dnaX;
	  int* dnaY;
	
		int vitorias = 0;
		int derrotas = 0;
		int empates = 0;
		int pontuacao = 0;

    pRNG prng;

		Individuo();

		Individuo(int genes);

		Individuo(Individuo pai, Individuo mae);

		int randomGene();
		int zeroOuUm();

		void limparPontuacaoIndividuo();
		void mutacao();

		void premiarVitoria();
		void premiarDerrota();
		void premiarEmpate();

    int randomA(int max);

    int randomA(int min, int max);
};

