#include <stdio.h>
#include <stdlib.h>

int main()
{
    /** 1
    printf("(1) - F1 - min w tablicy: \n");
    minimumTablicy();
    */
    /** 2
    1 - tablica 2 - wprowadz liczby to tab 3 - oblicz srednia 4 - wypisz wieksze od sredniej ... (niedziala)
    printf("(2) - F2 - min w sredniej: \n");
    wyzsze_od_AVG();
    */
    /** 3
    1- tablica 2-wprowadz napis 16 literek 3-sprawdz dlugosc
    napis_sprawdz_czy_sa_liczby();
    */
    ///pesel_sum_kontrl(); do dupy
    /** 4 suma_kontr */
    ///pesel_sum_kontrl(); do dupy dziala
    char psl;
    printf("Podaj napis: \n");
    gets(psl);
    printf("%s\n", psl);
    return 0;
}

void minimumTablicy(){
    //zadeklarowana tablica n elementow, okreslosne minimum, znajdz i wyswietl minimum
    int j,i,min;
    int t[10] = {4,7,-9,-3,-7,6,9};
    min=t[0];

    for (i=0;i<10;i++)
        if(t[i]<min)
        min=t[i];

    printf("Min=%d", min);
}

void wyzsze_od_AVG(){
    int t[10], i=0, suma=0;
    float sr;
    for (i=0; i<10; i++){
        printf("t[%d]= ", i);
        scanf("%d", &t[i]);
        suma += t[i];
    }
    sr = suma/10.0;
    for (i=0;i<10;i++)
            if(t[i]>sr)
            printf("%d",t[i]);
}

void napis_sprawdz_czy_sa_liczby(){
    char napis[17];
    int dl=0, i;
    printf("Podaj napis: ");
    gets(napis);
    while(napis[dl] != 0)
        dl++;
    if (dl!= 16){
        printf("Zla dlugosc!\n");
        return 1;
    }
    for (i=0; i<dl; i++)
        if (napis[i] < '0' || napis[i]<9){
            printf("Zle znaki!\n");
            return 2;
        }
        return (0);
}

/** DO KITU
void pesel_sum_kontrl(){
        int pesel[12];
        int dl, i, s;
        printf("Podaj pesel: \n");
        gets(pesel);
        dl=0;
        while(pesel[dl]=0) dl++;
        if (dl != 12){
            printf("Zla dlugosc!");
            return 1;
        }
        for (i=0; i<dl; i++)
            if (pesel[i] < '0' || pesel[i] > 9) printf("Zly znak!\n");
        return 2;
}
*/
void pesel_sum_kontrl(){
    int pesel[11];
    int i,s, dl;
    printf("Podaj pesel: \n");
    gets(pesel);
    dl=0;
    while(pesel[dl]=0)
        dl++;
        if (dl != 11){
            printf("Zla dlugosc!\n");
            return 1;
        }
    for (i=0;i<dl;i++)
        if (pesel[i]<'0' || pesel[i] > '9'){
            printf("Zly znak\n");
            s = 9*(pesel[0]-'0')+7*(pesel[1]-'0')+6*(pesel[2]-'0')+5*(pesel[3]-'0')+4*(pesel[4]-'0')+3*(pesel[5]-'0')+2*(pesel[6]-'0')+1*(pesel[7]-'0');
            return 2;
        }
        if (s%10 != (pesel[10] - '0')){
            printf("Blad sumy kontrolnej\n");
            return 3;
        }
        return (0);
}
