/******************************************************************************\
*								 Fitness:									 *
\******************************************************************************/
#include "defTipo.h"
#include <cstdlib>
#include <cmath>

/******************************************************************************\
*								Calculo Fitness 							 *
\******************************************************************************/
double calcFitness(alelo *indiv, int gen)
{
	double Fitness = 0;
	
	for(int i = 0; i < lcrom; i++)
		Fitness = Fitness + indiv[i];

	return Fitness;
}

