#include <iostream>
using namespace std;

///-------function template with 1 param-----------------------------------------------------------------------------------
/
template <class tmplt> //template definition building a generic type of data
tmplt add2numbers(tmplt a, tmplt b){
    return a+b;
}

int main()
{
        int x=47, y=3, z;
        z = add2numbers(x, y);
        std::cout << z << std::endl;
        return (0);
}
*/
///------Function template wit 2 parameters------------------------------------------------
/**
template <class Tmpl, class Und>
Tmpl smaller(Tmpl a, Und b){
    return (a<b?a:b); // if(a<b) return a if not return b
}

int main()
{
    int x=89;
    double y= 66.578;
    cout << smaller(x, y) << endl;
}
*/
///---------template class---------------------------------------------------------------------------------
//CLASS template

template <class T>
class class1
{
    T first, second;
    public:
        class1(T a, T b){
            first = a;
            second = b;
        }
        T bigger(); //function in class template
};

template <class T> //before every class function call - class template init<c++ specific>
T class1<T>::bigger(){  //<T> use the same template [arameter that's used in class <c++ specific>
        return (first>second?first:second);
}

int main()
{
        class1 <int> _accessObject(69, 106); //with class template we use the same data type here - what type of data we declared for T will be used here
        cout << _accessObject.bigger();
}



template <class T>
class myClass
{
    public:
        myClass(T x){
            cout << x << "is not a char!" << endl;
        }
} ;

template<>//template specialization
class myClass<char>{
    public:
       myClass(char x){
        cout << "X is a character!" << endl;
       }
};

int main()
{
    myClass<int> _accessObject1(7);
    myClass<double> _accessObject2(3.14);
    myClass<char> _accessObject3('Q');
}
