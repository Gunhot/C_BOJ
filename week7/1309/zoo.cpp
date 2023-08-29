#include <iostream>
#include <vector>
using namespace std;

/*
    n : 1
        xx, ox, xo
    n : 2
        xx,             ox,             xo
        xx, xo, ox      xx, xo          xx, ox

    n : 3
        xx,             ox,             xo
        xx, xo, ox      xx, xo          xx, ox
*/
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    int **dp = new int *[n]();
    for (int i = 0; i < n; i++)
        dp[i] = new int[3]();
    dp[0][0] = 1; // xx
    dp[0][1] = 1; // ox
    dp[0][2] = 1; // xo
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % 9901;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % 9901;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % 9901;
    }
    cout << (dp[n - 1][0] + dp[n - 1][1] + dp[n - 1][2]) % 9901;
    return 0;
}