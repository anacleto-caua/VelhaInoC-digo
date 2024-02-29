#pragma once
#include "IndividuoStruct.cpp"
#include "RandomAnacleto.h"

class Tabuleiro
{
public:

	Individuo a;
	Individuo b;
	
	int vitoriasPrimeiro;
	int vitoriasSegundo;

	int vencedorRound;
	
	int tabuleiro[3][3];

  int movimentos[9][2];
  int movimentosContador = 0;

  int linhaVencedora[3][2];


	Tabuleiro();

	void limpaTabuleiro();

	void competir(Individuo& a, Individuo& b);

	int* codigoParaXY(int jogada);

	bool isJogadaValida(int jogada);

	bool terminou();
	
	int vencedorDaLinha(int a, int b, int c);

	void premiar();

  void limpaMovimentos();
  
  void addMovimento(int x, int y);

  void addLinhaVencedora(int ax, int ay, int bx, int by, int cx, int cy);

  int getVencedor();
};

