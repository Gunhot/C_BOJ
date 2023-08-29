#include <iostream>

using namespace std;

int main()
{
    int b = 12;
    int sum = 0;
    int arr = 1;
    while (b > 0)
    {
        cout << "b : " << b << endl;
        cout << "sum : " << sum << endl;
        cout << "arr : " << arr << endl;
        if (b % 2 == 1)
            sum = arr;
        arr *= 2;
        b /= 2;
        cout << "-> b : " << b << endl;
        cout << "-> sum : " << sum << endl;
        cout << "-> arr : " << arr << endl;
    }
    return (0);
}