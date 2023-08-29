#include <iostream>
#include <algorithm>

using namespace std;
int k;
int *nums;

// depth는 정하고 있는 곳
// index는 nums의 index
void combination(int *combs, int index, int depth)
{
    if (depth == 6)
    {
        for (int i = 0; i < 6; i++)
            cout << combs[i] << ' ';
        cout << endl;
    }
    else
    {
        for (int i = index; i <= k; i++)
        {
            combs[depth] = nums[i];
            if(6 - depth <= k - i)
                combination(combs, i + 1, depth + 1);
        }
    }
    return;
}

int main(void)
{
    int combs[6];
    while (1)
    {
        cin >> k;
        if (k == 0)
            break;
        nums = new int[k]();
        for (int i = 0; i < k; i++)
            cin >> nums[i];
        combination(combs, 0, 0);
        cout << endl;
    }
    return (0);
}