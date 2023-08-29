#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[1000];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    //오름차순으로
    sort(a, a + n);
    //가장 마지막 n - 1
    //k번째 높은 애는 n - k
    cout << a[n - k] << '\n';
}