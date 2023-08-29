/*
문제
During the Olympiad finals we usually serve pizza for the contestants. 
When the food arrives, the contestants to queue to get some pizza. 
Each student will be given a single slice of pizza when his/her turn arrives. 
The problem is that 
some people need more than one slice of pizza to be well fed 
so they need to queue again for more pizza after they get the first one.

Given a list of slices needed to fed each of the contestants, 
compute how long it will take to fed all of them. 
We can give a slice of pizza every second and when a contestant is well fed he does not return to the queue.


입력
The first line will contain an integer N. The number of contestants.

The second line will contain N integers separated by spaces. 
The number of slices of pizza needed to feed each contestant.

N <= 1000

The numbers in the sequence will be between 1 and 1000.

Each contestant will need at least 1 and at most 100 slices of pizza.

출력
A line containing N integers separated by spaces. The time in which each of the contestant get all the slices he/she needs.
*/

#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

void wait(int *seconds, int *slices, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (slices[i] != 0)
        {
            seconds[i]++;
        }
    }
}

bool check(int *slices, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (slices[i] != 0)
        {
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    int n;
    cin >> n;
    int *seconds = new int[n]();
    int *slices = new int[n]();
    for (int i = 0; i < n; i++)
        cin >> slices[i];
    int i = 0;
    while(check(slices, n))
    {
        if (i == n)
            i = 0;
        if(slices[i] != 0)
        {
            // cout << i + 1 << ' ';
            slices[i]--;
            wait(seconds, slices, n);
        }
        i++;
    }
    // cout << endl;
    for (int i = 0; i < n; i++)
        cout << seconds[i] + 1 << ' ';
    cout << endl;
    return (0);
}