/*

    * CPP buffer flush :
    -> A buffer flush is the transfer of computer data from a temporary storage area to the computer’s permanent memory.
    -> we use std::flush for flushing the output.
    -> Generally, the std::endl function works the same by inserting a new-line character and flushes the stream.

    NOTE : if for mingw compilers if below code is not working then try it on https://www.onlinegdb.com/fork/ryYiG5i3z#

    To learn more about multithreading visit : https://cplusplus.com/reference/multithreading/

 */

#include <iostream>
#include <thread> // std::this_thread::sleep_for
#include <chrono> // std::chrono::seconds

using namespace std;

void print_all(int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        cout << i + 1 << endl;
    }
}

int main()
{
    // it print all the number at once after 5 seconds
    cout << "Printing without flush : ";
    for (int i = 1; i <= 5; i++)
    {
        cout << i << " ";
        this_thread::sleep_for(chrono::seconds(1));
    }

    // it will print number after each second.
    cout << "Printing with flush : ";
    for (int i = 1; i <= 5; i++)
    {
        cout << i << " " << flush;
        this_thread::sleep_for(chrono::seconds(1));
    }

    // here it create a new thread and start given function which is given inside the argument.
    thread t1(print_all, 0, 20);
    thread t2(print_all, 30, 50);

    return 0;
}