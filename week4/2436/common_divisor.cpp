/*
어떤 두 자연수에 공통인 약수들 중에서 가장 큰 수를 최대공약수라고 하고,
두 자연수의 공통인 배수들 중에서 가장 작은 수를 최소공배수라고 한다.

예를 들어, 두 자연수 12와 90의 최대공약수는 6이며, 최소공배수는 180이다.

이와 반대로 두 개의 자연수 A, B가 주어졌을 때, A를 최대공약수로, B를 최소공배수로 하는 두 개의 자연수를 구할 수 있다.
그러나, 이러한 두 개의 자연수 쌍은 여러 개 있을 수 있으며, 또한 없을 수도 있다.

예를 들어, 최대공약수가 6이며 최소공배수가 180인 두 정수는
위의 예에서와 같이 12와 90일 수도 있으며, 30과 36, 18과 60, 혹은 6과 180일 수도 있다.
그러나, 최대공약수가 6이며 최소공배수가 20인 두 자연수는 있을 수 없다.

두 개의 자연수가 주어졌을 때, 이 두 수를 최대공약수와 최소공배수로 하는 두 개의 자연수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 두 개의 자연수가 빈칸을 사이에 두고 주어진다. 첫 번째 수는 어떤 두 개의 자연수의 최대공약수이고, 두 번째 수는 그 자연수들의 최소공배수이다. 입력되는 두 자연수는 2 이상 100,000,000 이하이다.

출력
첫째 줄에는 입력되는 두 자연수를 최대공약수와 최소공배수로 하는 두 개의 자연수를 크기가 작은 수부터 하나의 공백을 사이에 두고 출력한다. 입력되는 두 자연수를 최대공약수와 최소공배수로 하는 두 개의 자연수 쌍이 여러 개 있는 경우에는 두 자연수의 합이 최소가 되는 두 수를 출력한다.*/

#include <iostream>
#include <algorithm>
#include <cmath>

typedef long long ll;
using namespace std;
ll common_divisor(ll a, ll b)
{
    if (a < b)
        swap(a, b);
    // a가 큰놈
    ll remainder;
    while (b != 0)
    {
        remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll divisor;
    ll multiple;
    cin >> divisor >> multiple;
    ll ab = multiple / divisor;
    for (ll i = sqrt(ab); i >= 1; i--)
    {
        if (ab % i == 0)
        {
            if (common_divisor(i, ab / i) == 1)
            {
                cout << i * divisor << ' ' << ab / i * divisor << endl;
                return (0);
            }
        }
    }
    return (0);
}