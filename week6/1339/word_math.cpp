// #include <iostream>
// #include <string>
// #include <algorithm>

// using namespace std;

// int index(char c)
// {
//     return (c - 'A');
// }

// int change_to_num(string s, int *code)
// {
//     int sLen = s.length();
//     int num = 0;
//     for (int i = 0; i < sLen; i++)
//     {
//         num *= 10;
//         num += code[index(s[i])];
//     }
//     return (num);
// }

// void insertion_sort_string(string *s, int n)
// {
//     int i, j;
//     for (i = 1; i < n; i++)
//     {
//         string tmp = s[i];
//         for (j = i - 1; j >= 0; j--)
//         {
//             if (s[j].length() < tmp.length())
//                 s[j + 1] = s[j];
//             else
//                 break;
//         }
//         s[j + 1] = tmp;
//     }
// }

// void make_code(int *code, string *s, int n)
// {
//     insertion_sort_string(s, n);
//     int total_len = s[0].length();
//     int num = 9;
//     for (int total_idx = 0; total_idx < total_len; total_idx++)
//     {
//         // 할당 시작
//         for (int i = 0; i < n; i++)
//         {
//             int s_len = s[i].length();
//             if (total_idx >= total_len - s_len)
//             {
//                 int s_idx = total_idx - (total_len - s_len);
//                 int idx = index(s[i][s_idx]);
//                 if (code[idx] == 0)
//                     code[idx] = num--;
//             }
//         }
//     }
// }

// /*
// 5
// AB 98
// BC 87
// CD 76
// DE 65
// EF 54
// */

// int cal(int *code, string *s, int n)
// {
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//         sum += change_to_num(s[i], code);
//     return (sum);
// }

// int main(void)
// {
//     int n;
//     int code[26] = {
//         0,
//     };
//     string *s;
//     cin >> n;
//     s = new string[n]();
//     for (int i = 0; i < n; i++)
//         cin >> s[i];
//     // 알고리즘~
//     make_code(code, s, n);
//     // 입력 완료
//     cout << cal(code, s, n);
//     return (0);
// }

// 아까워서 못지우겠다

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void make_code(int *code, int *alph_cnt)
{
    int n = 9;
    while (!all_of(alph_cnt, alph_cnt + 26, [](int x)
                   { return x == 0; }))
    {
        int *maxElement = max_element(alph_cnt, alph_cnt + 26);
        int maxIndex = distance(alph_cnt, maxElement);
        code[maxIndex] = n--;
        alph_cnt[maxIndex] = 0;
    }
}

int change_to_num(string s, int *code)
{
    int sLen = s.length();
    int num = 0;
    for (int i = 0; i < sLen; i++)
    {
        num *= 10;
        num += code[s[i] - 'A'];
    }
    return (num);
}

int cal(string *s, int *code, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += change_to_num(s[i], code);
    return (sum);
}

int main(void)
{
    int alph_value[26] = {
        0,
    };
    int n;
    cin >> n;
    string *s = new string[n]();
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        int slen = s[i].length();
        for (int j = 0; j < slen; j++)
        {
            int digit = 1;
            int times = slen - j;
            for (int k = 1; k < times; k++)
                digit *= 10;
            alph_value[s[i][j] - 'A'] += digit;
        }
    }
    int code[26] = {
        0,
    };
    make_code(code, alph_value);
    cout << cal(s, code, n);

    
    return (0);
}