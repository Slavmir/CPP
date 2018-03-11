#include <iostream>
#include <cassert>
#include <ctime>
#include <cstdlib>

int mx_ops();

int main()
{
        mx_ops();
        return (0);
}

int mx_ops()
{
        int i=0, j=0;
        constexpr int lo=25, n=2, m=4;
        int chr[lo][n*m];

        for (i=0; i<lo; i++)
            for (j=0; j<n*m; j++)
            chr[i][j] = rand()%2;

        for (i=0; i<lo; i++){
            for (j=0; j<n*m; j++){
                std::cout << chr[i][j];
            }
        std::cout << std::endl;
        }
        return chr[lo][n*m];
}
