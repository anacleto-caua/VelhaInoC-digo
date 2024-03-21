#include "Tabuleiro.h"

Tabuleiro::Tabuleiro() {
limpaTabuleiro();
}

Tabuleiro::Tabuleiro(int genes)
{
this->genes = genes;
limpaTabuleiro();
}

void Tabuleiro::limpaTabuleiro()
{
vitoriasPrimeiro = 0;
vitoriasSegundo = 0;

for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++) {
tabuleiro[i][j] = 0;
}
}
}

void Tabuleiro::competir(Individuo& a, Individuo& b) {

  limpaTabuleiro();
  limpaMovimentos();

  int genesA = 0;
  int genesB = 0;

  int jogadaA = -1;
  int jogadaB = -1;

  int* move;
  int x, y;

  while (genesA < a.genes && genesB < b.genes) {

    while (!isJogadaValida(jogadaA) && genesA < a.genes) {
      jogadaA = a.dnaX[genesA];
      genesA++;
    }

    if (terminou(genesA, genesB)) {
      break;
    }

    move[0] = codigoParaXY(jogadaA, 0);
    move[1] = codigoParaXY(jogadaA, 1);
    // Serial.print(move[0]);
    // Serial.println(move[1]);

    tabuleiro[move[0]][move[1]] = 1;
    addMovimento(move[0], move[1]);

    while (!isJogadaValida(jogadaB) && genesB < b.genes) {
      jogadaB = b.dnaY[genesB];
      genesB++;
    }

    if (terminou(genesA, genesB)) {
      break;
    }

    move[0] = codigoParaXY(jogadaB, 0);
    move[1] = codigoParaXY(jogadaB, 1);
    // Serial.print(move[0]);
    // Serial.println(move[1]);

    tabuleiro[move[0]][move[1]] = 2;
    addMovimento(move[0], move[1]);

    // for (int i = 0; i < 3; i++) {
    //   for (int j = 0; j < 3; j++) {
    //     Serial.print(tabuleiro[i][j]);
    //     Serial.print(" ");
    //   }
    //   Serial.println();
    // }
  }
  premiar(a, b);
  
}

int Tabuleiro::codigoParaXY(int jogada, int op) {
  int x = 0;
  int y = 0;

  switch (jogada) {
    case 0:
      x = 0;
      y = 0;
      break;
    case 1:
      x = 0;
      y = 1;
      break;
    case 2:
      x = 0;
      y = 2;
      break;
    case 3:
      x = 1;
      y = 0;
      break;
    case 4:
      x = 1;
      y = 1;
      break;
    case 5:
      x = 1;
      y = 2;
      break;
    case 6:
      x = 2;
      y = 0;
      break;
    case 7:
      x = 2;
      y = 1;
      break;
    case 8:
      x = 2;
      y = 2;
      break;
    default:
      // Faz o L!!!!!
      break;
  }

  if(op == 0){
    return x;
  }else{
    return y;
  }
}

bool Tabuleiro::isJogadaValida(int jogada) {
	int x = 0;
	int y = 0;

	switch (jogada) {
    case 0:
      x = 0;
      y = 0;
      break;
    case 1:
      x = 0;
      y = 1;
      break;
    case 2:
      x = 0;
      y = 2;
      break;
    case 3:
      x = 1;
      y = 0;
      break;
    case 4:
      x = 1;
      y = 1;
      break;
    case 5:
      x = 1;
      y = 2;
      break;
    case 6:
      x = 2;
      y = 0;
      break;
    case 7:
      x = 2;
      y = 1;
      break;
    case 8:
      x = 2;
      y = 2;
      break;
    default:
      // Faz o L!!!!!
      return false;
      break;
	}

	if (tabuleiro[x][y] == 0) {
		return true;
	}

	return false;
}

bool Tabuleiro::terminou(int genesA, int genesB) {
	int vencedor = 0;

	for (int i = 0; i < 3; i++) {
		// Caso de vitoria em uma linha
		vencedor = vencedorDaLinha(tabuleiro[0][i], tabuleiro[1][i], tabuleiro[2][i]);
		if (vencedor != 0) {
			this->vencedorRound = vencedor;
			addLinhaVencedora(0, i, 1, i, 2, i);
			return true;
		}

		// Caso de vitoria em uma coluna
		vencedor = vencedorDaLinha(tabuleiro[i][0], tabuleiro[i][1], tabuleiro[i][2]);
		if (vencedor != 0) {
			this->vencedorRound = vencedor;
			addLinhaVencedora(i, 0, i, 1, i, 2);
			return true;
		}
	}

	// Caso de vitoria em diagonal
	vencedor = vencedorDaLinha(tabuleiro[0][0], tabuleiro[1][1], tabuleiro[2][2]);
	if (vencedor != 0) {
		this->vencedorRound = vencedor;
		addLinhaVencedora(0, 0, 1, 1, 2, 2);
		return true;
	}

	// Caso de vitoria em diagonal inversa
	vencedor = vencedorDaLinha(tabuleiro[0][2], tabuleiro[1][1], tabuleiro[2][0]);
	if (vencedor != 0) {
		this->vencedorRound = vencedor;
		addLinhaVencedora(0, 2, 1, 1, 2, 0);
		return true;
	}

	int preenchidos = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (tabuleiro[i][j] != 0) {
				preenchidos++;
			}
		}
	}

	//DeuVelha
	if (preenchidos >= 9) {
		this->vencedorRound = 0;
		return true;
	}

	if (genesA >= genes - 1) {
		this->vencedorRound = 2;
		return true;
	}
	else if (genesB >= genes - 1) {
		this->vencedorRound = 1;
		return true;
	}
	this->vencedorRound = 0;

	return false;
}

int Tabuleiro::vencedorDaLinha(int a, int b, int c) {
	if (a == 1 && b == 1 && c == 1) {
		return 1;
	}
	else if (a == 2 && b == 2 && c == 2) {
		return 2;
	}

	return 0;
}

void Tabuleiro::premiar(Individuo& a, Individuo& b) {
	if (vencedorRound == 1) {
		a.premiarVitoria();
		b.premiarDerrota();
	}
	else if (vencedorRound == 2) {
		a.premiarDerrota();
		b.premiarVitoria();
	}
	else {
		a.premiarEmpate();
		b.premiarEmpate();
	}

}

void Tabuleiro::limpaMovimentos() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 2; j++) {
			movimentos[i][j] = -1;
		}
	}
	movimentosContador = 0;
}

void Tabuleiro::addMovimento(int x, int y) {
	movimentos[movimentosContador][0] = x;
	movimentos[movimentosContador][1] = y;

	movimentosContador++;
}

void Tabuleiro::addLinhaVencedora(int ax, int ay, int bx, int by, int cx, int cy) {
	int linha[3][2];

	this->linhaVencedora[0][0] = ax;
	this->linhaVencedora[0][1] = ay;

	this->linhaVencedora[1][0] = bx;
	this->linhaVencedora[1][1] = by;

	this->linhaVencedora[2][0] = cx;
	this->linhaVencedora[2][1] = cy;
}

int Tabuleiro::getVencedor() {
	return this->vencedorRound;
}