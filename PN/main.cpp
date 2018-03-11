#include <iostream>
#include <cstdlib>
int main()
{
    const int p = 70;
    int cntr;
    unsigned long long min_ll = 10000000000000;
    unsigned long long max_ll = LONG_MAX;
    unsigned long long ax, bx, t;
    for (int i=min_ll; i<=max_ll; i++){
        ax=i;
        bx=p;
        while(bx){
            t = bx;
            bx= ax % bx;
            ax=t;
        }
        if(ax == 1)
            std::cout << cntr + 1 << i << " ";
            while(cntr == 150){
            system("PAUSE");
        }
    }
    std::cout << std::endl;
    return 0;
}
