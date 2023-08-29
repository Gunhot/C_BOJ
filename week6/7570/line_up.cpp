#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

deque<int> dq;
int n;

void go_front(int i)
{
    int temp = dq.at(i);
    dq.erase(dq.begin() + i);
    dq.push_front(temp);
}

void go_back(int i)
{
    int temp = dq.at(i);
    dq.erase(dq.begin() + i);
    dq.push_back(temp);
}

int consecutive_count[1000001];

int main(void)
{
    cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     int temp;
    //     cin >> temp;
    //     dq.push_back(temp);
    // }

    //ㅈㄴ 어려웠는데
    //겁나 간단하게 풀더라
    //idea : 연속된 수는 움직일 필요가 없다.    
    int x;
    int max_consecutive_count = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		consecutive_count[x] = consecutive_count[x - 1] + 1;
		max_consecutive_count = max(max_consecutive_count, consecutive_count[x]);
	}
    cout << n - max_consecutive_count;

    return (0);
}