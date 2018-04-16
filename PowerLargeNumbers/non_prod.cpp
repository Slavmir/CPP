#include <iostream>
#include <string>
#include <chrono>
#include <random>

typedef unsigned long long ULL;
typedef unsigned int UI;

std::string add2numbers(std::string & x, std::string & y){
    std::string z;
    int p, w, i, j, k, n;
    i = x.length();
    j = y.length();
    n=i;
        if(j<i)
            n=j;
    p=0;
    z="";

        for (k=1; k<=n; k++){
            w = (int)(x[--i]) + (int)(y[--j]) + p - 96;
            p = w / 10;
            z = (char)((w % 10) + 48) + z;
        }
        //
            while(i){
                w = x[--i] + p - 48;
                p = w / 10;
                z = (char)((w % 10) + 48) + z;
                }
                //
                while(j){
                    w = y[--j] + p - 48;
                    p = w / 10;
                    z = (char)((w % 10) + 48) + z;
                    }
                    //
        if(p)
            z = (char)(p + 48) + z;

        if(z == "")
            z = "0";

        return z;
}

std::string multiply2Numbers(std::string a, UI b){
    std::string w;
    w = "0";
    while(true){
        if(b & 1)
            w = add2numbers(w , a);
        if (b >>= 1)
            a = add2numbers(a, a);
            else
                break;
    }
    return w;
}

std::string multiply2_large_Numbers(std::string & a, std::string & b){
    std::string c, w ,z;
    w = "0";
    z = "";

    for (int i=b.length()-1; i>=0; i--){
        c = multiply2Numbers(a, b[i]-48) + z;
        w = add2numbers(w ,c);
        z = z + "0";
    }
    return w;
}

int main()
{
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::string a, w;
    UI b = 6;
    std::mt19937_64 mt_rand_64(seed);
    ULL rndVar = mt_rand_64();
    std::cout << rndVar  << std::endl;
    a = rndVar;
    w = "1";

    while(true){
        if(b & 1)
            w = multiply2_large_Numbers(w, a);
        if(b >>= 1)
            a = multiply2_large_Numbers(a, a);
            else
                break;
    }
    std::cout << w << std::endl;
}

// <2048bit> -- 225685888979403526093186291267556277617864379101740646457136881
