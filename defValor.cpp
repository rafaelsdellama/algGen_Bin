/******************************************************************************\
*						 Definicao Valor(inicializacao)						 *
\******************************************************************************/

#include "defTipo.h"

/* Definicao da variaveis globais */
populacao popVelha , popNova;		
double *arq_media_fitness, *arq_melhor_fitness; 	// dados para serem gravados
int **arq_melhor_individuo;							// dados para serem gravados


// Parametros da simulacao
int nroMaxExec = 1;								// numero de repeticoes do AG
int maxGen = 90;									// numero maximo de geracoes 

// Parametros do AG
double taxaCross = 0.6;								// taxa de crossover
double taxaMut = 1.0/lcrom;							// taxa de mutacao

int tamPop = 100;									// tamanho da pop. 
int lcrom = 96;										// tamanho do cromossomo 

bool elitismo = true;								// true: elitismo ; false: sem elitismo
int tamTorneio = 3;									// tamanho do torneio (usado na selecao por torneio)

//Hipermutação
bool hipermutacao = true;							// true: hipermutacao ; false: sem hipermutacao
int tamCiclo = 10;//maxGen/100;							// tamanho do ciclo de hipermutação
double taxaR = 3;									//porcentagem de acrescimo na taxa de mutação (1 + taxaR)*tavaMut
bool cicloHipermutacao = false;						//determina se acabou de ocorrer um ciclo de hipermutação - NÃO ALTERAR

//Imigração
bool imigracao = false;								// true: imigracao ; false: sem imigracao
double taxaMigracao = 0.05;							// taxa de imigrantes
