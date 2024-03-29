#include "AlgoritmoGenetico.h"

AlgoritmoGenetico::AlgoritmoGenetico(int genes, int numIndividuos, float removerPercent, float mutacaoPercent)
{

	rounds = 0;

	this->genes = genes;
	this->numIndividuos = numIndividuos;
	this->removerPercent = removerPercent;
	this->mutacaoPercent = mutacaoPercent;

	this->tabuleiro = Tabuleiro(genes);

	individuos = new Individuo[numIndividuos];

  pRNG prng;
}

void AlgoritmoGenetico::resetarAg(){
  rounds = 0;
  maiorPontuacaoRound = 0;
  gerarPopulacaoInicial();
}

void AlgoritmoGenetico::gerarPopulacaoInicial()
{
	for (int i = 0; i < numIndividuos; i++) {
		individuos[i] = Individuo(genes);
	}
}

void AlgoritmoGenetico::competir()
{
	for (int i = 0; i < numIndividuos; i++) {
		for (int j = 0; j < numIndividuos; j++) {
			if (i != j) {
				tabuleiro.competir(individuos[i], individuos[j]);

			}
		}
	}

}

void AlgoritmoGenetico::competir(int i, int j)
{
	tabuleiro.competir(individuos[i], individuos[j]);
}

bool AlgoritmoGenetico::compareIndividuos(const Individuo& a, const Individuo& b)
{
	return a.pontuacao > b.pontuacao;
}

void AlgoritmoGenetico::ordenarPopulacao()
{
	/*
		sort(individuos.begin(), individuos.end(), [](const Individuo& a, const Individuo& b) {
			return a.pontuacao > b.pontuacao;
		});
	*/

	for (int i = 0; i < this->numIndividuos; i++) {
		int maior = i;
		for (int j = i + 1; j < this->numIndividuos; j++) {
			if (individuos[j].pontuacao > individuos[maior].pontuacao) {
				maior = j;
			}
		}

		if (maior != i) {
			Individuo aux = individuos[i];
			individuos[i] = individuos[maior];
			individuos[maior] = aux;
		}
	}
}

void AlgoritmoGenetico::eliminarPopulacao()
{
	int remocao = numIndividuos * removerPercent / 100.0;

	for (int i = 0; i < remocao; i++) {
		individuos[i];
	}
}

void AlgoritmoGenetico::limparPontuacaoPopulacao()
{
	for (int i = 0; i < this->numIndividuos; i++) {
		individuos[i].limparPontuacaoIndividuo();
	}
}

void AlgoritmoGenetico::cruzarPopulacao()
{
	int remocao = numIndividuos * removerPercent / 100.0;

	/**
	Individuo ind;
	while (individuos.size() != numIndividuos) {
	  for (int i = 0; i < numIndividuos - remocao && individuos.size() != numIndividuos; i += 2) {
		ind = Individuo(individuos[i], individuos[i + 1]);

		random_device rd;
		mt19937 generator(rd()); //use the Mersenne Twister algorithm to generate numbers

		uniform_int_distribution<int> generate(1, 100);
		if (generate(generator) < mutacaoPercent) {
		  ind.mutacao();
		}

		if (individuos.size() != numIndividuos) {
		  individuos.push_back(ind);
		}
	  }
	}
	*/

	int id_pai = 0;
	int id_mae = 1;

	for (int i = numIndividuos - 1 - remocao; i < numIndividuos - 1; i++) {

		individuos[i].cruzar(individuos[id_pai], individuos[id_mae]);

		if (randomA(100) + 1 < mutacaoPercent) {
			individuos[i].mutacao();
		}

		id_pai++;
		id_mae++;

		if (id_mae >= numIndividuos - 1 - remocao) {
			id_pai = 0;
			id_mae = 1;
		}
	}

}

void AlgoritmoGenetico::iniciarSelecao()
{
	this->pontuacaoMaxima = ((numIndividuos-1) * 2) * 3;

	gerarPopulacaoInicial();
}

void AlgoritmoGenetico::selecao()
{
	competir();

	ordenarPopulacao();

	this->maiorPontuacaoRound = individuos[0].pontuacao;

	limparPontuacaoPopulacao();

	eliminarPopulacao();

	cruzarPopulacao();

	rounds++;
}

void AlgoritmoGenetico::apresentacao()
{
	/*
	  cout << "Tamanho: " << numIndividuos << endl;

	  cout << "Round: " << rounds << endl;
	  cout << "Melhor individuo" << endl;
	  cout << "Pontuacao: " << individuos[0].pontuacao << endl;
	  cout << "Jogadas: " << individuos[0].vitorias + individuos[0].empates + individuos[0].derrotas << endl;
	  cout << "Pior individuo" << endl;
	  cout << "Pontuacao: " << individuos[numIndividuos-1].pontuacao << endl;
	*/
}

int(*AlgoritmoGenetico::getMovimentos())[2] {
	return this->tabuleiro.movimentos;
}

int(*AlgoritmoGenetico::getLinhaVencedora())[2] {
	return this->tabuleiro.linhaVencedora;
}

int AlgoritmoGenetico::getVencedor() {
	return this->tabuleiro.getVencedor();
}

int AlgoritmoGenetico::randomA(int max){
    int randomByte = prng.getRndInt();

    int dif = max;

    int8_t rng = ((unsigned int)randomByte % max);

    return rng;
  }

  int AlgoritmoGenetico::randomA(int min, int max){
    int randomByte = prng.getRndInt();

    int div = min - 0;
    int dif = max - div;

    int8_t rng = ((unsigned int)randomByte % (dif + 1)) + div;

    return rng;
  }