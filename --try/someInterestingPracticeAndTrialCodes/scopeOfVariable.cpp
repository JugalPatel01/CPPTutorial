#include <iostream>
#define deb(x) cout << #x << " = " << x << " -> " << &x << endl; // Macro for x and its value

using namespace std;
int main()
{
    // 1st phase
    int a = 10, b = 20;     // here a and b are defined in 1st phase 
    deb(a);
    deb(b);
    cout << endl;
    {
        // 2nd phase            
        int a = 15, c = 18;        // here 2nd phase is inside the 1st phase and it again declair variable a in this scope
            deb(a);
            deb(b);
            deb(c);
            cout<<endl;
        {
            // 3rd phase
            int b = 25, d = 30;         // here b is declaird again in other memory space which is differnt from outer scope
            deb(a);
            deb(b);
            deb(c);
            deb(d);
            cout<<endl;
        }
    }
    deb(a);
    deb(b);

    return 0;
}