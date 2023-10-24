/*

    # namespaces

    * namespaces
    -> It allow us to group named entities that otherwise would have global scope into narrower scopes, giving them 
       namespace scope.
    -> This allows organizing the elements of programs into different logical scopes referred to by names.

        syntax : 
        namespace ns_name{
            int a, b;
        }

    -> we can directly use this variables inside the namespace but to use them outside the namespace we have to use :: (scope   
       operator). 
        eg. ns_name::a, ns_name::b, std::a, etc...

    To learn more about namespaces visit : https://cplusplus.com/doc/tutorial/namespaces/
*/

#include <iostream>
using namespace std;

void print_func()
{
    cout << "from std namespace." << endl;
}

namespace one
{
    void print_func()
    {
        cout << "from namespace one." << endl;
    }
}

namespace second
{
    void print_func()
    {
        cout << "from namespace two." << endl;
    }
}

int main()
{
    print_func();
    one::print_func();
    second::print_func();
    return 0;
}