#pragma once
#include "Tabuleiro.h"
#include "IndividuoStruct.cpp"
#include <pRNG.h>

class AlgoritmoGenetico
{
public:
	int rounds;

	int genes;
	int numIndividuos;
	float removerPercent;
	float mutacaoPercent;

  int maiorPontuacaoRound = 0;
  int pontuacaoMaxima;

  Tabuleiro tabuleiro;

	Individuo* individuos;

  pRNG prng;

	AlgoritmoGenetico(int genes, int numIndividuos,  float removerPercent, float mutacaoPercent);

	void gerarPopulacaoInicial();

	void competir();

	void competir(int i, int j);

	void ordenarPopulacao();

	bool compareIndividuos(const Individuo& a, const Individuo& b);
	
	void eliminarPopulacao();

	void limparPontuacaoPopulacao();

	void cruzarPopulacao();

  void iniciarSelecao();
	
  void selecao();

	void apresentacao();

  int (*getMovimentos())[2];

  int (*getLinhaVencedora())[2];

  int getVencedor();

  int8_t randomA(int max);

  int8_t randomA(int min, int max);
};

