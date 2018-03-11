#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void liczba_dzielnik(); //prttp
void liczby_i_pole_3kata(); //prttp

int main()
{
    int wybor;
    printf("1 - Pole trojkata [1]\n");
    printf("2 - Dzielnik liczby [2]\n");
    scanf(" %d", &wybor);
    switch(wybor)
    {
    case 1:
        liczby_i_pole_3kata();
        break;
    case 2:
        liczba_dzielnik();
        break;
    default:
        printf("Zly wybor!\nKoniec!\n");
        break;
    }
    return 0;
}
void liczba_dzielnik(){
        int i, licz=0, dzielniki;
    printf("Podaj liczbe: \n");
    scanf (" %d", &licz);
    printf("Podales %d \n", licz);
    for (i=1; i<=licz; i++){
        if (licz % i == 0){
            printf("Dzielniki liczby %d to: %d\n", licz, i);
        }
    }
}

void liczby_i_pole_3kata(){
    //3,4,5
    int n, i, suma;
    printf("Podaj ilosc elementow w tablicy: \n");
    scanf(" %d", &n);
    if(n < 3 || n > 3){
        printf("Zla ilosc liczb! Trojkata z tego nie budiet!\n");
        return 1;
    }
    int tablica[n];

    for (i=0; i<n; i++)
        scanf(" %d", &tablica[i]);
    for (i=0; i<n; i++)
        printf("%d\n", tablica[i]);

    suma=0;
    for (i=0;i<n;i++){
        suma+= tablica[i];
    }

    printf ("\nSuma= %d\n", suma);
    float p = 0.5 * (suma);
    printf("p = %f", p);

    float podPrw = p*(p-tablica[0])*(p-tablica[1])*(p-tablica[2]);
    float PoleTrojKoata = sqrt(podPrw);
    printf("\nPole Trojkata = %f", PoleTrojKoata);
}
