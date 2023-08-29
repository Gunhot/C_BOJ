#include <iostream>
#include <vector>
#include <queue>

using namespace std;
bool *find_prime()
{
    bool *is_prime = new bool[10000]();
    for (int i = 0; i < 10000; i++)
        is_prime[i] = true;
    // 왜 제곱근까지만 하더라
    for (int i = 2; i <= 100; i++)
    {
        if (is_prime[i] == true)
        {
            for (int j = i + i; j < 10000; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int arr_to_num(int *arr)
{
    int sum = 0;
    sum += 1000 * arr[0];
    sum += 100 * arr[1];
    sum += 10 * arr[2];
    sum += arr[3];
    return sum;
}

int *num_to_arr(int n)
{
    int *arr = new int[4]();
    arr[0] = n / 1000;
    arr[1] = (n / 100) % 10;
    arr[2] = (n / 10) % 10;
    arr[3] = n % 10;
    return arr;
}

int bfs(bool *is_prime, int from, int to)
{
    int cnt[10000];
    for (int i = 0; i < 10000; i++)
        cnt[i] = -1;
    queue<int> q;
    q.push(from);
    cnt[from] = 0;

    while (!q.empty())
    {
        int cur_num = q.front();
        q.pop();
        if (cur_num == to)
            return cnt[cur_num];
        for (int i = 0; i < 4; i++)
        {
            int *cur_arr = num_to_arr(cur_num);
            for (int j = 0; j < 10; j++)
            {
                if (i == 0 && j == 0)
                    continue;
                cur_arr[i] = j;
                int new_num = arr_to_num(cur_arr);
                if (is_prime[new_num] == true)
                {
                    if (cnt[new_num] == -1)
                    {
                        q.push(new_num);
                        cnt[new_num] = cnt[cur_num] + 1;
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    int from, to;
    bool *is_prime = find_prime();
    for (int i = 0; i < t; i++)
    {
        cin >> from >> to;
        int result = bfs(is_prime, from, to);
        if (result == -1)
            cout << "Impossible" << endl;
        else
            cout << result << endl;
    }

    return 0;
}