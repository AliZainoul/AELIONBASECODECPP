#include <iostream>
using namespace std;
class MyClass
{
public:
    MyClass() :m_Val(99) {}
    friend void (operator<<)(MyClass& mc, ostream& os){
        os << mc.m_Val;
        //return *this;
    }
private:
    int m_Val;

};
int main(){
    MyClass mc;
    mc << cout; // Weird!!
    return 0;
}

// FUNCTIONAL: in the parameters of the << operator, we start with MyClass& mc