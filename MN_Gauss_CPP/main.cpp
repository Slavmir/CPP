#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstdint>

void mx_Gauss(); //prototype

int main()
{
    mx_Gauss();
    return 0;
}

void mx_Gauss(){
std::cout.precision(5);
std::cout.setf(std::ios::fixed, std::ios::floatfield);
int n=3,m=6, i, j, k;
float arr0[n][m] = {3.,4.,5.,1.,0.,0.,2.,5.,2.,0.,1.,0.,4.,6.,7.,0.,0.,1.};
float c;
/**WYDRUK MACIERZY */
for(i=0; i<n; i++){
    for (j=0; j<m; j++){
        std::cout << arr0[i][j] << " ";
    }
    std::cout << std::endl;
}
//
for (i=0; i<n; i++){
    c = arr0[i][i];
    for (k=i; k<=n+i; k++)
        arr0[i][k] = arr0[i][k]/c;
//
    for (j=0; j<i; j++){
        c = arr0[j][i];
        for (k=i; k<=n+i; k++)
            arr0[j][k] = arr0[j][k] - arr0[i][k] * c;
            }
//
    for (j=i+1; j<n; j++){
        c = arr0[j][i];
        for (k=i; k<=n+i; k++)
            arr0[j][k] = arr0[j][k] - arr0[i][k] * c;
    }
}
std::cout << "------------------" << std::endl;
std::cout << "Po transformacji: " << std::endl;
for (i=0; i<n; i++){
    for (j=0; j<m; j++){
        std::cout << arr0[i][j] << " ";
    }
    std::cout << std::endl;
    }
}
