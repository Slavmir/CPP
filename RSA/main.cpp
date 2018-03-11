#include "pre_proc_definitions.hpp"

int main()
{
    srand(time(NULL));
    int choice;
    std::cout << "Press enter to start." << std::endl;
    std::cin.get();
    do
    {
        std::cout << "1 - generate keys" << std::endl;
        std::cout << "2 - encrypt message" << std::endl;
        std::cout << "0 - exit" << std::endl;
        std::cin >> choice;
        switch(choice)
        {
            case 1:
            rsa_keys();
            break;

            case 2:
            RSAcipher_decipher();
            break;
        }
    }while(choice != 0);

    return (0);
}

void w8(void){
    char c[1];
    std::cin.getline(c, 1);
    std::cin.getline(c, 1);
    for(int i=1; i<500; i++)
        std::cout << std::endl;
}

ULL biggestCommonDivisor(ULL a, ULL b){
    ULL t;
    while(b != 0){
        t = b;
        b = b % a;
        a = t;
    }
    return a;
}

ULL reverseModulus(ULL a, ULL n){
    ULL a0, n0, p0, p1, q, r, t;
    p0 = 0;
    p1 = 1;
    a0 = a;
    n0 = n;
    q = n0 / a0;
    r = n0 % a0;

    while(r > 0){
        t = p0 - q * p1;
        if(t >= 0)
            t = t % n;
        else
            t = n - ((-t) % n);
        p0 = p1;
        p1 = t;
        n0 = a0;
        a0 = r;
        q = n0 / a0;
        r = n0 % a0;
    }
    return p1;
}

void rsa_keys(){
    const unsigned int smallPrimesArray[14] = {3, 5, 7, 11, 13, 17, 19, 21, 23, 29, 31, 39, 41, 51};
    const ULL hexedPrimes[100] = {
        0x737be43, 0x737be5f, 0x737be73, 0x737be89, 0x737beb3,
        0x737beb5, 0x737bebf, 0x737bec5, 0x737bedd, 0x737beeb,
        0x737befb, 0x737bf49, 0x737bf69, 0x737bf73, 0x737bf85,
        0x737bf8b, 0x737bf99, 0x737bf9f, 0x737bfab, 0x737bfb5,
        0x737bfcd, 0x737bfff, 0x737c011, 0x737c021, 0x737c02d,
        0x737c0b7, 0x737c0b9, 0x737c0c5, 0x737c0f3, 0x737c0ff,
        0x737c117, 0x737c11f, 0x737c153, 0x737c167, 0x737c16b,
        0x737c195, 0x737c1bf, 0x737c1f7, 0x737c1fd, 0x737c219,
        0x737c21b, 0x737c225, 0x737c23f, 0x737c255, 0x737c269,
        0x737c26f, 0x737c27f, 0x737c28d, 0x737c291, 0x737c293,
        0x737c2bb, 0x737c2cf, 0x737c2d3, 0x737c2e7, 0x737c2eb,
        0x737c2f3, 0x737c305, 0x737c309, 0x737c315, 0x737c363,
        0x737c3cf, 0x737c3dd, 0x737c3f5, 0x737c3ff, 0x737c405,
        0x737c40b, 0x737c423, 0x737c429, 0x737c447, 0x737c449,
        0x737c477, 0x737c48b, 0x737c491, 0x737c497, 0x737c49b,
        0x737c527, 0x737c549, 0x737c563, 0x737c57f, 0x737c58b,
        0x737c593, 0x737c59d, 0x737c5a3, 0x737c5a9, 0x737c5bd,
        0x737c5e1, 0x737c615, 0x737c61b, 0x737c63b, 0x737c64d,
        0x737c653, 0x737c659, 0x737c65d, 0x737c665, 0x737c66b,
        0x737c6a7, 0x737c6ad, 0x737c6db, 0x737c6f9, 0x737c725
    };

/*AR --> 4589414309519119*/

    ULL key_P, key_Q, phi,n,e,d;
    key_P = hexedPrimes[rand() % 100];
    key_Q = hexedPrimes[rand() % 100];
    phi = (key_P - 1) * (key_Q - 1);
    n = key_P * key_Q;     /// 10848072686786669520
    for(e=hexedPrimes[rand() % 14]; biggestCommonDivisor(e, phi) != 1; e+=2){
        d = reverseModulus(e, phi);
    }
    std::cout << "Write the data that you'll see! For Public keys!" << std::endl;
    std::cout << "Public key!" << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "n: " << n << std::endl;
    std::cout << "Private key!" << std::endl;
    std::cout << "d: " << d << std::endl;
    w8();
}

ULL power_modulo(ULL a, ULL w, ULL n){
        ULL pow, res, q;
        pow = a;
        res = 1;
        for(q=w; q>0; q /=2){
            if(q % 2)
                res = (res * pow) % n;
            pow = (pow * pow) % n;
        }
        return res;
}

void RSAcipher_decipher(){
    ULL e, n ,t;
    std::cout << "RSA cipher" << std::endl;
    std::cout << "Enter e: ";
    std::cin >> e;
    std::cout << "Enter modulus: ";
    std::cin >> n;
    std::cout << "-------------------" << std::endl;
    std::cout << "RSA code (t): " << std::endl;
    std::cin >> t;
    std::cout << power_modulo(t,e,n) << std::endl;
    w8();
}
/**
e: 176796025
n: 14664029540542427
*/
