#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdint.h>

int main()
{
    int i,j,k,n=3,m=6;
    float r[3][6] = {3.0,4.0,5.0,1.0,0.0,0.0,2.0,5.0,2.0,0.0,1.0,0.0,4.0,6.0,7.0,0.0,0.0,1.0};
    float c;
    for (i=0; i<n; i++){
            printf("\n");
        for (j=0; j<m; j++)
            printf(" %.3f",r[i][j]);
    }
    //
    for (i=0; i<n; i++){
        c=r[i][i];
        for (k=i; k<=n+i; k++)
            r[i][k] = r[i][k]/c;
        //
    for (j=0; j<i; j++){
        c = r[j][i];
        for (k=i; k<=n+i; k++)
            r[j][k] = r[j][k] - r[i][k]*c;
    }
    //
    for (j=i+1; j<n; j++){
        c=r[j][i];
            for(k=i;k<=n+i;k++)
                r[j][k]=r[j][k] - r[i][k] * c;
        }
    }
    printf("\n");
    printf("Po transformacji: \n");
    for (i=0; i<n; i++){
        printf("\n");
            for (j=0; j<m; j++)
                printf(" %.3f", r[i][j]);
    }
    return 0;
}
