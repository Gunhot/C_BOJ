#include <iostream>
#include <vector>
using namespace std;

void print_table(string a, string b, int **table)
{
    cout << endl;
    cout << ' ' << a << endl;
    for (int i = 0; i < b.length(); i++)
    {
        cout << b[i];
        for (int j = 0; j < a.length(); j++)
        {
            if (table[i][j])
                cout << table[i][j];
            else
                cout << ' ';
        }
        cout << endl;
    }
}

int **build_table(string a, string b)
{
    int **table = new int *[b.length()]();
    for (int i = 0; i < b.length(); i++)
        table[i] = new int[a.length()]();
    return table;
}

int cal(string a, string b)
{
    int ans = 0;
    int **table = build_table(a, b);
    for (int i = 0; i < b.length(); i++)
    {
        for (int j = 0; j < a.length(); j++)
        {
            if (b[i] == a[j])
            {
                table[i][j] = 1;
                if (i >= 1 && j >= 1)
                {
                    table[i - 1][j - 1] >= 1;
                    table[i][j] = table[i - 1][j - 1] + 1;
                    ans = max(ans, table[i][j]);
                }
            }
        }
        print_table(a, b, table);
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string a;
    string b;
    cin >> a;
    cin >> b;
    cout << cal(a, b);

    return 0;
}