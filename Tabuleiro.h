#pragma once
#include "IndividuoStruct.cpp"

class Tabuleiro
{
public:

	int vitoriasPrimeiro;
	int vitoriasSegundo;

	int vencedorRound;

	int tabuleiro[3][3];

	int movimentos[9][2];
	int movimentosContador = 0;

	int linhaVencedora[3][2];

	int genes;

	Tabuleiro();

	Tabuleiro(int genes);

	void limpaTabuleiro();

	void competir(Individuo& a, Individuo& b);

	int codigoParaXY(int jogada, int op);

	bool isJogadaValida(int jogada);

	bool terminou(int genesA, int genesB);

	int vencedorDaLinha(int a, int b, int c);

	void premiar(Individuo& a, Individuo& b);

	void limpaMovimentos();

	void addMovimento(int x, int y);

	void addLinhaVencedora(int ax, int ay, int bx, int by, int cx, int cy);

	int getVencedor();
};

