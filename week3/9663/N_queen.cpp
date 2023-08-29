#include <iostream>
#include <algorithm>
using namespace std;
int n;
int ans;

// index는 정하고 있는 곳
int check(int *a, int index, int test)
{
    for (int i = 0; i < index; i++)
    {
            //가로에 있다라고 판단할 수 있다
        if (a[i] == test)
            return false;
            //기울기를 판단한 것 -> 대각선에 있다.
        if (abs(a[i] - test) == abs(i - index))
            return false;
    }
    return true;
}

// cur까지 정했다.
// a가 원래는 stack에만 존재해야하는데 cur 덕분에 상관이 없다.
void n_queen(int *a, int cur)
{
    if (cur == n - 1)
    {
        ans++;
        //성공했을 때
        return;
    }
    int test = a[cur] + 1;
    // a[cur]이 0또는 n - 1일 수 있으므로 a[cur -1] X, a[cur + 1] X
    // 탈출조건 한 바퀴 다 돌았을 때
    // 3 -> 4X 5O
    while (test != a[cur])
    {
        //5O
        test++;
        if (test >= n)
            test = 0;
        //해당 인덱스에서 골랐을 때
        if (check(a, cur + 1, test) == true)
        {
            a[cur + 1] = test;
            n_queen(a, cur + 1);
        }
    }
    //실패했을 때
    return;
}

int main(void)
{
    cin >> n;
    // 0으로 초기화
    int *a = new int[n]();
    for (int i = 0; i < n; i++)
    {
        a[0] = i;
        n_queen(a, 0);
    }
    cout << ans << endl;
    return (0);
}
n : 4
_ _ _ _
0 
1
2
3