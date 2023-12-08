#include <iostream>

using namespace std;
union point
{
   //defining a union
   double x,y,z;
};

int main()
{
    point p1 = {13.3};
    p1.y = 12.3;
    p1.z = 14.2;
    cout << p1.x << endl;
    cout << p1.y << endl;
    cout << p1.z << endl;

    return 0;
}