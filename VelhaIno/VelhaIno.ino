#include <SoftwareSerial.h>
#include "AlgoritmoGenetico.h"

int8_t genes = 10;
int8_t numIndividuos = 5;
float removerPercent = 50;
float mutacaoPercent = 20;

AlgoritmoGenetico ag = AlgoritmoGenetico(genes, numIndividuos, removerPercent, mutacaoPercent);

int8_t pinG[3][3] = {
  {13, 12, 11},
  {10, 9, 8},
  {7, 6, 5}
};

int8_t pinR[3][3] = {
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
  Serial.begin(115200); // abre a porta serial a 9600 bps:

  for(int j = 0; j < 3; j++){ // eixo x
    for(int k = 0; k < 3; k++){ // eixo y
        pinMode(pinG[j][k], OUTPUT);
        pinMode(pinR[j][k], OUTPUT);
    }
  }


  // Cria a primeira geração de indivíduos e define a pontuação máxima possível
  // <<DESFUNCIONAL POR FALTA DE MEMÓRIA PARA EXECUÇÃO>>
  ag.iniciarSelecao();


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
    delay(300);

  
  }

  Serial.println();
  Serial.println();
  Serial.println("Fim!!!");

}

void loop() {

  Serial.println(ag.rounds);
  Serial.println(ag.maiorPontuacaoRound);
  
  ag.selecao();

 
  
  delay(1000);
}
