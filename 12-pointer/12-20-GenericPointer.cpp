/*
    If we don't know what type of variable's address we need to store in pointer at that time we use generic pointer.
    baiscally generic pointers are void pointers and at the time of using that pointer we need to do explicit typecast.

    type casting : convert type of data into another type like int to char , float to integer
    1)Implicit typecasting  : performed by compiler
    2)explicit typecasting  : perfomred by user forcefully


    here we do explicit typecasting by forcefully so output is depended upon little endian or big endian system

    example : we need to typecast 321 to character and as per we know range of character is 0 to 127 .
    so,suppose our system following little Endian then this typecasting give us 65 which is equivalent to A
    and suppos our system following big Endian then this typecasting give us 1 which is equal to start of heading means blank.

    Little Endian and Big Endian method for representing data in (Memory Location) address:
        Little Endian: -->  LSB part of data at Lower address & MSB part of data at higher address
        if we need to store 1101 then we store it as

         1 1        0 1
         MSB        LSB
         _______________________________
        | 0   1 (LSB)  |  1   1 (MSB)   |
        |______________|________________|        at using time we use it as 1101 but we store it as like this in memory in little Endian
        lower address     higher address

        Big Endian: --> LSB part of data at Higher address & MSB part of data at lower address
        if we need to store 1101 then we store it as

         1 1        0 1
         MSB        LSB
         _______________________________
        | 1   1 (MSB)  |  0   1 (LSB)   |
        |______________|________________|        at using time we use it as 1101 and we store it also like this in memory in Big Endian
        lower address    higher address


*/

#include <iostream>
using namespace std;
int main()
{
    int a = 321, b; // 321 = 00000001 01000001
    char cha = 'a', chb;
    b = cha; // implicit typecasting
    cout << "int b = " << b << endl;
    chb = (char)a;                        // explicit typecasting
    cout << "char chb = " << chb << endl; // here my system following little Endian method and give output 01000001 which is 'A' .
                                          // If my system following big Endian method for storing memory then it give output (start of Heading) blank.

    short int arr[5] = {300, 301, 302, 303, 304};

    void *ptr;
    ptr = arr;
    cout << "value of 300(000000001 00101100) in character = " << *(char *)ptr << endl; // type casting of generic pointer to character & read 1 Bytes
    cout << "value of 300 in short int = " << *(short int *)ptr << endl;                // type casting of generic pointer to short integer & read 2 Bytes
    cout << "value of 300 in int = " << *(int *)ptr << endl;                            // type casting of generic pointer to integer & read 4 Bytes

    /* Here we have short int array so each element in this array take 2 Bytes Now when we fetch value as integer
    here in above case according to property of integer it read 4 Bytes so it fetch 2 short int blocks of 2 Bytes and
    give us output of 00000001 00101100 00000001 00101101 (300 301)which is equal to 19726636
    */

    cout << "value of 300 in float = " << *(float *)ptr << endl; // type casting of generic pointer to float & read 4 bytes
    return 0;
}