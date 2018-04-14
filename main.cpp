#include <iostream>

class ArmstrongNumbersClass
{
    int orgNum, orgNum2, number, rem, sum=0;

    public:
        void ArmstrongNumberCheck();
        void ArmstrongNumberBetweenIntervals();
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

int main()
{
        std::cout << "1. Check if number is an Armstrong number:" << std::endl;
        ArmstrongNumbersClass _armstrongNumbersObject;
        _armstrongNumbersObject.ArmstrongNumberCheck();
        std::cout << "2. Check Armstrong numbers between an interval:" << std::endl;
        ArmstrongNumbersClass _accessObjectInterval;
        _accessObjectInterval.ArmstrongNumberBetweenIntervals();
}


//Prog A -- was.lukasz@gmail.com
