// 크기가 N인 수열 A = A1, A2, ..., AN이 있다. 수열의 각 원소 Ai에 대해서 오등큰수 NGF(i)를 구하려고 한다.

// Ai가 수열 A에서 등장한 횟수를 F(Ai)라고 했을 때,
// 예를 들어, A = [1, 1, 2, 3, 4, 2, 1]인 경우 F(1) = 3, F(2) = 2, F(3) = 1, F(4) = 1이다.
// Ai의 오등큰수는 오른쪽에 있으면서 수열 A에서 등장한 횟수가 F(Ai)보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다.
// 그러한 수가 없는 경우에 오등큰수는 -1이다.
// A1의 오른쪽에 있으면서 등장한 횟수가 3보다 큰 수는 없기 때문에, NGF(1) = -1이다.
// A3의 경우에는 A7이 오른쪽에 있으면서 F(A3=2) < F(A7=1) 이기 때문에, NGF(3) = 1이다. NGF(4) = 2, NGF(5) = 2, NGF(6) = 1 이다.

// 입력
// 첫째 줄에 수열 A의 크기 N (1 ≤ N ≤ 1,000,000)이 주어진다. 둘째에 수열 A의 원소 A1, A2, ..., AN (1 ≤ Ai ≤ 1,000,000)이 주어진다.

// 출력
// 총 N개의 수 NGF(1), NGF(2), ..., NGF(N)을 공백으로 구분해 출력한다.

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

int main(void)
{
    cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
    int n;
    cin >> n;
    int *input = new int[n]();
    for (int i = 0; i < n; i++)
        cin >> input[i];
    int maxInput = *max_element(input, input + n);
    int *F = new int[maxInput + 1](); // 값!
    for (int i = 0; i < n; i++)
        F[input[i]]++;
    /*
    INPUT : 1 1 2 3 4 2 1
    F     : 3 3 2 1 1 2 3
    NGF   : X X 3 2 2 3 X <- F
    NGF   : X X 1 2 2 1 X <- INPUT
    */
    int *NGF = new int[n](); // 자리!
    stack<int> possibleF;
    for (int i = n - 1; i >= 0; i--)
    {
        // 나
        int myInput = input[i];
        int myF = F[myInput];
        // 현재 나보다 낮은 애들 싹다 뽑아
        while (!possibleF.empty())
        {
            int topInput = input[possibleF.top()];
            int topF = F[topInput];
            if (myF >= topF)
                possibleF.pop();
            else 
                break;
        }
        // 큰놈 없다면 비었겠지
        if(possibleF.empty())
            NGF[i] = -1;
        else
            NGF[i] = input[possibleF.top()];
        possibleF.push(i);
    }

    for (int i = 0; i < n; i++)
        cout << NGF[i] << ' ';
    cout << endl;
    return (0);
}