/*

    # What are exceptions?
        -> Exceptions are the unexpected situations that arise during the execution of a program.
        -> Exception handling provides a mechanism through which we can handle the error generating part separately from the rest of the code.
        -> It provides the information to the user. so that developer can detect the mistake and correct it.
        -> There are mainly three exception handling keywords:
            -> try : this part assumes that error will take place.
            -> catch : This part identifies which exception has occurred and tried to catch it.
            -> throw : when the program encounters an issue it, throws an exception.

*/

#include <iostream>
using namespace std;

class Printer
{
    string name;
    int available_papers;

public:
    Printer(string s, int paper) : name(s), available_papers(paper) {}

    void Print(string text_doc)
    {
        // suppose in one page we can print 4 letters
        int required_paper = text_doc.length() / 4;

        if (required_paper > available_papers)
        {
            throw "Papers are not enough.";
        }

        cout << "Printing ... " << text_doc << endl;
        available_papers -= required_paper;
        if (available_papers == 0)
        {
            throw 0;
        }
    }
};

int main()
{
    Printer p1("epson ", 8);
    try
    {
        p1.Print("This the text for printing and we need almost 4 pages for this text. ");
    }
    catch (const char *exc)
    {
        cout << "Exception : " << exc << endl;
    }
    catch (const int &exc)
    {
        cout << "There is " << exc << "papers are remaining in the printer. please fill it." << endl;
    }
    catch (...)
    {
        cout << "exception in Printer class's Print method" << endl;
    }
    return 0;
}