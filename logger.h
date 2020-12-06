#include <iostream>
#include <string>
using namespace std;

// This template allows to print any type to console. 
//
// For example:
// print<string>("text");
// print<int>(1);

template <typename T>
void print(T value)
{
    cout << value << endl;
}

template <typename T1, typename T2>
void print(T1 value1, T2 value2)
{
    cout << value1 << value2 << endl;
}

template <typename T1, typename T2, typename T3>
void print(T1 value1, T2 value2, T3 value3)
{
    cout << value1 << value2 << value3 << endl;
}
