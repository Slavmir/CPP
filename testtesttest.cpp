// NOT MY CODE -- I have absolutely no idea why it's here and what for ...

#include <iostream>
#include <cmath>

typedef unsigned int UI;

int main(int argc, char * argv[])
{
        UI c, k, t, q, m ,n, i, j, ij;
        bool * S;
        std::cin >> n;
        m = n/3;
        if(!(m % 1))
            m++;
        S = new bool [m + 1];
        c = 0;
        k = 1;
        t = 2;
        q = ((UI)sqrt(n))/3;
        for(i=1; i<=m; i++)
            S[i] = true;
        for(i=1; i<=q; i++){
            k = 3 - k;
            c += (k << 2) * i;
            j = c;
            ij = (i << 1) * (3 - k) + 1;
            t += k << 2;
            while(j <= m){
                S[j] = false;
                j += ij;
                ij = t - ij;
            }
        }
        std::cout << 2 << " " << 3 << " ";
        for(i=1; i<=m; i++)
        if(S[i]){
            if(i & 1)
                std::cout << 3 * i + 2;
            else
                std::cout << 3 * i + 1;
            std::cout << " ";
        }
        std::cout << std::endl;
        delete [] S;
}

