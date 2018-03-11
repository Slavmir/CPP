#include <iostream>
#include <iomanip>
#include <cassert>
#include <cstdlib>
#include <ctime>
#include <cmath>

const double eps = 1e-12; //stala porownacza bliska zeru 10^-12

bool gauss(int n, double **AB, double *X); //prttp

int main()
{

        std::cout << std::setprecision(9);
        double **AB, *X;
        int n;
        std::cout << "Podaj liczbe niewiadomych: ";
        std:: cin >> n;
        std::cout << std::endl;
        //Tworzenie macierzy AB i X z op. new
        AB = new double * [n];
        X = new double [n];
        for (int i=0; i<n; i++)
            AB[i] = new double [n+1];
        //wypelniamy macierz AB[i][j] liczbami
        for (int i=0; i<n; i++)
            for (int j=0; j<=n; j++)
                AB[i][j] = (unsigned)rand()%49 +1;
        /// wydruk - test
        /** Tabela*/
        for (int i=0; i<n; i++){
            for (int j=0; j<=n; j++){
                std::cout << AB[i][j] << " ";
            }
            std::cout << std::endl;
        }
        /** Koniec testu */
        ///--------------
        std::cout << std::endl;
        if(gauss(n,AB,X)){
            for (int i=0; i<n; i++)
                std::cout << "x" << i+1 << " = " << std::setw(9) << X[i] << std::endl;
        }
        else{
            std::cout << std::endl;
            std::cout << "Dzielnik zero!" << std::endl;
        }
        for (int i=0 ;i<n; i++)
            delete AB[i];

        delete [] AB;
        delete [] X;

        return (0);
}

bool gauss(int n, double **AB, double *X){
        double m, s;

        // eliminacja wspolczynnikow
        for (int i=0; i<n-1; i++){
            for (int j=i+1; j<n; j++){
                if(fabs(AB[i][i]) < eps)
                    return false;
                m = -AB[j][i] / AB[i][i];
                for (int k=i+1; k<=n; k++)
                    AB[j][k] += m * AB[i][k];
            }
        }
        // Wyliczanie niewiadomych
        for (int i=n-1; i>=0; i--){
            s = AB[i][n];
            for (int j=n-1; j>= i+1; j--)
                s -= AB[i][j] * X[j];
            if (fabs(AB[i][i]) < eps)
                return false;
            X[i] = s/AB[i][i];
        }
        return true;
}
