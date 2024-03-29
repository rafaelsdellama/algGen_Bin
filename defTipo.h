/******************************************************************************\
*								 Definicoes							 *
\******************************************************************************/
#include <iostream>

using namespace std; 

/* Definicao dos tipos de dados */
typedef int alelo; 							// tipo de dado que os alelos podem assumir 
typedef struct estrutura_individuo {
			alelo *cromossomo;				// cromossomo
			double fitness;					// funcao de avaliacao	
			int pai1 , pai2 ;				// indice dos pais 	
} individuo;

typedef struct {
			individuo *indiv;
			double somaFitness;
			double mediaFitness;
			double maxFitness;
			int melhorIndividuo;
			int melhorIndividuo2;			
} populacao;


/* Definicao da variaveis globais */
extern populacao popVelha , popNova;		
extern int nroMaxExec;									// numero de repeticoes do AG
extern int tamPop, lcrom, maxGen;
extern double taxaCross , taxaMut;						// taxas de crossover e mutacao
extern int tamTorneio;									// tamanho do torneio (usado na selecao por torneio)
extern double *arq_media_fitness, *arq_melhor_fitness;  // dados para serem gravados
extern int **arq_melhor_individuo;						// dados para serem gravados
extern bool elitismo;									// true: elitismo ; false: sem elitismo
extern bool imigracao;									// true: imigracao ; false: sem imigracao
extern double taxaMigracao;								// taxa de imigra��o
extern bool hipermutacao;								// true: hipermutacao ; false: sem hipermutacao
extern int tamCiclo;									// tamanho do ciclo de hipermuta��o
extern double taxaR;									//porcentagem de acrescimo na taxa de muta��o
extern bool cicloHipermutacao;							//determina se acabou de ocorrer um ciclo de hipermuta��o

/*Declara��o das fun��es */
void algGen ( int nroExec);
void inicializacao(int nroExec);
void impressao(populacao *pop , int gen);
double calcFitness(alelo *indiv, int gen);
int *aloc_vectori(int lines);
double *aloc_vectord(int lines);
individuo *aloc_vectorind(int lines);
int **aloc_matrixi(int lines , int collums);
void desaloc_matrixi(int **Matrix , int lines);
int random_int(int L_range, int H_range);
double random_dou(void);
void estatistica( populacao *pop , int gen );
int selecao( populacao *pop , int j );
void geracao(int gen);
void crossover(alelo *pai1, alelo *pai2, alelo *filho1 , alelo *filho2 ,  int j );
void arq_saida(int nroExec);
void salv_pop(int nroExec);
void ler_pop(int nroExec);
void apaga_arquivos(int nroExec);
void imigranteAleatorio();
void calcHipermutacao(int gen);
