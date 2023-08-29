#include <stdio.h>
#include <string.h>
#define SIZE 1000000
char stack[SIZE];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    if(top == -1)
        return (0);
    return stack[top--];
}

int check(char *str)
{
    int len = strlen(str);
    int i;

    for (i = 0; i < len; i++)
    {
        if (str[i] == '(')
        {
            push('(');
        }
        else if(str[i] == ')')
        {
            if(pop() == 0)
            {
                return (0);
            }
        }
    }
    if(top != -1)
    {
        while(top != -1)
            pop();
        return (0);
    }
    return(1);
}

int main(void)
{
    char str[100];
    int n;
    int i;

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf(" %s", str);
        if(check(str))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return (0);
}