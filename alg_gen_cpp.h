#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

// n - liczba atrybutow rozwiazania
// x[n] - jednowymiarowa tablica atrybutow rozwiazania (rozwiazanie)
// f(x) - funkcja przystosowania
// m - liczba genow wykorzystana do zakodowania jednego atrybutu rozwiazania
// xmin[n] - jednowymiarowa tablica minimalnych wartosci atrybutow rozwiazania
// xmax[n] - jednowymiarowa tablica maksymalnych wartosci atrybutow rozwiazania
// lop - liczba osobnikow populacji
// chr[lop][n*m] - dwuwymiarowa tablica chromosomow rodzicielskich
// chp[lop][n*m] - dwuwymiarowa tablica chromosomow potomnch
// twr[lop] - tablica wskaznikow na rodzicow
// pm - prawdopodobienstwo mtacji
// pk - prawdopodobienstwo krzyzowania

const int n = 2;
const int m = 24;
const int lop = 10;
const float pk = 0.9;
/**const float pm = 0.1;*/

float xmin[n] = {0,0};
float xmax[n] = {20, 20};
#define ksi01() (float)rand()/RAND_MAX

float f(float x[n]); //prototyp funkcja przystosowania
void gen_pierwsza_populacje(int chr[lop][n*m]); //prttp generuj 1 generacje
void drukuj_1sza_pop(int chr[lop][n*m]); //prttp
void drukuj_populacje_potomna(int chp[lop][n*m]); //prttp
void ocen_osobnikow_populacji(int chr[lop][n*m], float fp[lop]); //prototyp ocena osbnikow populacji
void selekcja_osobnikow_na_rodzicow(float fp[lop], int twr[lop]); //prototyp selekcja
void krzyzujOsobniki(int chr[lop][n*m], int twr[lop], int chp[lop][n*m]); //prttp krzyzowanie
//void mutacjaOsbnikow(int chp[lop]); //mutacja
//void sukcesja(int chp[lop][n*m], int chr[lop][n*m]); //prttp sukcesja

int main(int argc, char ** argv)
{
            int chr[lop][n*m],chp[lop][n*m];
            int twr[lop];
            float fp[lop];
            srand(time(NULL));
            cout << "Rodzice: " << endl;
            gen_pierwsza_populacje(chr);
            drukuj_1sza_pop(chr);
            cout << endl;
            ocen_osobnikow_populacji(chr, fp);
            selekcja_osobnikow_na_rodzicow(fp, twr);
            krzyzujOsobniki(chr, twr, chp);
            cout << "Potomne: " << endl;
            drukuj_populacje_potomna(chp);
            cout << endl;
            return(0);

}

float f(float x[n]){
        float s = 0;
        for (int i=0; i<n; i++)
            s = s + x[i] * sin(x[i]) * sin(x[i]);
        return s;
}

void gen_pierwsza_populacje(int chr[lop][n*m]){
        for (int i=0; i<lop; i++){
            for (int j=0; j<n*m; j++){
                chr[i][j] = rand()%2;
            }
        }
}

void drukuj_1sza_pop(int chr[lop][n*m]){
        for (int i=0; i<lop; i++){
            for (int j =0; j<n*m; j++){
                /**if (j>0 && j%n==0)
                    cout << " ";*/
                cout << chr[i][j];
            }
            cout << endl;
        }
}

void ocen_osobnikow_populacji(int chr[lop][n*m], float fp[lop]){
    int gp, gl;
    float wd, p2;
    float x[n];

    for (int j=0; j<lop; j++){
        for (int i=0; i<n; i++){
            p2 = 1;
            wd = 0;
            gp = (i+1) * m -1;
            gl = i * m;
            for (int k=gp; k>=gl; k--){
                wd = wd + chr[j][k] * p2;
                p2 = 2 * p2;
            }
            x[i] = xmin[i] + (xmax[1] - xmin[i]) * wd/(p2 -1);
        }
        fp[j] = f(x);
    }
}

void selekcja_osobnikow_na_rodzicow(float fp[lop], int twr[lop]){
        int i1, i2;
        for (int i=0; i<lop; i++){
            i1 = rand()%lop;
            i2 = rand()%lop;
        if (fp[i1]>fp[i2])
            twr[i] = i1;
        else
            twr[i] = i2;
        }
}

void krzyzujOsobniki(int chr[lop][n*m], int twr[lop], int chp[lop][n*m]){
        int i1, i2, l = lop, p1, p2, r1, r2, pc;
        for (int i=0; i<lop/2; i++){
            i1 = rand()%1;
            r1 = twr[i1];
            twr[i1] = twr[l-1];
            l--;
            i2 = rand()%1;
            r2 = twr[i2];
            twr[i2] = twr[l-1];
            l--;
            p1 = 2 * i;
            p2 = 2 * i + 1;

            if (ksi01()< pk){
                pc = rand()%(n*m-1);
                for (int k=0; k<=pc; k++){
                    chp[p1][k]=chr[r1][k];
                    chp[p2][k]=chr[r2][k];
                }
                for (int k=pc+1; k<n*m; k++){
                    chp[p1][k] = chr[r2][k];
                    chp[p2][k] = chr[r1][k];
                }
            }
            else{
                for (int k=0; k<=n*m; k++){
                    chp[p1][k] = chr[r1][k];
                    chp[p2][k] = chp[r2][k];
                }
            }
        }
}

void drukuj_populacje_potomna(int chp[lop][n*m]){
    for (int i=0; i<lop; i++){
        for (int j=0; j<n*m; j++){
            /**if(j>0 && j%n==0){
                cout << " ";*/
                cout << chp[i][j];
            }
            cout << endl;
        }
    }


/**
void mutacjaOsbnikow(int chp[lop][n*m]){
        for (int i=0;i<lop; i++){
        for (int j =0; j<n*m; j++){
        if(ksi01()<=pm){
            if(chp[i][j]==1)
                chp[i][j]=0;
            else
                chp[i][j] = 1;
            }
        }
    }
}

void sukcesja(int chp[lop][n*m], int chr[lop][n*m]){
        for (int i=0;i<lop; i++){
            for (int j=0; j<n*m; j++){
                chr[i][j] = chp[i][j];
        }
    }
}
*/
