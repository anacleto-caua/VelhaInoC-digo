#include <SoftwareSerial.h>
#include "AlgoritmoGenetico.h"

int8_t genes = 20;
int8_t numIndividuos = 10;
float removerPercent = 50;
float mutacaoPercent = 20;

AlgoritmoGenetico ag = AlgoritmoGenetico(genes, numIndividuos, removerPercent, mutacaoPercent);

/*
// Pinos

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
*/


// // Variaveís para medição do tempo
// unsigned long inicio_preparacao = 0; 
// unsigned long fim_preparacao = 0;
// unsigned long tempo_preparacao = 0;

unsigned long inicio_iteracoes = 0; 
unsigned long tempo_iteracoes = 0;

void setup()
{

  // inicio_preparacao = millis(); 
  
  Serial.begin(115200); // abre a porta serial a 9600 bps:

  // Cria a primeira geração de indivíduos e define a pontuação máxima possível
  Serial.println("Iniciando ag para seleção");
  ag.iniciarSelecao();
  Serial.println("Ag para seleção iniciado");
  
  // fim_preparacao = millis();

  // tempo_preparacao = fim_preparacao - inicio_preparacao;
}

// Loop básico, sem interação com os leds
void loop()
{

  Serial.print("Pontuacao necessária: ");
  Serial.println(ag.pontuacaoMaxima * 0.7);
  
  inicio_iteracoes = millis();
  // Serial.print("Primeira medicao: ");
  // Serial.println(inicio_iteracoes);

  // for(int testes = 0; testes < 1000; testes++){

    // Algoritmo de seleção limite 20 rounds 70% cobrança
    while(ag.rounds < 20 && ag.maiorPontuacaoRound < ag.pontuacaoMaxima * 0.7){
      
      ag.selecao();

      Serial.print("Rounds: ");
      Serial.println(ag.rounds);

      Serial.print("Maior pontuacao round: ");
      Serial.println(ag.maiorPontuacaoRound);
    
    }

  //   ag.resetarAg();

  // }
  
  tempo_iteracoes = millis() - inicio_iteracoes;

  Serial.println("Fim da seleção");
  /*

  Serial.print("Rounds: ");
  Serial.println(ag.rounds);

  Serial.print("Maior pontuacao round: ");
  Serial.println(ag.maiorPontuacaoRound);

  */
  Serial.print("Inicio Iteracoes: ");
  Serial.println(inicio_iteracoes);

  Serial.print("Tempo Iteracoes: ");
  Serial.println(tempo_iteracoes);

  delay(100000000);
}

// Loop complexo, interage com os leds
// void loop()
// {

//   int (*movimentos)[2];
//   int (*linhaVencedora)[2];
//   int vencedor;
//   bool piscaVencedorState;

//   int delayPiscaVencedor = 300; // 2 secs
//   int delayPiscaComemoracao = 150; // 2 secs
//   int delayPiscaVelha = 150; // 2 secs

//   if(ag.rounds == 0){
//     Serial.println("Inicio do looping de seleção.");

//     Serial.print("Pontuacao necessária: ");
//     Serial.println(ag.pontuacaoMaxima * 0.7);

//   }else{
//     Serial.println("Fim da seleção");
//     delay(10000);
//   }

//   while (ag.rounds < 20 && ag.maiorPontuacaoRound <= ag.pontuacaoMaxima * 0.7) {

//     ag.selecao();

//     Serial.print("Rounds: ");
//     Serial.println(ag.rounds);

//     Serial.print("Maior pontuacao round: ");
//     Serial.println(ag.maiorPontuacaoRound);

//     delay(2000);

//     // Mostra 3 individuos enfrentando o campeão atual
//     for(int i = 1; i <= 3; i++){
//       ag.competir(0, numIndividuos - i);
      
//       movimentos = ag.getMovimentos();
//       for(int j = 0; j < 9; j++){
//         if(j%2 == 0){
//           if(movimentos[j][0] != -1){
//             setPin(
//                 pinG[movimentos[j][0]]
//                 [movimentos[j][1]]
//                 , true);
//           }
//         }else{
//           if(movimentos[j][0] != -1){
//             setPin(
//                 pinR[movimentos[j][0]]
//                 [movimentos[j][1]]
//                 , true);
//           }
//         }

//         delay(delayPiscaVencedor); // Uma jogada a cada sec
//       }

//       vencedor = ag.getVencedor();
      
//       // Comemora a vitória
//       if(vencedor != 0){
//         linhaVencedora = ag.getLinhaVencedora();
//         piscaVencedorState = false;
        
//         for(int k = 0; k < 7; k++){ // Rodar 6 vezes 3 desliga 3 liga ====  (3 piscadas)
//           for(int j = 0; j < 3; j++){
//             if(vencedor == 1){
//               if(linhaVencedora[j][0] != -1){
//                 setPin(
//                     pinG[linhaVencedora[j][0]]
//                     [linhaVencedora[j][1]]
//                     , piscaVencedorState);
//               }
//             }else{
//               if(linhaVencedora[j][0] != -1){
//                 setPin(
//                     pinR[linhaVencedora[j][0]]
//                     [linhaVencedora[j][1]]
//                     , piscaVencedorState);
//               }
//             }

//             delay(delayPiscaComemoracao);
//           }
//           piscaVencedorState = !piscaVencedorState;
//         }

//       // Se deu velha
//       }else{
//         piscaVencedorState = false;
//         for(int l = 0; l < 7; l++){ // 7 voltar ====== 3 piscadas + 1 apagando todos os leds

//           for(int j = 0; j < 3; j++){ // eixo x
//             for(int k = 0; k < 3; k++){ // eixo y
//                 setPin(
//                     pinG[j][k]
//                     , piscaVencedorState);

//                 setPin(
//                     pinR[j][k]
//                     , piscaVencedorState);
//             }
//           }

//           delay(delayPiscaVelha); //Pisca 1sec
//           piscaVencedorState = !piscaVencedorState;
//         }
//       }

//       // Apaga todos os leds ao final da comemoração
//       for(int j = 0; j < 3; j++){ // eixo x
//        for(int k = 0; k < 3; k++){ // eixo y
//           setPin(pinG[j][k], false);
//           setPin(pinR[j][k], false);
//         }
//       }

//     }
//   }

  
// }

