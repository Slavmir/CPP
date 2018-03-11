#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  float **A,**B,**C,m,n,p,i,j,k,s;

  // odczytujemy wymiary macierzy

  cin >> m >> n >> p;

  // tworzymy macierze o odpowiednich rozmiarach

  A = new float * [m];
  B = new float * [n];
  C = new float * [m];

  for(i = 0; i < m; i++)
  {
    A[i] = new float[n];
    C[i] = new float[p];
  }

  for(i = 0; i < n; i++) B[i] = new float[p];

  // odczytujemy dane dla macierzy A

  for(i = 0; i < m; i++)
    for(j = 0; j < n; j ++) cin >> A[i][j];

  // odczytujemy dane dla macierzy B

  for(i = 0; i < n; i++)
    for(j = 0; j < p; j++) cin >> B[i][j];

  cout << endl;

  // mnożymy macierz A przez B i wynik umieszczamy w C

  for(i = 0; i < m; i++)
    for(j = 0; j < p; j++)
    {
      s = 0;
      for(k = 0; k < n; k++) s += A[i][k] * B[k][j];
      C[i][j] = s;
    }

  // wyprowadzamy wynik mnożenia w C

  cout <<  "C = A x B:\n";

  for(i = 0; i < m; i++)
  {
    for(j = 0; j < p; j++) cout << setw(6) << C[i][j];
    cout << endl;
  }

  // zwalniamy pamięć zajętą przez macierze

  for(i = 0; i < m; i++)
  {
    delete [] A[i];
    delete [] C[i];
  }

  for(i = 0; i < n; i++) delete [] B[i];
  delete [] A;
  delete [] B;
  delete [] C;

  return 0;
}
