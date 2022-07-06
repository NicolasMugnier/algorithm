#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "tableau.h"
#include "algorithmesDeTris.h"

#define N 10000

int main()
{
	int n,j,k,x;
	int t[N];
	clock_t t1,t2;
	 
	srand(time(NULL));
	
	n=N;

	generationTableauDesordonne(t,n);
	//generationTableauOrdonne(t,n);

	t1=clock();
	
	/***** tri par insertion *****/
	//Insertion(t,n);
	// RESULTATS
	// TABLEAUX TRIES
		// 500 => 0
		// 1000 => 0
		// 10000 => 0
		// 100000 => 0
	// TABLEAUX NON TRIES
		// 500 => 0
		// 1000 => 0
		// 10000 => 0.170
		// 100000 => 17.670
	// Cet algorithme détecte si le tablea est trié ou pas
	
	/***** tri par selection *****/
	//Selection(t,n);
	// RESULTATS
	// TABLEAUX TRIES
		// 500 => 0
		// 1000 => 0
		// 10000 => 0.250
		// 100000 => 26.030
	// TABLEAUX NON TRIES
		// 500 => 0
		// 1000 => 0
		// 10000 => 0.160
		// 100000 => 16.650
	
	/***** tri par échange *****/
	//Echange(t,n);
	// RESULTATS
	// TABLEAUX TRIES
		// 500 => 0
		// 1000 => 0
		// 10000 => 0.210
		// 100000 => 21.740
	// TABLEAUX NON TRIES
		// 500 => 0
		// 1000 => 0
		// 10000 => 0.720
		// 100000 => 72.090
	
	/***** Shakesort *****/
	//Shakesort(t,n);
	// RESULTATS
	// TABLEAUX TRIES
		// 500 => 0
		// 1000 => 0
		// 10000 => 0.210
		// 100000 => 22.630
	// TABLEAUX NON TRIES
		// 500 => 0
		// 1000 => 0
		// 10000 => 0.600
		// 100000 => 61.660
	
	/***** Shellsort *****/
	//Shellsort(t,n);
	// RESULTATS
	// TABLEAUX TRIES
		// 500 => 0
		// 1000 => 0
		// 10000 => 0
		// 100000 => 0
	// TABLEAUX NON TRIES
		// 500 => 0
		// 1000 => 0
		// 10000 => 0.1
		// 100000 => 10
	// Cet algorithme détecte si le tableau est déjà trié ou pas
	
	/***** Heapsort_1 *****/
	// tri en créant l'arbre trié au fur et à mesure du parcours du tableau
	//Heapsort_1(t,n);
	// RESULTATS
	// TABLEAUX TRIES
		// 500 => 0
		// 1000 => 0
		// 10000 => 0.540
		// 100000 => 54.250
	// TABLEAUX NON TRIES
		// 500 => 0
		// 1000 => 0
		// 10000 => 0.520
		// 100000 => 52.780
	
	/***** Heapsort_2 *****/
	// tri en partant du premier tas
	// version utilisant la fonction donnée dans l'énoncé
	//Heapsort_2(t,n);
	// RESULTATS
	// TABLEAUX TRIES
		// 500 => 0
		// 1000 => 0
		// 10000 => 0.610
		// 100000 => 59.890
	// TABLEAUX NON TRIES
		// 500 => 0
		// 1000 => 0
		// 10000 => 0.700
		// 100000 => 69.4
		
	//Heapsort_3(t,n);
	
	/***** Quicksort *****/
	Quicksort(t,0,n);
	// RESULTATS
	
	t2=clock();
	
	if(verifTableau(t,n)==0)
		printf("Tableau trié en %.3f\n",(float)(t2-t1)/CLOCKS_PER_SEC);
	else
		printf("Erreur lors du tri !\n");
	
	return 0;
}
