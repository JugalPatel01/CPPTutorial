/*

    # string class implementation from scratch (Implimentation of almost all OOPS concepts in real world)

    expected functionalities of new string class are :
        -> create/initiate an empty string
        -> create a constant string
        -> Give a value of one string variable to other new string variable
        -> Give a value of one string variable to already defined string variable
        -> Get size/length of the string
        -> Take input and show output of the strings

*/

#include <iostream>
#include <string.h>
// #include <cstring>
using namespace std;

class String
{

public:
    // Default constructor , using initialization list for assiging value in the class data members
    String() : data(nullptr), len(0)
    {
    }

    // Parameterized constructor
    String(const char *ch)
    {
        len = strlen(ch);
        data = new char[len + 1];
        strcpy(data, ch);
    }

    // Copy constructor
    String(const String &str)
    {
        if (str.data)
        {
            len = str.len;
            data = new char[len + 1];
            strcpy(data, str.data);
        } else{
            data = nullptr;
            len = 0;
        }
    }

    // Move constructor
    String(String &&str) : data(str.data), len(str.len)
    {
        str.len = 0;
        str.data = nullptr;
    }

    // // Copy assignment operator
    // String &operator=(const String &str)
    // {
    //     if (this != &str)
    //     {
    //         if(data) delete[] data;
    //         len = str.len;
    //         data = new char[len + 1];
    //         strcpy(data, str.data);
    //     }

    //     return *this;
    // }

    // Above method is simple way to implement copy assignment operator, but suppose there is some problem with assigning a new
    // resources, then this method will return error so, to deal with this issue we can go with copy and swap method.

    String &operator=(const String &str)
    {
        if (this != &str)
        {
            String temp(str);
            Swap(*this, temp);
        }
        return *this;
    }

    void Swap(String &str1, String &str2)
    {
        std::swap(str1.data, str2.data);
        std::swap(str1.len, str2.len);
    }

    // Move assignment operator

    String &operator=(String &&str)
    {
        if (this != &str)
        {
            if (data)
                delete[] data;
            data = str.data;
            len = str.len;
            str.data = nullptr;
            str.len = 0;
        }
        return *this;
    }

    unsigned int length() const
    {
        return len;
    }

    ~String()
    {
        delete[] data;
        data = nullptr;
        len = 0;
    }

private:
    char *data;
    unsigned int len;
    friend ostream &operator<<(ostream &out, const String &str);
    friend istream &operator>>(istream &in, String &str);
};

ostream &operator<<(ostream &out, const String &str)
{
    if (str.data)
        out << str.data;
    return out;
}

istream &operator>>(istream &in, String &str)
{
    char buffer[255];
    in >> buffer;

    if (str.data)
        delete[] str.data;

    str.len = strlen(buffer);
    str.data = new char[str.len + 1];
    strcpy(str.data, buffer);

    return in;
}

int main()
{
    // first requirement -> initialize an empty string
    String str1; // using default constructor

    // second requirement  -> create a string with constant value
    String str2 = "New_str"; // using parameterized constructor

    // third requirement    -> give a value of one string variable to new string variable
    String str3 = str1; // using copy constructor

    // fourth requirement -> give a value of one string variable to already existing variable
    str3 = str2; // using copy assignment operator

    // fifth requirement  -> Get size of the string
    unsigned int len_str2 = str2.length();
    cout << "length of str2 is : " << len_str2 << endl;

    // sixth requirement -> output the string
    cout << str2 <<endl; // overloading << operator

    // seventh requirement -> take input of the string
    cin >> str1; // overloaing >> operator

    // eighth requirement -> move resources from one variable to other variable for optmization
    String str4 = std::move(str2); // use of move constructor

    cout<<str4<<endl;
    cout<<str2<<endl;

    return 0;
}