/*

    # Manipulators
    -> Manipulators are helping functions that can modify the input/output streams.
    -> This special functions are included in the I/O statements to alter the format parameters of a stream.
    -> Different Differnet manipulators.
        -> Some manipulators are defined in the "iostream", "ios" and "iomanip" library.
            1) endl : It is used to enter a new line and after entering a new line it flushes the output stream.

            2) ends : It inserts a null character into the output stream.
                    : It works with std::ostrstream, when the associated output buffer needs to be null-terminated to be processed as a C string.

            3) flush : it flushes(forces all the output written on the screen or in the file) the output stream.
                        : flush, endl and ends are defined in the ostream.
                        : For getting more details about flush check it out on below file location :
                        --try\Interesting_and_funny_Trial_codes\Multi_threading_and_parallelism\01-flush_and_multithreading.cpp

            4) ws : It is defined in istream.
                    : It is used to ignore the whitespaces in the string sequences.

            NOTE : apart from these there are (showpos, noshowpos, showbase, uppercase, nouppercase, fixed, scientific, hex, dec, oct, left, right) manipulators which are non-parameterized Manipulators.

            5) setw(val) : It is used to set the field width in output operations.

            6) setfill(char) : It is used to fill the character 'char' on output stream.

            7) setprecision(val) :It sets 'val' as the new value for the precision of floating-point values.

            8) setbase(val) : It is used to set the numeric base value for numeric values.

    NOTE : more information about manipulators are on
            -> https://cplusplus.com/reference/ios/
            -> https://cplusplus.com/reference/iomanip/
*/

#include <iostream>
#include <istream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{

    // normal string with white space
    string str1 = "            abc";

    // passing it to the string stream
    istringstream str2(str1);

    string line;
    // Use of "ws" Manipulator for getting string from the string stream.
    getline(str2 >> std::ws, line);

    // use of "endl" manipulator
    cout << "str1 is : " << str1 << endl;
    cout << "line is : " << line << endl;

    /*

       NOTE : implementaion of flush manipulator is in below file location :

        --try\Interesting_and_funny_Trial_codes\Multi_threading_and_parallelism\01 - flush_and_multithreading.cpp

    */

    // use of ends manipulator
    ostringstream ss;
    streambuf *old_buffer = cout.rdbuf(ss.rdbuf());
    cout << "a";
    cout << "b" << ends;
    cout << "c" << endl;
    cout.rdbuf(old_buffer);
    string generated_line = ss.str();
    cout << "generated line by ends and endl is : " << generated_line << endl;

    for (auto ch : generated_line)
    {
        cout << "ascii value for '" << ch << "' is " << int(ch) << endl;
    }

    // Use of hex, oct, setbase(), fixed, setprecision(), setw() manipulators
    double number1 = 23.251352345353;
    int number = 23;
    cout << "Number is = " << number << endl;
    cout << "Hex value of number is = " << hex << number << endl;
    cout << "Octal value of number is = " << oct << number << endl;
    cout << "setbase(16) value of number is = " << setbase(10) << number << endl;
    cout << endl;
    cout << "Number1 is = " << number1 << endl;
    cout << "setprecision(3) value of the number1 is = " << setprecision(3) << number1 << endl;
    cout << "fixed and setprecision(3) value of the number1 is = " << fixed << setprecision(3) << number1 << endl;
    cout << "scientific  value of number1 is = " << scientific << setw(30) << right << number1 << endl;

    return 0;
}