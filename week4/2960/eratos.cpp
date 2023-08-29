#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)
{
    int n, k;
    cin >> n >> k;
    bool *erased = new bool[n + 1]();
    int count = 0;
    for (int i = 2; i <= n; i++)
    {
        if (erased[i] == false)
        {
            for (int j = i; j <= n; j += i)
            {
                if (erased[j] == false)
                {
                    erased[j] = true;
                    count++;
                    if (count == k)
                    {
                        cout << j;
                        return (0);
                    }
                }
            }
        }
    }
    return (0);
}