#include <iostream>
#include <algorithm>
using namespace std;

int l, c;
char *input;
int final_check(int *a)
{
    int vowel_count = 0;
    for (int i = 0; i < l; i++)
    {
        if (input[a[i]] == 'a' || input[a[i]] == 'e' || input[a[i]] == 'i' || input[a[i]] == 'o' || input[a[i]] == 'u' )
            vowel_count++;
    }
    if (vowel_count >= 1 && l - vowel_count >= 2)
        return true;
    else 
        return false;
}

//cur까지 정했다.
void password_creation(int *a, int cur)
{
    if (cur == l - 1)
    {
        if(final_check(a) == true)
        {
            for (int i = 0; i < l; i++)
                cout << input[a[i]];
            cout << endl;
        }
        //베이스케이스
        return ;
    }
    char test = a[cur] + 1;
    while (test < c)
    {
        a[cur + 1] = test;
        password_creation(a, cur + 1);
        test++;
    }
}

int main(void)
{
    scanf("%d %d\n", &l, &c);
    input = new char[c];
    for (int i = 0; i < c; i++)
        cin >> input[i];
    //input : a b c d e i o u
    //a[0] = input[0]
    //a[0] = a
    sort(input, input + c);
    int *a = new int[l]();
    for (int i = 0; i < c; i++)
    {
        a[0] = i;
        password_creation(a, 0);
    }

    return (0);
}