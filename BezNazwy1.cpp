#include <stdio.h>
int main()
{
	int **macierz;
	int i,j,n;
	 FILE *f = fopen("graf.txt", "r");
	if(f==NULL){
		printf("Blad otwarcia pliku");
		return 1;
	}
	fscanf(f,"%d",&n);
	int tab[n+1][n+1];
	for(i=0;i<=n;i++)for(j=0;j<=n;j++)tab[i][j]=0;
	while(1){
		fscanf(f,"%d",&i);
		fscanf(f,"%d",&j);
		tab[i][j]=1;tab[j][i]=1;
		if(feof(f))break;
	}
	fclose(f);
	for(i=1;i<=n;i++)
	{
      for(j=1;j<=n;j++)
         printf("%d",tab[i][j]);
      putchar('\n');
   }
   return (0);
}
