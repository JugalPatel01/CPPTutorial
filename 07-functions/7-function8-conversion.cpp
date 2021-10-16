//octal to decimal
//hexadecimal to decimal
//Decimal to binary
//Decimal to ocatal
//Decimal to hexadecimal
#include <bits/stdc++.h>
using namespace std;
int binaryToDecimal(int n)
{
    int ans = 0;
    int x = 1;
    while (n > 0)
    {
        int y = n % 10;
        ans += x * y;
        x *= 2;
        n /= 10;
    }
    return ans;
}
int octalToDecimal(int n)
{
    int ans = 0;
    int x = 1;
    while (n > 0)
    {
        int y = n % 10;
        ans += x * y;
        x *= 8;
        n /= 10;
    }
    return ans;
}
int hexadecimalToDecimal(string n)
{
    int ans = 0;
    int x = 1;
    int s = n.size();

    for (int i = s - 1; i >= 0; i--)
    {
        if (n[i] >= '0' && n[i] <= '9')
        {
            ans += x * (n[i] - '0');
        }
        else if (n[i] >= 'A' && n[i] <= 'F')
        {
            ans += x * (n[i] - 'A' + 10);
        }
        x *= 16;
    }
    return ans;
}
int decimalToBinary(int n)
{
    int ans = 0;
    int x = 1;
    while (x < n)
    {
        x = x * 2;
    }
    while (x > 0)
    {
        int lastdigit = n / x;
        ans = ans * 10 + lastdigit;
        n = n - (lastdigit * x);
        x = x / 2;
    }
    return ans;
}
int decimalToOctal(int n)
{
    int ans = 0;
    int x = 1;
    while (x < n)
    {
        x *= 8;
    }

    while (x > 0)
    {
        int lastdigit = n / x;
        ans = ans * 10 + lastdigit;
        n = n - (lastdigit * x);
        x = x / 8;
    }
    return ans;
}
string decimalToHexadecimal(int n)
{
    int x = 1;
    string ans = "";
    while (x < n)
    {
        x *= 16;
    }

    while (x > 0)
    {
        int lastdigit = n / x;
        n = n - (lastdigit * x);
        x = x / 16;
        if (lastdigit <= 9)
        {
            ans = ans + to_string(lastdigit);
        }
        else
        {
            char c = 'A' - 10 + lastdigit;
            ans.push_back(c);
        }
    }

    return ans;
}
int main()
{
    int a;
    string n;
    cout << "1).Binary to Decimal" << endl;
    cout << "2).Octal to Decimal" << endl;
    cout << "3).Hexadecimal to Decimal" << endl;
    cout << "4).Decimal to binary" << endl;
    cout << "5).Decimal to Octal" << endl;
    cout << "6).Decimal to Hexadecimal" << endl;
    cout << "enter your choise ";
    cin >> a;
    cout << "Enter the number for conversion: ";
    cin >> n;
    switch (a)
    {
    case 1:

        cout << binaryToDecimal(stoi(n)) << endl;
        break;
    case 2:

        cout << octalToDecimal(stoi(n)) << endl;
        break;
    case 3:

        cout << hexadecimalToDecimal(n) << endl;
        break;
    case 4:

        cout << decimalToBinary(stoi(n)) << endl;
        break;
    case 5:

        cout << decimalToOctal(stoi(n)) << endl;
        break;
    case 6:

        cout << decimalToHexadecimal(stoi(n)) << endl;
        break;

    default:
        cout << "enter again  ";
        break;
    }

    return 0;
}