#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> emp;
int check(int i, int j, int test, int sudoku[9][9])
{
    for (int k = 0; k < 9; k++)
    {
        // 가로비교
        if (k == j)
            continue;
        if (sudoku[i][k] == test)
            return false;
    }
    for (int k = 0; k < 9; k++)
    {
        // 세로비교
        if (k == i)
            continue;
        if (sudoku[k][j] == test)
            return false;
    }
    // 박스 검사중
    int a = (int)(i / 3) * 3;
    int b = (int)(j / 3) * 3;
    for (int k = a; k < a + 3; k++)
    {
        for (int l = b; l < b + 3; l++)
        {
            if (k != i && l != j)
            {
                if (sudoku[k][l] == test)
                    return false;
            }
        }
    }
    return true;
}

void print_sudo(int sudoku[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j];
            if (j != 8)
                cout << ' ';
        }
        cout << endl;
    }
}
// index에서 찾는 중
void sudo(int sudoku[9][9], int index)
{
    // print_sudo(sudoku);
    if (index == emp.size())
    {
        print_sudo(sudoku);
        exit(0);
    }
    for (int i = 1; i <= 9; i++)
    {
        if (check(emp[index].first, emp[index].second, i, sudoku))
        {
            sudoku[emp[index].first][emp[index].second] = i;
            sudo(sudoku, index + 1);
        }
    }
    //틀리면 다시 초기화 해줘야함
    sudoku[emp[index].first][emp[index].second] = 0;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int sudoku[9][9];
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
            if (sudoku[i][j] == 0)
                emp.push_back(make_pair(i, j));
        }
    sudo(sudoku, 0);
    return (0);
}