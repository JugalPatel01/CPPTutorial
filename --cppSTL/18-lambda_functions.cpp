/*

    * Lambda function :
    -> it allows us to implement inline functions which is not going to be reused and that's why it don't require name.

    syntax:
        [capture clause] (parameters) -> return-type
        {
            definition of method
        }

    for more about lambda function refer https://en.cppreference.com/w/cpp/language/lambda

 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void change_with_lambda(const vector<int> &values, const function<void(int)> &func)
{
    for (int value : values)
    {
        func(value);
    }
}

int main()
{
    vector<int> values = {1, 2, 3, 5, 6};

    int pass_in_lambda = 28;

    cout << "print all the values of an array with the use of lambda function : " << endl;

    auto lambda_func = [&pass_in_lambda](int value)
    { cout << " " << value + pass_in_lambda; };

    change_with_lambda(values, lambda_func);
    cout << endl;
    // use of lambda function

    auto x = find_if(values.begin(), values.end(), [](int val)
                     { return val > 3; });

    cout << "first value greater then 3 in given vector is : " << *x << endl;

    return 0;
}