#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    long long a, b;
    cin >> a >> b;
    // 유클리드 호제법
    if (a < b)
        swap(a, b);
    // a가 큰놈
    long long remainder;
    while (b != 0)
    {
        remainder = a % b;
        a = b;
        b = remainder;
    }
    for (long long i = 0; i < a; i++)
    {
        cout << "1";
    }
    return (0);
}