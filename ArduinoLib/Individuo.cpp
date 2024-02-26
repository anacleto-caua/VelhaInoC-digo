#include "Individuo.h"
#include <SoftwareSerial.h>

Individuo::Individuo() {

  pRNG prng;

	this->genes = 0;

	this->vitorias = 0;
	this->derrotas = 0;
	this->empates = 0;
	this->pontuacao = 0;

	this->dnaX = new int[genes];
	this->dnaY = new int[genes];

	for (int i = 0; i < genes; i++) {
		dnaX[i] = randomGene();
		dnaY[i] = randomGene();
	}
}

Individuo::Individuo(int genes) {
  pRNG prng;
  
	this->genes = genes;

	this->vitorias = 0;
	this->derrotas = 0;
	this->empates = 0;
	this->pontuacao = 0;
	
	this->dnaX = new int[genes];
	this->dnaY = new int[genes];

	for (int i = 0; i < genes; i++) {
		dnaX[i] = randomGene();
		dnaY[i] = randomGene();
	}
}

Individuo::Individuo(Individuo pai, Individuo mae) {
  pRNG prng;

	this->genes = pai.genes;

	this->vitorias = 0;
	this->derrotas = 0;
	this->empates = 0;
	this->pontuacao = 0;
	
	this->dnaX = new int[genes];
	this->dnaY = new int[genes];

	for (int i = 0; i < genes; i++) {
		if (zeroOuUm() == 0) {
			dnaX[i] = pai.dnaX[i];
		}
		else {
			dnaX[i] = mae.dnaX[i];
		}

		if (zeroOuUm() == 0) {
			dnaY[i] = pai.dnaY[i];
		}
		else {
			dnaY[i] = mae.dnaY[i];
		}
	}
}

int Individuo::randomGene()
{
	// Return the generated random integer
	return randomA(9);
}

int Individuo::zeroOuUm()
{
	// Return the generated random integer
	return randomA(2);
}

void Individuo::limparPontuacaoIndividuo() {
	this->vitorias = 0;
	this->derrotas = 0;
	this->empates = 0;
	this->pontuacao = 0;
}

void Individuo::mutacao() {
	dnaX[randomA(genes)] = randomGene();
	dnaY[randomA(genes)] = randomGene();
}

void Individuo::premiarVitoria() {
	vitorias++;
	pontuacao += 3;
}

void Individuo::premiarDerrota() {
	derrotas++;
	pontuacao += 0;
}

void Individuo::premiarEmpate() {
	empates++;
	pontuacao += 1;
}

int Individuo::randomA(int max){
  int randomByte = prng.getRndInt();

  int dif = max;

  int rng = (randomByte % max);

  return rng;
}

int Individuo::randomA(int min, int max){
  int randomByte = prng.getRndInt();

  int div = min - 0;
  int dif = max - div;

  int rng = (randomByte % (dif + 1)) + div;

  return rng;
}