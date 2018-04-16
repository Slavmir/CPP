#include <iostream>
#include <cstdlib>
#include <windows.h>

class ArmstrongNumbersClass
{
    int orgNum, orgNum2, number, rem, sum=0;

    public:
        void ArmstrongNumberCheck();
        void ArmstrongNumberBetweenIntervals();
        void menu();
};

void ArmstrongNumbersClass::ArmstrongNumberCheck(){
    using namespace std;
    cout << "Enter number " << endl;
    cin >> orgNum;
    number = orgNum;
    while(number>0)
    {
        rem = number % 10;
        sum += rem * rem * rem;
        number /= 10;
    }
    if(sum == orgNum)
        cout << orgNum << " is an Armstrong number." << endl;
    else
        cout << orgNum << " is NOT an Armstrong number." << endl;
}

void ArmstrongNumbersClass::ArmstrongNumberBetweenIntervals(){
        using namespace std;
        cout << "Find Armstrong numbers between and interval i.e. 100 - 300" << endl;
        cout << "Enter 1st number: " << endl;
        cin >> orgNum;
        cout << "Enter 2nd number: " << endl;
        cin >> orgNum2;
        cout << "Armstrong numbers between " << orgNum << " and " << orgNum2 << " are: " << endl;
        for(int i=orgNum; i<=orgNum2; i++){
            sum = 0;
            number = i;
                for(; number>0; number/=10){
                    rem = number % 10;
                    sum = sum + rem * rem * rem;
                }
                if(sum == i){
                    cout << i << endl;
                }
        }
}

void ArmstrongNumbersClass::menu(){
        int ans;
        char ansQuit;
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        std::cout << "Armstrong numbers. Select from below available options." << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "1. Check if number is an Armstrong number:" << std::endl;
        std::cout << "2. Check Armstrong numbers between an interval:" << std::endl;
        std::cout << "0. Exit program" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cin >> ans;
        switch(ans)
        {
        case 1:
            system("cls");
            //ArmstrongNumbersClass _armstrongNumbersObject; -- not required to init object and load function with the use of object
            ArmstrongNumberCheck();
            std::cout << "Done" << std::endl;
            std::cout << "Try again?";
            std::cin >> ansQuit;
            if(ansQuit == 'Y' || ansQuit == 'y'){
                system("cls");
                menu();
            }
            else
                exit (1);
            break;

        case 2:
            system("cls");
            //ArmstrongNumbersClass _accessObjectInterval; -- not required to init object and load function with the use of object
            ArmstrongNumberBetweenIntervals();
            std::cout << "Done" << std::endl;
            if(ansQuit == 'Y' || ansQuit == 'y'){
                system("cls");
                menu();
            }
            else
                exit (1);
            break;

        case 0:
            system("cls");
            std::cout << "SenkJu bye... !!! " << std::endl;
            break;

        default:
            std::cout << "Wrong selection" << std::endl;
            system("cls");
            menu();
        }
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

int main(int argc, char ** argv)
{
        ArmstrongNumbersClass _mainArmstrongObject;
        _mainArmstrongObject.menu();

}
//Prog A -- was.lukasz@gmail.com
