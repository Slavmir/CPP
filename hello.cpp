#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>

int main(){
	int h,i,j,n=4,m=5;
	//double a[3][4]={6.,3.,1.,10.,12.,11.,4.,17.,24.,27.,25.,46.};
	double a[4][5]={3,2,12,6,4,10,3,4,5,29,5,6,2,4,16,4,1,9,7,17};
	double d, w[n];
//	for(i=0;i<3;i++)
//	for(j=0;j<4;j++)
//	scanf("%d", &a[i][j]);
//wydruk tablicy
	for(i=0;i<n;i++)
	for(j=0;j<m;j++)
	printf("%f\n", a[i][j]);
//zerowanie wspolczynnikow
	for(i=0;i<n-1;i++){ //kolejne wspolczynniki podstawowe[i][i]
        h=i+1;
	while(h<n){ //kazda kolumne przeliczam do ostatniego wiersza przez dana kolumne
	d=a[h][i]/a[i][i];
	printf("wspolczynnik a[i][i] to :%f\n",a[i][i]);
	printf("wspolczynnik a[h][i] to :%f\n",a[h][i]);
	printf("wspolczynnik d to :%f\n",d);
	//j to kolejny wiersz
		for(j=i;j<m;j++){
		a[h][j]=a[h][j]-a[i][j]*d;
		printf("nowa zmienna to : %f\n",a[h][j]);
	}
	h++;
	}
	}
//mam obliczona macierz po przeksztalceniach
//teraz idac od konca moge obliczyc kolejne niewiadome
//ostatnia od razu
w[n-1]=a[n-1][n]/a[n-1][n-1];
printf("niewiadoma nr %d to : %f\n", n, w[n-1]);
for(i=n-2;i>=0;i--){
        w[i]=0;
//najpierw zsumuje wszystkie elementy w wierszu
    for(j=i+1;j<n;j++){
        w[i]=w[i]+a[i][j]*w[j];
        printf("sumy czesciowe to : %f\n", w[i]);
    }
//obliczam wspolczynnik
    w[i]=(a[i][n]-w[i])/a[i][i];
    printf("niewiadoma nr %d to : %f\n", i+1, w[i]);
}
	return 0;
}
