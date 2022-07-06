/* FONCTIONS DE TRIS */

/* TRI PAR INSERTION */

void Insertion (int tab[], int ntab)
{
	int i,j,k,tmp;
	for(k=1;k<ntab;k++)
		{
			tmp=tab[k]; // valeur à déplacer
			j=k-1;
			while(j>=0 && tmp<tab[j])
			{
				tab[j+1]=tab[j]; // deplacement des valeurs supérieurs à x vers la droite
				j--;
			}
	 	
			tab[j+1]=tmp; // l'indice de la valeur à insérer est j+1
	 }
}

/* TRI PAR SELECTION */

void Selection (int tab[], int ntab)
{
	int i,j,k,max,rangmax,tmp;

	k=ntab;

	while(k>0)
	{
		max=tab[0];
		rangmax=0;
	
		for(j=0;j<k;j++)
		{
			if(tab[j]>max)
			{
				max=tab[j];
				rangmax=j;
			}
		}
	
		tmp=tab[k-1];
		tab[k-1]=max;
		tab[rangmax]=tmp;
	
		k--;
	}
}

/* TRI PAR ECHANGE */

void Echange (int tab[], int ntab)
{
	int k,tmp,i;

	k=ntab-1;

	while(k>0)
	{
		for(i=0;i<k;i++)
		{
			if(tab[i]>tab[i+1])
			{
				tmp=tab[i+1];
				tab[i+1]=tab[i];
				tab[i]=tmp;
			}
		}

		k--;
	}
}

/* SHAKESORT */

void Shakesort(int tab[], int ntab)
{
	int g,d,i,tmp;

	g=0;
	d=ntab-1;

	while(d>g)
	{
		for(i=g;i<d;i++)
		{
			if(tab[i]>tab[i+1])
			{
				tmp=tab[i+1];
				tab[i+1]=tab[i];
				tab[i]=tmp;
			}
		}
	
		d--;

		for(i=d;i>=g;i--)
		{
			if(tab[i]<tab[i-1])
			{
				tmp=tab[i];
				tab[i]=tab[i-1];
				tab[i-1]=tmp;
			}
		}
	
		g++;
	}
}

/* SHELL SORT */

void Shellsort(int tab[], int ntab)
{
	int p,i,j,tmp;

	// calcul du pas
	for(p=1;p*3+1<ntab;p=p*3+1)
		;

	while(p>=1)
	{
		for(i=p;i<ntab;i+=p)
		{
			j=i-p;
			tmp=tab[i];

			while(j>=0 && tmp<tab[j])
			{
				tab[j+p]=tab[j];
				j-=p;
			}
	 
			tab[j+p]=tmp;
		}

		p=(p-1)/3;
	}
}

/* HEAPSORT */
//Première version

void Heapsort_1(int tab[], int ntab)
{
	int i,j,k,tmp;
	i=0;
	while(i<ntab/2)
	{	
		if((2*i+1)<ntab && tab[i]<tab[2*i+1])
		{
			tmp=tab[i];
			tab[i]=tab[2*i+1];
			tab[2*i+1]=tmp;
			
			j=(i-1)/2;
			k=i;
		
			while(j>=0)
			{
				if(tab[k]>tab[j])
				{
					tmp=tab[k];
					tab[k]=tab[j];
					tab[j]=tmp;
				}
				k--;
				j=(k-1)/2;
			}
		}
		
		if(2*(i+1)<ntab && tab[i]<tab[2*(i+1)])
		{
			tmp=tab[i];
			tab[i]=tab[2*(i+1)];
			tab[2*(i+1)]=tmp;
			
			j=(i/2)-1;
			k=i;
		
			while(j>=0)
			{
				if(tab[k]>tab[j])
				{
					tmp=tab[k];
					tab[k]=tab[j];
					tab[j]=tmp;
				}
				k--;
				j=(k/2)-1;
			}
		}		
		i++;
	}
	
	j=ntab;
	while(j>0)
	{
		// deplacement du maximum en fin de tableau
		tmp=tab[j-1];
		tab[j-1]=tab[0];
		tab[0]=tmp;
		j--;
	
		i=0;
	
		while(i<j/2)
		{
			if((2*i+1)<j && tab[2*i+1]>tab[2*(i+1)])
			{
				if(tab[i]<tab[2*i+1])
				{
					tmp=tab[i];
					tab[i]=tab[2*i+1];
					tab[2*i+1]=tmp;
				}
			}
			else
			{
				if(2*(i+1)<j && tab[i]<tab[2*(i+1)])
				{
					tmp=tab[i];
					tab[i]=tab[2*(i+1)];
					tab[2*(i+1)]=tmp;
				}
			}
			i++;
		}
			
	}
	
	if(tab[0]>tab[1])
	{
		tmp=tab[0];
		tab[0]=tab[1];
		tab[1]=tmp;
	}
}

