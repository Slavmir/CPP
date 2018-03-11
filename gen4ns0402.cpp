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
// bz - liczba iteracji bez zmian (bez poprawy najlepszego rozwiazania)

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>


#define ksi01() (float)rand()/RAND_MAX
#define n 2
#define m 24
#define lop 100
#define pm 0.07
#define pk 0.95
#define bz 40
#define lpp 1000


float xmin[n]={0,0};
float xmax[n]={20,20};

float nfp,nx[n];
int rbz;



float f(float x[n])
{
	float s=0;
	int i;
	// x=17.30764054	f1=17.29320809	f2=34.58641619	f3=51.87962428

	for(i=0;i<n;i++) s=s+x[i]*sin(x[i])*sin(x[i]);
	return s;
}

void inicjuj_najlepszego(void)
{
	int i;
	for(i=0;i<n;i++) nx[i]=xmin[i];
	nfp=f(nx);
}

void generacja_pierwszej_populacji(int chr[lop][n*m])
{
	int i,j;
	for(i=0;i<lop;i++)
		for(j=0;j<n*m;j++)
			chr[i][j]=rand()%2;
}

void drukuj(int chr[lop][n*m])
{
	int i,j;
	for(i=0;i<lop;i++){
		for(j=0;j<n*m;j++)
			printf("%d",chr[i][j]);
		printf("\n");
	}
	printf("\n");
}

void ocena_osobnikow_populacji(int chr[lop][m*n], float fp[lop])
{
	int i,j,k,gp,gl;
	float wd,p2;
	float x[n],pnfp;

	pnfp=nfp;
	for(j=0;j<lop;j++){
		for(i=0;i<n;i++){
			p2=1;
			wd=0;
			gp=(i+1)*m-1;
			gl=i*m;
			for(k=gp;k>=gl;k--){
				wd=wd+chr[j][k]*p2;
				p2=2*p2;
			}
			x[i]=xmin[i]+(xmax[i]-xmin[i])*wd/(p2-1);
		}

		fp[j]=f(x);
		if(fp[j]>nfp){
			nfp=fp[j];
			for(i=0;i<n;i++) nx[i]=x[i];
		}
	}
	if(pnfp==nfp) rbz++;
	else rbz=0;

}

void selekcja_osobnikow_rodzicielskich(float fp[lop], int twr[lop])
{
	int i,i1,i2;
	for(i=0;i<lop;i++){
		i1=rand()%lop;
		i2=rand()%lop;
		if(fp[i1]>fp[i2]) 	twr[i]=i1;
		else				twr[i]=i2;
	}
}

void krzyzowanie(int chr[lop][n*m], int twr[lop], int chp[lop][n*m])
{
	int i,j,i1,i2,r1,r2,p1,p2,l,pc;
	l=lop;
	for(i=0;i<lop/2;i++){
		i1=rand()%l; r1=twr[i1]; l--; twr[i1]=twr[l];
		i2=rand()%l; r2=twr[i2]; l--; twr[i2]=twr[l];
		p1=2*i; p2=p1+1;
		if(ksi01()<=pk){
			pc=rand()%(n*m-1)+1;
			for(j=0;j<pc;j++){
				chp[p1][j]=chr[r1][j];
				chp[p2][j]=chr[r2][j];
			}
			for(j=pc;j<n*m;j++){
				chp[p1][j]=chr[r2][j];
				chp[p2][j]=chr[r1][j];
			}
		}
		else{
			for(j=0;j<n*m;j++){
				chp[p1][j]=chr[r1][j];
				chp[p2][j]=chr[r2][j];
			}
		}
	}
}


void mutacja(int chp[lop][n*m])
{
	int i,j;
	for(i=0;i<lop;i++){
		for(j=0;j<n*m;j++){
			if(ksi01()<=pm){
				if(chp[i][j]==1) 	chp[i][j]=0;
				else				chp[i][j]=1;
			}
		}
	}
}

void sukcesja(int chp[lop][n*m],int chr[lop][n*m])
{
	int i,j;
	for(i=0;i<lop;i++){
		for(j=0;j<n*m;j++){
			chr[i][j]=chp[i][j];
		}
	}
}

void zwrocenie_najlepszego_osobnika(void)
{
	int i;
	printf("%f\n",nfp);
	for(i=0;i<n;i++) printf("%f\t",nx[i]);
	printf("\n");
}

main()
{
	int chr[lop][n*m],twr[lop],chp[lop][n*m];
	float fp[lop],tnfp[lpp], maksimum, minimum, srednia=0, stddev, temp[lpp], suma_temp;
	int l,i;

	srand(time(NULL));

	for(i=0;i<lpp;i++){
		rbz=0;
		inicjuj_najlepszego();
		generacja_pierwszej_populacji(chr);
		ocena_osobnikow_populacji(chr,fp);
		l=0;
		do{
			l++;
			selekcja_osobnikow_rodzicielskich(fp,twr);
			krzyzowanie(chr,twr,chp);
			mutacja(chp);
			sukcesja(chp,chr);
			ocena_osobnikow_populacji(chr,fp);
		}while(bz>rbz);
		tnfp[i]=nfp;
	}
    //zwrocenie_najlepszego_osobnika();
    //printf("Iteracji: %d", l);

	// znajdz max, min, avg, stddev tablicy tnfp
	for(i=0;i<lpp;i++)
    {
        if(maksimum<tnfp[i]) maksimum=tnfp[i];
    }
    printf("Max:%f\n", maksimum);
    minimum=maksimum;
    for(i=0;i<lpp;i++)
    {
        if(minimum>tnfp[i]) minimum=tnfp[i];
    }
    printf("Min:%f\n", minimum);
    for(i=0;i<lpp;i++)
    {
        srednia=srednia+tnfp[i];
    }
    srednia=srednia/lpp;
    printf("Avg:%f\n", srednia);
    //stddev
/*
    for(i=0;i<lpp;i++)
    {
        temp[i]=tnfp[i]-srednia;
        temp[i]=temp[i]*temp[i];
    }
    suma_temp=0;
    for(i=0;i<lpp;i++)
    {
        suma_temp=suma_temp+temp[i];
    }
    float result = sqrt (suma_temp/lpp);
    printf ("stddev= %f\n", result );
    */
	return 0;
}
