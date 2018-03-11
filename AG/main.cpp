#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <windows.h>

/// 1 generate population, 2 print on screen, 3 set adaptation function value for each specimen

const int n = 4;
const int m = 3;
const int psc = 25; //population scpecies count
const float cp = 0.9; //crossing prob.
const float xmin[n] = {0,0};
const float xmax[n] = {20,20};

float ksi_0F_gen(float ksiOF); //prttp for ksi floating pnt variable
void generate_1st_population(int chr[psc][n*m]); //prttp for genrating 1st chr population
void print_1st_population(int chr[psc][n*m]); //prttp print 1st pop
float f(float x[n]); //prttp adaptation function
void assess_specimens(int chr[psc][n*m], float fp[psc]); //prttp for specimen assessment


int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
    int chr[psc][n*m];
    float fp[psc];
    generate_1st_population(chr);
    std::cout << "1st population: " << std::endl;
    print_1st_population(chr);
    std::cout << std:: endl;
    std::cout << "Population specimens adaptation assessment: " << std::endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    assess_specimens(chr, fp);
    return 0;
}

float ksi_0F_gen(float ksi_0F_gen){ /** KSI floating point random variable */
    float ksi = (float)rand()/RAND_MAX;
    return ksi;
}

void generate_1st_population(int chr[psc][n*m]){ /** 1st POPULATION GENERATION */
        for (int i=0; i<psc; i++){
            for (int j=0; j<n*m; j++){
                chr[i][j] = rand()%2;
            }
        }
}

void print_1st_population(int chr[psc][n*m]){ /** PRINT POPULATION */
        for (int i=0;i<psc; i++){
                std::cout << "Specimen:" << i+1 << " : ";
            for (int j=0; j<n*m; j++){
                std::cout << chr[i][j];
            }
            std::cout << std::endl;
        }
}

float f(float x[n]){ /** ADAPTATION FUNCTION*/
    float s;
    for (int i=0; i<n; i++){
        s = s + x[i] + sin(x[i]) * sin(x[i]);
    }
    return s;
}

void assess_specimens(int chr[psc][n*m], float fp[psc]){ /** ASSESS SPECIMENS */
        int gp, gl;
        float wd, p2;
        float x[n];

        for (int j=0; j<psc; j++){
            for (int i=0; i<n; i++){
                p2 = 1;
                wd = 0;
                gp = (i+1) * m - 1;
                gl = i * m;
                for (int k=gp; k>= gl; k--){
                    wd = wd + chr[i][j] * p2;
                    p2 = 2 * p2;
                }
                x[i] = xmin[i] + (xmax[1] - xmin[i]) * wd/(p2 - 1);
            }
            fp[j] = f(x);
            std::cout << "Chromosome: " << j+1 << "   " << fp[j] << "\n";
        }
}
