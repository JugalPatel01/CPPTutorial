// Egyptian fraction

/*
    2/3 = (1/2)+(1/6)
    6/14 = (1/3)+(1/11)+(1/231)
    12/13= (1/2)+(1/3)+(1/12)+(1/156)

    eg. consider 6/14, we first find ceiling of 14/6, i.e., 3. so the first unit fraction becomes 1/3, then recur for (6/14-1/3) i.e.,4/42

*/
#include <iostream>
using namespace std;

void printEgyptian(int nr, int dr)
{

    if (nr == 0 || dr == 0)
        return;

    if (dr % nr == 0)
    {
        cout << "1/" << dr;
        return;
    }

    if (nr % dr == 0)
    {
        cout << nr / dr;
        return;
    }

    if (nr > dr)
    {
        cout << nr / dr << " + ";
        printEgyptian(nr % dr, dr);
        return;
    }

    if (dr > nr)
    {
        /*
            3/14 then
            n = 14/3 +1
              = (dr/nr)+1
            E.F. = 1/5 +
                 = (1/n)+

                =(3/14)-(1/5)=((3*5)-14)/(14*5)
                =((nr*n)-dr)/(dr*n)
        */
        int n = (dr / nr) + 1;
        cout << " 1/" << n << " + ";
        return printEgyptian((nr * n) - dr, dr * n);
    }
}

int main()
{
    int nr, dr;
    cout << "enter numerator and denominator respectivly" << endl;
    cin >> nr >> dr;

    cout << "Egyptian francton is ";
    printEgyptian(nr, dr);

    return 0;
}