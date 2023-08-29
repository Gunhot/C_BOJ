#include <iostream>
#include <algorithm>

using namespace std;

void multi(long long a[5][5], long long b[5][5], long long n)
{
    long long sum[5][5] = {
        0,
    };
    for (long long i = 0; i < n; i++)
        for (long long j = 0; j < n; j++)
        {
            for (long long k = 0; k < n; k++)
                sum[i][j] += a[i][k] * b[k][j];
            sum[i][j] = sum[i][j] % 1000;
        }
    copy(&sum[0][0], &sum[0][0] + 25, &a[0][0]);
}

int main()
{
    long long n, b;
    cin >> n >> b;
    long long arr[5][5] = {
        0,
    };
    long long sum[5][5] = {
        0,
    };
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < n; j++)
            cin >> arr[i][j];
        sum[i][i] = 1;
    }

    while (b > 0)
    {
        if (b % 2 == 1)
            multi(sum, arr, n);
        multi(arr, arr, n);
        b /= 2;
    }

    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < n; j++)
        {
            cout << sum[i][j];
            if (j == n - 1)
                cout << '\n';
            else
                cout << ' ';
        }
    }

    return (0);
}
