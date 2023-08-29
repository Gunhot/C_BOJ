#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[9];
    for (int i = 0; i < 9; i++)
        cin >> a[i];
    sort(a, a + 9);
    int sum = 0;
    for (int i = 0; i < 9; i++)
        sum += a[i];
    int remain = sum - 100;
    int i, j;

    for (i = 0; i < 8; i++)
        for (j = i + 1; j < 9; j++)
            if (a[i] + a[j] == remain)
            {
                for (int k = 0; k < 9; k++)
                    if (k != i && k != j)
                        cout << a[k] << '\n';
                return (0);
            }
}