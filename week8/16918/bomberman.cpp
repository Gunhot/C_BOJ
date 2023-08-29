#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int **read_map(int r, int c)
{
    char temp;
    int **map = new int *[r]();
    for (int i = 0; i < r; i++)
        map[i] = new int[c]();
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            cin >> temp;
            if (temp == '.')
                map[i][j] = 0;
            else if (temp == 'O')
                map[i][j] = 3;
        }
    return map;
}

void print(int **map, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}

void first(int **map, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] > 0)
                map[i][j]--;
        }
    }
}

void second(int **map, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] == 0)
                map[i][j] = 3;
        }
    }
}

void third(int **map, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] == 0)
                map[i][j] = 3;
        }
    }
}

void second(int **map, int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] == 0)
                map[i][j] = 3;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int r, c;
    int n;
    cin >> r >> c >> n;
    int **map = read_map(r, c);
    print(map, r, c);
    // 1초 보내기
    first(map, r, c);
    // 싹다 설치하기
    second(map, r, c);
    while (true)
    {
        // 3초 보내기
        third(map, r, c);
        // 터트리기
        firth(map, r, c);
    }

    return 0;
}