// Seconde version
void placer(int g, int d, int *T)
{
	int i,j,x,place_trouvee;
	x=T[g];
	i=g;
	j=2*g+1;
	place_trouvee=0;

	while((j<=d) && !(place_trouvee))
	{
		if(j<d)
			if (T[j+1]>T[j]) j++;
		
		if(x>=T[j])
			place_trouvee=1;

		else
		{
			T[i]=T[j];
			i=j;
			j=2*i+1;
		}
	}

	T[i]=x;
}

void Heapsort_2(int tab[], int ntab)
{
	int d,g,tmp;
	
	g=ntab/2;
	d=ntab-1;

	while(d>0)
	{
		while(g>0)
		{
			placer(g-1,d,tab);
			g--;
			
		}

		tmp=tab[0];
		tab[0]=tab[d];
		tab[d]=tmp;
	
		d--;
		g=(d+1)/2;
	}
}

void Heapsort_3(int tab[], int ntab)
{
	int d,g,tmp;
	g=ntab/2;
	d=ntab-1;
	
	while(g>0)
	{
		placer(g-1,d,tab);
		g--;
	}
	
	while(d>0)
	{
		tmp=tab[0];
		tab[0]=tab[d];
		tab[d]=tmp;
		d--;
		placer(0,d,tab);
	}
}

/* QUICKSORT */
// partitionnement du tableau
int partition(int t[], int gauche, int droite)
{
	int i,j,k,l,p,tmp;
	
	i=gauche;
	j=droite-1;
	k=(gauche+droite)/2;
	p=t[k];
	
	while(i<j)
	{
		
		while((i<k)&&(t[i]<=p)) i++;
		while((j>k)&&(t[j]>=p)) j--;

		if(i<k && j>k){
			tmp=t[i];
			t[i]=t[j];
			t[j]=tmp;
		}

		if((j==k)&&(i<k))
		{
			//decalage du tableau vers la gauche
			tmp=t[i];
			for(l=i;l<k;l++)
				t[l]=t[l+1];
			t[k]=tmp;
			k--;
			p=t[k];
			j--;
			//solution alternative
			/*tmp=t[i];
			t[i]=t[k];
			t[k]=tmp;
			k=i;
			j=droite-1;
			p=t[k];*/
		}

		if((i==k)&&(j>k))
		{
			//decalage du tableau vers la droite
			tmp=t[j];
			for(l=j;l>k;l--)
				if(l>0)
					t[l]=t[l-1];
			t[k]=tmp;
			k++;
			p=t[k];
			i++;
			//solution alternative
			/*tmp=t[j];
			t[j]=t[k];
			t[k]=tmp;
			k=j;
			i=gauche;
			p=t[k];*/
		}
	}
	return k;
}

void Quicksort(int t[],int debut, int fin)
{

	int k;
	k=partition(t,debut,fin);
	if(debut<fin)
	{
		if(debut+1<k) Quicksort(t,debut,k+1);
		if(k<fin-1) Quicksort(t,k+1,fin);
	}

}
