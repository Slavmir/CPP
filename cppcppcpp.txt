#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

static const char alphNum[] =
"0123456789"
"abcdefghijklmnopqrstuwxyz"
"ABCDEFGHIJKLMNOPQRSTUWXYZ"
"!@#$%^&*()-=_+";

const int strlength = sizeof(alphNum) - 1;

char genRandomPass(); //prttp

int main()
{
    srand(time(NULL));
    std::string strPass;
    for(int i=0; i<20; ++i){
        strPass += genRandomPass();
    }
    cout << strPass << endl;
    return 0;
}

char genRandomPass(){
            return alphNum[rand() % strlength];
}
