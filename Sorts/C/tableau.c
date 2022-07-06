/* GENERATION D UN TABLEAU DESORDONNE */
void generationTableauDesordonne(int t[], int n)
{
	int i;
	for(i=0;i<n;i++)
		t[i]=rand();
}

/* GENERATION D UN TABLEAU ORDONNE */
void generationTableauOrdonne(int t[], int n)
{
	int i;
	for(i=0;i<n;i++)
		t[i]=i;
}

/* AFFICHAGE D UN TABLEAU */
/*void affichageTableau(int t[], int n)
{
	int i;
	for(i=0;i<n;i++)
		printf("%d ",t[i]);
	
	printf("\n");
}

/* VERIFICATION SI TABLEAU TRIE */
// renvoie 1 si il y a une erreur
// renvoie 0 si le tableau est bien trié

int verifTableau(int t[], int n)
{
	int i;
		
	for(i=0;i<n-1;i++)
	{
		if(t[i]>t[i+1])
		{
			return 1;
		}
	}
			
	return 0;
}
