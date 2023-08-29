#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

int find_parent(int x, int *parent)
{
    if(parent[x] == x)
        return x;
    else
        return parent[x] = find_parent(parent[x], parent);
}

bool Union(int a, int b, int *parent)
{
    a = find_parent(a, parent);
    b = find_parent(b, parent);

    if (a != b)
    {
        parent[b] = a;
        return true;
    }
    else
        return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<tuple<int, int, int>> graph;
    for (int i = 0; i < k; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph.push_back(make_tuple(weight, from, to));
    }
    sort(graph.begin(), graph.end());

    int *parent = new int[n + 1]();
    for (int i = 0; i < n + 1; i++)
        parent[i] = i;
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        int weight = get<0>(graph[i]);
        int from = get<1>(graph[i]);
        int to = get<2>(graph[i]);
        if(Union(from, to, parent))
            ans += weight;
    }
    cout << ans << endl;
    return 0;
}