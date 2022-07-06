#include <stdio.h>
#define N 10

void permutation(int *el1, int *el2)
{
	int *x;
	x=el1;
	el1=el2;
	el2=x;
}

int partition(int t[], int gauche, int droite)
{
	int i,j,k,l,p,tmp;
	
	i=gauche;
	j=droite-1;
	k=(gauche+droite)/2;
	p=t[k];
	
	while(i<j)
	{
		//while(t[k]==t[k+1]) k++;
		
		printf("pivot:%d, indice du pivot: %d\n",p,k);
		
		while((i<k)&&(t[i]<=p)) i++;
		while((j>k)&&(t[j]>=p)) j--;
		
		//printf("p=%d,i=%d,j=%d,k=%d\n",p,i,j,k);

		if(i<k && j>k){
			//permutation(&t[i],&t[j]);
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
			//printf("k=%d\n",k);
			p=t[k];
			j--;
		}

		if((i==k)&&(j>k))
		{
			printf("decalage vers la doite\n");
			//decalage du tableau vers la droite
			tmp=t[j];
			for(l=j;l>k;l--)
				if(l>0)
					t[l]=t[l-1];
			t[k]=tmp;
			k++;
			p=t[k];
			i++;
			printf("pivot:%d, indice:%d\n",p,k);
		}
		
		for(l=gauche;l<droite;l++)
			printf("%d ",t[l]);
		printf("\n");
	}
	printf("return %d\n",k);
	return k;
}

void quicksort(int t[],int debut, int fin)
{

	//printf("debut=%d, fin=%d, k=%d\n",debut,fin,k);
	int k;

	k=partition(t,debut,fin);
		
	if(debut<fin)
	{
	if(debut+1<k) quicksort(t,debut,k+1);
	if(k<fin-1) quicksort(t,k+1,fin);
	}

}

int main()
{
	int t[N];
	int n=N,i;
	
	srand(time(NULL));
	
	for(i=0;i<n;i++)
		t[i]=rand()%10;
	
	//permutation(&t[0],&t[1]);
	
	for(i=0;i<n;i++)
		printf("%d ",t[i]);
	printf("\n");
	
	quicksort(t,0,n);
	
	//printf("%d\n",partition(t,0,n));

	for(i=0;i<n;i++)
		printf("%d ",t[i]);
	printf("\n");
	
	return 0;
}
