#include "RandomAnacleto.h"

RandomAnacleto::RandomAnacleto(){
  pRNG prng;
}

int RandomAnacleto::randomA(int max){
  int randomByte = prng.getRndInt();

  int dif = max;

  int rng = (randomByte % max);

  return rng;
}

int RandomAnacleto::randomA(int min, int max){
  int randomByte = prng.getRndInt();

  int div = min - 0;
  int dif = max - div;

  int rng = (randomByte % (dif + 1)) + div;

  return rng;
}