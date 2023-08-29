#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int cal_diff(char *a, char *b)
{
    int diff = 0;
    int a_len = strlen(a);
    for (int i = 0; i < a_len; i++)
    {
        if (a[i] != b[i])
            diff++;
    }
    return diff;
}

int main(void)
{
    char src[50];
    char dest[50];
    cin >> src >> dest;
    int s_len = strlen(src);
    int d_len = strlen(dest);
    int m = INT_MAX;
    for (int i = 0; i <= d_len - s_len; i++)
        m = min(m, cal_diff(src, dest + i));
    cout << m << endl;
    return (0);
}