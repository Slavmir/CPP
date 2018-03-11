#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>
// Mersene Prime Calculator
using namespace std;

int main ()
{
	ofstream file;
    file.open("Prime.txt");
	int i,counter;
	unsigned long long int a[116609];
	for(i=0;i<116609;i++)
	{
		a[i]=0;
	}
	a[116608]++;
	for(counter=0;counter<6972593;counter++)
	{
		cout<<counter<<endl;
		for(i=0;i<116609;i++)
		{
			a[i]*=2;
		}
		for(i=116608;i>0;i--)
		{
			if(a[i]>=pow(10,18))
			{a[i-1]=a[i-1]+(floor (a[i]/pow(10,18)));a[i]=a[i]-((floor (a[i]/pow(10,18)))*pow(10,18));}
		}
	}
	for(i=0;i<116608;i++)
	{
		file<<a[i];
	}
	file<<--a[116608]<<endl;
	file.close();
	return 0;
}
