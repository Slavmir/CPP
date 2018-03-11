#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <windows.h>

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
    int passLength=0;
    cout << "Enter password length: " << endl;
    cin >> passLength;
    while (passLength != 0){
    if(passLength <8){
            cout << "Password is not secure!" << endl;
            cin >> passLength;
    }
    else if(passLength > 12){
        cout << "You're really going to remmebr this ??" << endl;
        cin >> passLength;
    }
    else{
        srand(time(NULL));
        std::string strPass;
            for(int i=0; i<passLength; ++i)
                strPass += genRandomPass();

            cout << "Random password i: " << strPass << endl;
        }
    }
    return 0;
}

char genRandomPass(){
    return alphNum[rand() % strlength];
}
