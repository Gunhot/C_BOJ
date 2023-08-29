// 지민이는 N개의 원소를 포함하고 있는 양방향 순환 큐를 가지고 있다. 지민이는 이 큐에서 몇 개의 원소를 뽑아내려고 한다.

// 지민이는 이 큐에서 다음과 같은 3가지 연산을 수행할 수 있다.

// 첫 번째 원소를 뽑아낸다. 이 연산을 수행하면, 원래 큐의 원소가 a1, ..., ak이었던 것이 a2, ..., ak와 같이 된다.
// 왼쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 a2, ..., ak, a1이 된다.
// 오른쪽으로 한 칸 이동시킨다. 이 연산을 수행하면, a1, ..., ak가 ak, a1, ..., ak-1이 된다.
// 큐에 처음에 포함되어 있던 수 N이 주어진다. 그리고 지민이가 뽑아내려고 하는 원소의 위치가 주어진다. (이 위치는 가장 처음 큐에서의 위치이다.) 이때, 그 원소를 주어진 순서대로 뽑아내는데 드는 2번, 3번 연산의 최솟값을 출력하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 큐의 크기 N과 뽑아내려고 하는 수의 개수 M이 주어진다. N은 50보다 작거나 같은 자연수이고, M은 N보다 작거나 같은 자연수이다. 둘째 줄에는 지민이가 뽑아내려고 하는 수의 위치가 순서대로 주어진다. 위치는 1보다 크거나 같고, N보다 작거나 같은 자연수이다.

// 출력
// 첫째 줄에 문제의 정답을 출력한다.
/*
10 3
1 2 3
-------
1 2 3
1 2
3
*/
/*
10 3
2 9 5
1 8 4 V
7 3
8 4 V
9 5 V
10 7 V
7
8 V
9 V
10 V
1 V

*/
#include <iostream>
#include <deque>
using namespace std;

class RotatingQueue
{
private:
    deque<int> dq;
    int target_num;
    int queue_size;
    int result;

public:
    RotatingQueue(int n)
    {
        queue_size = n;
        target_num = 0;
        result = 0;
    }
    void insert(int temp)
    {
        target_num++;
        dq.push_back(temp);
    }
    void print_dq()
    {
        for (int i = 0; i < target_num; i++)
            cout << dq.at(i) << ' ';
        cout << endl;
    }
    void print_result()
    {
        cout << result << endl;
    }
    int get_queue_size()
    {
        return queue_size;
    }
    int get_target_num()
    {
        return target_num;
    }
    int get_first()
    {
        return dq.front();
    }

    /*아래 세개가 기능*/
    void moveLeft()
    {
        for (int i = 0; i < target_num; i++)
        {
            if(dq.at(i) == 1)
                dq.at(i) = queue_size;
            else
                dq.at(i)--;
        }
        result++;
    }
    void moveRight()
    {
        for (int i = 0; i < target_num; i++)
        {
            if(dq.at(i) == queue_size)
                dq.at(i) = 1;
            else
                dq.at(i)++;
        }
        result++;
    }
    void firstOut()
    {
        for (int i = 0; i < target_num; i++)
            dq.at(i)--;
        dq.pop_front();
        target_num--;
        queue_size--;
    }
};

int main(void)
{
    int n, m;
    cin >> n >> m;
    RotatingQueue rq(n);
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        rq.insert(temp);
    }
    while (rq.get_target_num() != 0)
    {
        int leftD = abs(rq.get_first() - 1);
        int rightD = abs(rq.get_first() - rq.get_queue_size()) + 1;
        if (leftD < rightD)
            for (int i = 0; i < leftD; i++)
                rq.moveLeft();
        else
            for (int i = 0; i < rightD; i++)
                rq.moveRight();
        rq.firstOut();
    }
    rq.print_result();
    return (0);
}