#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


int main(void)
{
    int n;
    cin >> n;
    int *nums = new int[n]();
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sort(nums, nums + n);
    // 준비완료
    if (nums[0] != 1)
        cout << 1;
    else
    {
        // 1~result 무게를 모두 만들 수 있을 때
        int possible = nums[0];
        // result : 1
        for (int i = 1; i < n; i++)
        {
            // 다음 저울추(nums[i])가 result보다 같거나 작다면
            if (nums[i] <= (possible + 1))
            // 다음 저울추로 (1+L)~(K+L)무게 측정 가능 => 1~(K+L)무게를 모두 만들 수 있는 것
                possible += nums[i];
            // 다음 저울추(nums[i])가 result보다 크다면
            // result와 nums[i]사이에 있는 값들은 측정할 수가 없다~
            else
                break;
        }
        cout << possible + 1;
    }
    return (0);
}