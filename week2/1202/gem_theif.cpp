#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int main()
{
    int n = 0;
    int k = 0;
    pair<int, int> gem[300000]; // 무게, 가격
    int bag[300000];            // 무게
    priority_queue<int, vector<int>> pq;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> gem[i].first >> gem[i].second;
    for (int i = 0; i < k; i++)
        cin >> bag[i];
    // 작은놈에 들어간다면 큰놈에도 들어갈 수 있게
    sort(bag, bag + k);
    sort(gem, gem + n);
    long long sum = 0;
    int j = 0;
    for (int i = 0; i < k; i++)
    {
        while (j < n && gem[j].first <= bag[i])
        {
            pq.push(gem[j].second);
            j++;
        }
        if (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum;
    return (0);
}
