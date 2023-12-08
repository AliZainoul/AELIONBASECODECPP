#include <iostream>
using namespace std;
class MyClass
{
public:
    MyClass() :m_Val(99) {}
    void (operator<<)(ostream& os){
        os << m_Val;
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

// FUNCTIONAL: LOGICAL << in line 17 is the surcharched operator; meanwhile the << operator in line 8 is the stream operator. 