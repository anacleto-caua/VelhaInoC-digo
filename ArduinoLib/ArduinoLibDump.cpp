/*



#include <SoftwareSerial.h>
#include "AlgoritmoGenetico.h"

int genes = 10;
int numIndividuos = 2;
float removerPercent = 50;
float mutacaoPercent = 20;

AlgoritmoGenetico ag = AlgoritmoGenetico(genes, numIndividuos, removerPercent, mutacaoPercent);

int pinG[3][3] = {
  {13, 12, 11},
  {10, 9, 8},
  {7, 6, 5}
};

int pinR[3][3] = {
  {14, 15, 16},
  {17, 18, 19},
  {2, 3, 4}
};

void setPin(int ledPin, bool state){
  if(state){
    digitalWrite(ledPin, HIGH); // Turn LED on
  }else{
    digitalWrite(ledPin, LOW); // Turn LED off
  }
}

void setup()
{
  Serial.begin(9600); // abre a porta serial a 9600 bps:

  for(int j = 0; j < 3; j++){ // eixo x
    for(int k = 0; k < 3; k++){ // eixo y
        pinMode(pinG[j][k], OUTPUT);
        pinMode(pinR[j][k], OUTPUT);
    }
  }


  // Cria a primeira geração de indivíduos e define a pontuação máxima possível
  // <<DESFUNCIONAL POR FALTA DE MEMÓRIA PARA EXECUÇÃO>>
  // ag.iniciarSelecao();


  bool pinState = true;
  //Pisca para iniciar o looping de seleção
  for(int i = 0; i < 6; i++){
    for(int j = 0; j < 3; j++){ // eixo x
      for(int k = 0; k < 3; k++){ // eixo y
        setPin(pinG[j][k], pinState);
        setPin(pinR[j][k], pinState);
      }
    }
    
    pinState = !pinState;
    delay(1000);
  
  }
}

void loop()
{

  int (*movimentos)[2];
  int (*linhaVencedora)[2];
  int vencedor;
  bool piscaVencedorState;
  int delayPiscaMs = 2000; // 2 secs

  // Looping de seleção <<DESFUNCIONAL POR FALTA DE MEMÓRIA PARA EXECUÇÃO>>
  /*
  while (ag.maiorPontuacaoRound <= ag.pontuacaoMaxima * 0.7) {

    ag.selecao();

    // Mostra 3 individuos enfrentando o campeão atual
    for(int i = 1; i <= 3; i++){
      ag.competir(0, numIndividuos - i);
      
      movimentos = ag.getMovimentos();
      for(int j = 0; j < 9; j++){
        if(j%2 == 0){
          if(movimentos[j][0] != -1){
            setPin(
                pinG[movimentos[j][0]]
                [movimentos[j][1]]
                , true);
          }
        }else{
          if(movimentos[j][0] != -1){
            setPin(
                pinG[movimentos[j][0]]
                [movimentos[j][1]]
                , piscaVencedorState);
          }
        }

        delay(delayPiscaMs); // Uma jogada a cada sec
      }

      linhaVencedora = ag.getLinhaVencedora();
      vencedor = ag.getVencedor();
      piscaVencedorState = false;
      
      // Comemora a vitória
      if(vencedor != 0){
        for(int k; k < 6; k++){ // Rodar 6 vezes 3 desliga 3 liga ====  (3 piscadas)
          for(int j = 0; j < 3; j++){
            if(vencedor == 1){
              if(linhaVencedora[j][0] != -1){
                setPin(
                    pinG[linhaVencedora[j][0]]
                    [linhaVencedora[j][1]]
                    , piscaVencedorState);
              }
            }else{
              if(linhaVencedora[j][0] != -1){
                setPin(
                    pinR[linhaVencedora[j][0]]
                    [linhaVencedora[j][1]]
                    , piscaVencedorState);
              }
            }

            delay(delayPiscaMs); //Pisca 1sec
            piscaVencedorState = !piscaVencedorState;
          }
        }

      // Se deu velha
      }else{
        piscaVencedorState = false;
        for(int l = 0; l < 7; l++){ // 7 voltar ====== 3 piscadas + 1 apagando todos os leds

          for(int j = 0; j < 3; j++){ // eixo x
            for(int k = 0; k < 3; k++){ // eixo y
                setPin(
                    pinG[j][k]
                    , piscaVencedorState);

                setPin(
                    pinR[j][k]
                    , piscaVencedorState);
            }
          }

          delay(delayPiscaMs); //Pisca 1sec
          piscaVencedorState = !piscaVencedorState;
        }
      }

    }
  }


  int sequenciaMaster[9][2] = {{0,0}, {0,1}, {0,2}, {1,0}, {1,1}, {1,2}, {2,0}, {2,1}, {2,2}};


}

*/