#include <iostream>
#include <cstdlib>
#include <random>
#include <chrono>
typedef unsigned long long ULL;

ULL generateVar(auto seed); /// prttp
void checkIFprime(ULL numVar); ///prttp

int main()
{
        auto s = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        ULL numVar = generateVar(s);
        checkIFprime(numVar);
        return (0);
}

ULL generateVar(auto seed){
    ULL v;
    std::mt19937_64 mt_rand_64(seed);
    v = mt_rand_64();
    return v;
}

void checkIFprime(ULL numVar){

        ULL x =5;
        int wx =2;
        const long long limes = sqrt(numVar);

        if(numVar == 1){
            std::cout << numVar << " hard to classify if it's prime." << std::endl;
            return;
        }
        if(numVar == 2){
            std::cout << numVar << " is prime!" << std::endl;
            return;
        }
        if(numVar == 3){
            std::cout << numVar << " is prime!" << std::endl;
            return;
        }
        //odd ball
        if (numVar%2 == 0){
            std::cout << numVar << " is NOT a prime!" << std::endl;
            return;
        }
        if(numVar%3 == 0){
            std::cout << numVar << " is NOT prime" << std::endl;
            return;
        }

        while(x <= limes){
            if(numVar%x == 0){
                std::cout << numVar << " is NOT prime!" << std::endl;
                return;
            }
            x = x + wx;
            wx = 6 - x;
        }
        std::cout << numVar << " is prime!" << std::endl;
}
