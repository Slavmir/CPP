#include <iostream>
#include <cmath>
typedef unsigned long long ULL;

void ifPrime(ULL var); //prttp

int main()
{
        ULL p1, p2;
        p1 = 121098217;
        p2 = 13;
        ifPrime(p1);
        std::cout << std::endl;
        //ifPrime(p2);
        return (0);
}

void ifPrime(ULL var){
    ULL i = 5;
    int firstPrime = 2;
    const int long long limes = sqrt(var);
        if(var == 1){
            std::cout << "1 is hard to classify." << std::endl;
            return;
            }
        if(var == 2){
            std::cout << "2 is prime." << std::endl;
            return;
        }
        if(var == 3){
            std::cout << "3 is prime." << std::endl;
            return;
        }
        //
        if(var%2 == 0){
            std::cout << var << " is N O T a prime number!" << std::endl;
            return;
        }
        if(var%3 == 0){
            std::cout << var << " is N O T a prime number!" << std::endl;
        }
        while(i<=limes){
            if(var%i == 0){
                std::cout << var << " is N O T prime." << std::endl;
                return;
            }
            i = i+firstPrime;
            firstPrime = 6-i;
        }
        std::cout << var << " is PRIME." << std::endl;
}
