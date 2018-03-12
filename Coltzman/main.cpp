#include <iostream>
//Liczby z sekwencji Coltzmana ktore wchodza w warunek 3n-1
// wychodzi mi ze sa to liczby I-sze
int main ()
{
    int ans;

    std::cout << " Enter a number :";
    std::cin >> ans;

    while ( ans != 1 ){
        if ( ans % 2 == 1){
            std::cout << ans << std::endl;
            ans = (3 * ans) + 1;
        }
        else
            ans /= 2;

    //std::cout << ans << " ";
    }

    return 0;
}
