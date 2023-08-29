#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int a, b;
    cin >> a >> b;
    // 유클리드 호제법
    if (b > a)
        swap(a, b);
    int dev;
    int remainder;
    while (1)
    {
        dev = a / b;
        remainder = a % b;
        // cout << a << ' ' << b << ' ' << dev << ' ' << remainder << endl;
        if (remainder == 0)
            break;
        a = b;
        b = remainder;
    }
    cout << b;
    return (0);
}
