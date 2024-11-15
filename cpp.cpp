#include <iostream>
using namespace std;

class MyClass {
public:
    static int value;
};

int MyClass::value = 0;


int main(){
    int x;
    cout<<"Enter: ";
    cin>>x;

    MyClass newClass;
    newClass.value+=x;
    cout<<"Value: "<<newClass.value<<endl;;
    main();
}