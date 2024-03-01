#pragma once
#include <pRNG.h>

struct Individuo {
    int genes;

    int8_t* dnaX;
    int8_t* dnaY;

    int vitorias = 0;
    int derrotas = 0;
    int empates = 0;
    int pontuacao = 0;

    pRNG prng;

    Individuo() {

        this->genes = 0;

        this->vitorias = 0;
        this->derrotas = 0;
        this->empates = 0;
        this->pontuacao = 0;

        this->dnaX = new int8_t[genes];
        this->dnaY = new int8_t[genes];

        for (int i = 0; i < genes; i++) {
            dnaX[i] = randomGene();
            dnaY[i] = randomGene();
        }
    }


    Individuo(int genes) {

        this->genes = genes;

        this->vitorias = 0;
        this->derrotas = 0;
        this->empates = 0;
        this->pontuacao = 0;

        this->dnaX = new int8_t[genes];
        this->dnaY = new int8_t[genes];

        for (int i = 0; i < genes; i++) {
            dnaX[i] = randomGene();
            dnaY[i] = randomGene();
        }
    }

    Individuo(Individuo pai, Individuo mae) {

        this->genes = pai.genes;

        this->vitorias = 0;
        this->derrotas = 0;
        this->empates = 0;
        this->pontuacao = 0;

        this->dnaX = new int8_t[genes];
        this->dnaY = new int8_t[genes];

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

    int8_t randomGene()
    {
        // Return the generated random integer
        return randomA(9);
    }

    int zeroOuUm()
    {
        // Return the generated random integer
        return randomA(2);
    }

    void limparPontuacaoIndividuo() {
        this->vitorias = 0;
        this->derrotas = 0;
        this->empates = 0;
        this->pontuacao = 0;
    }

    void mutacao() {
        dnaX[randomA(genes)] = randomGene();
        dnaY[randomA(genes)] = randomGene();
    }

    void premiarVitoria() {
        vitorias++;
        pontuacao += 3;
    }

    void premiarDerrota() {
        derrotas++;
        pontuacao += 0;
    }

    void premiarEmpate() {
        empates++;
        pontuacao += 1;
    }

    int8_t randomA(int max){
    int randomByte = prng.getRndInt();

    int dif = max;

    int8_t rng = ((unsigned int)randomByte % max);

    return rng;
  }

  int8_t randomA(int min, int max){
    int randomByte = prng.getRndInt();

    int div = min - 0;
    int dif = max - div;

    int8_t rng = ((unsigned int)randomByte % (dif + 1)) + div;

    return rng;
  }
};
