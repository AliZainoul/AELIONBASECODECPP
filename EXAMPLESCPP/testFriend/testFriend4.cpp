#include <iostream>
using namespace std;
class MyClass
{
public:
    MyClass() :m_Val(99) {}
    friend void (operator<<)(ostream& os, MyClass& mc){
        os << mc.m_Val;
        //return *this;
    }

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

//NOT FUNCTIONAL: ERROR AT LINE 17
/*
testFriend.cpp:17:8: error: invalid operands to binary expression ('MyClass' and 'std::ostream' (aka 'basic_ostream<char>'))
    mc << cout; // Weird!!
    ~~ ^  ~~~~
testFriend.cpp:7:18: 
*/

/*
FUNCTION IF AND ONLY IF:

    -- cout << mc; is FUNCTIONAL !!
  OR
    -- we overload the operator<< with the two definitions.
*/