#include <iostream>
using namespace std;
class MyClass
{
public:
    MyClass() :m_Val(99) {}
    void (operator<<)(MyClass& mc, ostream& os){
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

// NOT FUNCTIONAL: 

/*
testFriend2.cpp:7:11: error: overloaded 'operator<<' must be a binary operator (has 3 parameters)
    void (operator<<)(MyClass& mc, ostream& os){
          ^
testFriend2.cpp:17:8: error: invalid operands to binary expression ('MyClass' and 'std::ostream' (aka 'basic_ostream<char>'))
    mc << cout; // Weird!!
    ~~ ^  ~~~~
*/

/*
    Because the this pointer does not exist in friendship
*/