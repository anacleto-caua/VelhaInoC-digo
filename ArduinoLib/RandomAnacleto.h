#pragma once
#include <pRNG.h>

class RandomAnacleto
{
public:
  pRNG prng;

  RandomAnacleto::RandomAnacleto();

  int randomA(int max);

  int randomA(int min, int max);
};