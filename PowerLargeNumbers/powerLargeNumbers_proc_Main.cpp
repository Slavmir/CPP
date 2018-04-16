#include "pre_proc.hpp"

std::string add_2_numbers(std::string & x, std::string & y){
        std::string zeta_String;
        int n, p, w;
        int i = x.length();
        int j = y.length();
        n=i;
        if(j<n)
            n=j;
                for (int k=1; k<=n; k++){
                    w = (int)(x[--i]) + (int)(y[--j]) + p - 96;
                    p = w / 10;
                    zeta_String = (char)((w % 10) + 48) + zeta_String;
                }
                //
                    while(i){
                        w = x[--i] + p - 48;
                        p = w / 10;
                        zeta_String = (char)((w % 10) + 48) + zeta_String;
                    }
                    //
                        while(j){
                            w = y[--j] + p - 48;
                            p = w / 10;
                            zeta_String = (char)((w % 10) + 48) + zeta_String;
                        }
                        //
                if(p)
                    zeta_String = (char)(p + 48) + zeta_String;

                if(zeta_String == "")
                    zeta_String = "0";

        return zeta_String;
}

std::string multiply_ull_and_ui(std::string a, UI b){
        std::string w;
        w = "0";
        while(true){
            if(b & 1)
                w = add_2_numbers(w, a);
            if(b >>= 1)
                a = add_2_numbers(a, a);
            else
                break;
        }
        return w;
}

std::string multiply_2_ull_numbers(std::string & a, std::string & b){
        std::string c, w, zeta_String;
        w ="0";
        zeta_String = "";

        for (int i=b.length()-1; i>=0; i--){
            c = multiply_ull_and_ui(a, b[i] - 48) + zeta_String;
            w = add_2_numbers(w, c);
            zeta_String = zeta_String + "0";
        }
        return w;
}

ULL generator(auto seed){
    std::mt19937_64 mt_rand_64(seed);
    ULL tmpVar = mt_rand_64();
    return tmpVar;
}

int main()
{
    std::string a, w;
    UI b = 5;
    auto s = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    ULL xx = generator(s);
    a = xx;
    std::cout << xx << std::endl;
    w = 1;
    while(true){
        if(b & 1)
            w = multiply_2_ull_numbers(w, a);
        if(b >>= 1)
            a = multiply_2_ull_numbers(a, a);
        else
            break;
}
    std::cout << w << std::endl;
    return (0);
}
