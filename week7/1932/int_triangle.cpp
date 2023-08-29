#include <iostream>
#include <vector>
using namespace std;

int **build_triangle(int height)
{
    int **triangle = new int *[height]();
    for (int i = 0; i < height; i++)
        triangle[i] = new int[height * 2 - 1]();
    return triangle;
}

void read(int **triangle, int height)
{
    int row = height;
    int col = 2 * height - 1;
    for (int i = 0; i < row; i++)
    {
        int gap = height - 1 - i;
        for (int j = gap; j < col - gap; j += 2)
        {
            cin >> triangle[i][j];
        }
    }
}

void print(int **triangle, int height)
{
    int row = height;
    int col = 2 * height - 1;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << triangle[i][j];
        }
        cout << endl;
    }
}

int **build_table(int height)
{
    int **table = new int *[height]();
    for (int i = 0; i < height; i++)
        table[i] = new int[height * 2 - 1]();
    return table;
}

int cal(int **triangle, int height)
{
    int row = height;
    int col = 2 * height - 1;
    int **table = build_table(height);
    print(triangle, height);
    print(table,height);
    int ans = 0;
    for (int i = 0; i < row; i++)
    {
        int gap = height - 1 - i;
        for (int j = 0; j < col; j++)
        {
            table[i][j] = triangle[i][j];
            if (i >= 1 && j >= 1)
                table[i][j] = max(table[i - 1][j - 1] + triangle[i][j], table[i][j]);
            if (i >= 1 && j <= col - 1)
                table[i][j] = max(table[i - 1][j + 1] + triangle[i][j], table[i][j]);
            ans = max(ans, table[i][j]);
        }
        print(table, height);
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int height;
    cin >> height;
    int **triangle = build_triangle(height);
    read(triangle, height);
    // print(triangle, height);
    int ans = cal(triangle, height);
    cout << ans;
    return 0;
}