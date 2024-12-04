/*

    * Lambda function :
    -> it allows us to implement inline functions which is not going to be reused and that's why it don't require name.

    * Capture clause
    -> it is used to instruct the compiler to capture the variables visible in scope around where the lambda is declared, either by copy or by reference, to be available for use inside the lambda method body.
        -> [](){} means nothing should be captured.
        -> [=](){} means all variables used in the function's definition should be captured by value.
        -> [&](){} means all variables used in the function's definition should be captured by reference.
        -> [=, &var] means all variables should be captured by copy but variable "var" should be captured by refernece.
        -> [*this] means capture the copy of the current object(capturing by value).
                -> It is important in a scenario where a lambda expression is asynchronously dispatched from a non-static member function.
        -> NOTE : we can also introduce new variable in the capture clause 
                -> eg. [i = int{}](){}


    Syntax of Lambda function :
        [capture clause] (parameters) -> return-type
        {
            definition of method
        }

    eg. auto function = [&](int a) -> int {return a * 4 ;};



    NOTE : To learn how lambda function works, copy the below code and paste it in the [cppinsight website](https://cppinsights.io/)

    for more about lambda function refer https://en.cppreference.com/w/cpp/language/lambda

 */


/* 
    NOTE : we can also overload lambda function in c++17 version.
            -> eg. 

                template<typename... T>
                struct overload : T...{
                    using T::operator()...;
                }

                //deducation guide
                template<typename... T>
                overload(T...)->overload<T>;

                int main(){
                auto func = overload{[](int& v){v = v*2;}, [](int &v, double &b){v = v*2; b = b*2.0;}};
                func(2);
                func(2, 2.3);
                return 0;
                }
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

    const int pass_in_lambda = 28;

    cout << "Print all the values of an array with the use of lambda function : " << endl;

    auto lambda_func = [&pass_in_lambda](int value) mutable
    { cout << " " << value + pass_in_lambda; };

    change_with_lambda(values, lambda_func);
    cout << endl;
    // use of lambda function

    auto x = find_if(values.begin(), values.end(), [](int val)
                     { return val > 3; });

    cout << "First value greater then 3 in given vector is : " << *x << endl;

    return 0;
}