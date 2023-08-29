
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;

void press(string &cur, int i)
{
    // 나
    if (cur[i] == '1')
        cur[i] = '0';
    else
        cur[i] = '1';
    // 앞
    if (i - 1 >= 0)
        if (cur[i - 1] == '1')
            cur[i - 1] = '0';
        else
            cur[i - 1] = '1';
    // 뒤
    if (i + 1 <= n - 1)
        if (cur[i + 1] == '1')
            cur[i + 1] = '0';
        else
            cur[i + 1] = '1';
}


int cal(string cur, string tar)
{
    // idea : i - 1만 바라보자 (Greedy)
    int cnt = 0;
    for (int i = 1; i < n; i++)
    {
        // i - 1이 다르면 i를 눌러서 바꾼다.
        if (cur[i - 1] != tar[i - 1])
        {
            press(cur, i);
            cnt++;
        }
    }
    // 끝까지 다 왔는데 다르다면 -> 답 없음
    if (cur.compare(tar) == 0)
        return (cnt);
    else
        return (-1);
}

void answer(int first, int second)
{
    if (first == -1 && second == -1)
        cout << -1;
    else if(first == -1 && second != -1)
        cout << second + 1;
    else if(first != -1 && second == -1)
        cout << first;
    else
        cout << min(first, second + 1);
}

int main(void)
{
    cin >> n;
    string cur, tar;
    cin >> cur;
    cin >> tar;
    int first;
    first = cal(cur, tar);
    //안됐다고 안심하긴 이름
    int second;
    //처음에 누르고 시작해도 가능한 경우가 있음
    press(cur, 0);
    second = cal(cur, tar);
    answer(first, second);
    return (0);
}