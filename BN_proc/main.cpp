#include "pre_proc.hpp"

class get2048var
{
    public:
        std::string add_2_numbers(std::string & x, std::string & y);
        std::string multiply_ull_and_ui(std::string a, UI b);
        std::string multiply_2_ull_numbers(std::string & a, std::string & b);
        ULL generator(auto seed);
        std::string executeProgram();

    protected:
        std::string vvr;

};

std::string get2048var::add_2_numbers(std::string & x, std::string & y){
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

std::string get2048var::multiply_ull_and_ui(std::string a, UI b){
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

std::string get2048var::multiply_2_ull_numbers(std::string & a, std::string & b){
        std::string c, w, zeta_String;
        w ="0";
        zeta_String = "";

        for (int i=b.length()-1; i>=0; i--){
            c = multiply_ull_and_ui(a, b[i]-48)+zeta_String;
            w = add_2_numbers(w, c);
            zeta_String = zeta_String + "0";
        }
        return w;
}

ULL get2048var::generator(auto seed){
    std::mt19937_64 mt_rand_64(seed);
    ULL tmpVar = mt_rand_64();
    return tmpVar;
}

std::string get2048var::executeProgram(){
    std::string a, w;
    UI b = 2048;
    auto s = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    ULL xx = generator(s);
    a = 2;
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
    std::cout << "2048 bit number:  " << w << std::endl;
    vvr = w;
    return w;
}

/**
54656372167286453806804451922838513789172128581928
1432120197967251519456494022048534789701014515293
373408938328596935267618640653825439552292160
1797867153005986906830341110184672338093390306873
*/

int main()
{
    get2048var _access2048object;
    _access2048object.executeProgram();
    return (0);
}
