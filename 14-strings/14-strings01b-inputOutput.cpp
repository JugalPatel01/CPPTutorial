#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
int main()
{

    string str;
    getline(cin, str);
    cout << "Entered string is : " << str << endl;

    // suppose we have to sperate a string using some separator which is present in the string
    // eg. "year,good,bad,back,and,what"
    // here we have to seperate words after ',' like ["year","good","bad","back","and","what"] then
    // here we can use sstream (string stream) library for that.
    // string stream is used for string parsing(we can use sstream to break a string into parts using delimiters), and string conversion(we can use it to convert between different datatypes and strings)

    string example = "year, good, bad, back , and, what";
    stringstream ss(example);

    vector<string> partsOfstring;
    string part;
    while (getline(ss, part, '.'))
    {
        partsOfstring.push_back(part);
    }
    cout << "[";
    for (auto i : partsOfstring)
    {
        cout << i << " ";
    }
    cout << "]" << endl;

    // we can again join the words using in using sstream.
    int day = 7, month = 3, year = 2024;
    stringstream datestream;
    datestream << day << "-" << month << "-" << year;
    string date = datestream.str();
    cout << "date : " << date << endl;

    // we can use sstream to reading words which are space spereated
    string sentence = "This is world of CPP";
    stringstream sentencestream(sentence);
    string sen_word;
    while (sentencestream >> sen_word)
    {
        cout << sen_word << " -> ";
    }
    cout << endl;

    return 0;
}