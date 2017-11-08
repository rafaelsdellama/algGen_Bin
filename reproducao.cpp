/******************************************************************************\
*									 Reproducao								 *
\******************************************************************************/

#include "defTipo.h"
#include <cstdlib>

/******************************************************************************\
*								 Mutacao (inteiro)							 *
\******************************************************************************/
int mutacao(alelo valorAlelo )
{
		int valor;
		
		if ( random_dou () < taxaMut  ) {
			if (valorAlelo == 0){
				valor = 1;
			}
			else {
				valor = 0;
			}
		}
		else {
			valor = valorAlelo;
		}
		return valor;
}

/******************************************************************************\
*								 Crossover	- 2 pontos 						 *
\******************************************************************************/
void crossover(alelo *pai1, alelo *pai2, alelo *filho1 , alelo *filho2 ,  int j )
{
		 int auxiliar, gene, cruzamento1 = 0, cruzamento2 = 0;
	
	
		 if ( random_dou() < taxaCross  ) {
				/* cruzamentos : verifica se pontos sao iguais */
				while (cruzamento1 == cruzamento2) {
					cruzamento1 = random_int (0,lcrom-1); 	// define ponto de cruzamento entre 1 e l-1
					cruzamento2 = random_int (0,lcrom-1); 	// define ponto de cruzamento entre 1 e l-1
				}
				/* ordena cruzamento 1 e 2 */
				if (cruzamento1 > cruzamento2) {
					auxiliar = cruzamento1;
					cruzamento1 = cruzamento2;
				  	cruzamento2 = auxiliar;
				}
         }
		 if ( elitismo == 1 && j < 2 ) {
				cruzamento1 = 0;
				cruzamento2 = 0;
		 }
		/* gera Individuos */
		for (gene = 0; gene < lcrom; gene++) {
			if (gene < cruzamento1 || gene >= cruzamento2) {
				if  ( elitismo == 1 && j < 2 ) {
					filho1[gene] = pai1[gene];					// filho 1 
					filho2[gene] = pai2[gene];	
				}
				else {
					filho1[gene] = mutacao(pai1[gene]);			// filho 1 
					filho2[gene] = mutacao(pai2[gene]);
				}
			}
			else {
				filho1[gene] = mutacao(pai2[gene]);				// filho 1 
				filho2[gene] = mutacao(pai1[gene]);			
			}	
		}	
}


