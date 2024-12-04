/*
    # structure binding
        -> it give us the ability to declare multiple variables initialized from a tuple or strucutre.
        -> Syntex of strucutre binding
            -> auto [identifier-list] = expression


*/

#include <iostream>
using namespace std;

struct mail
{
    int mail_count;
    string owner;
    string address;
    string domain;
};

typedef mail new_mail;

int main()
{
    new_mail m1{1, "xyz", "xyz.dom", "dom"};
    auto [mail_c, owner, addr, domain_name] = m1;

    cout << mail_c << endl;

    return 0;
}