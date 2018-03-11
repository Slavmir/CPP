#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>

int main(){
	int i,j,k,n=3,m=6;
	float r[3][6]={3.,4.,5.,1.,0.,0.,2.,5.,2.,0.,1.,0.,4.,6.,7.,0.,0.,1.};
	float c;

	for(i=0;i<n;i++){
	printf("\n");
        for(j=0;j<m;j++)
            printf(" %f", r[i][j]);
        }
	//
	for(i=0;i<n;i++){
		c=r[i][i];
		for(k=i;k<=n+i;k++)
			r[i][k]=r[i][k]/c;
		//
		for(j=0;j<i;j++){
			c=r[j][i];
			for(k=i;k<=n+i;k++)
				r[j][k]=r[j][k]-r[i][k]*c;
		}
		//
		for(j=i+1;j<n;j++){
			c=r[j][i];
			for(k=i;k<=n+i;k++)
				r[j][k]=r[j][k]-r[i][k]*c;
		}
	}
	printf("\n");
	printf("po transformacji\n");
	for(i=0;i<n;i++){
	printf("\n");
	for(j=0;j<m;j++)
	printf(" %f", r[i][j]);
	}
	return 0;
}
