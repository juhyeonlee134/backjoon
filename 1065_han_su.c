/* https://www.acmicpc.net/problem/1065 */
#include <stdio.h>

int is_han(int n);

int main(void)
{
    int input;
    int idx;
    int cnt = 0;

    scanf("%d", &input);
    for (idx = 1; idx <= input; idx++)
    {
        if (is_han(idx))
        {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

int is_han(int n)
{
    int digit[4] = {0, };
    int idx = 0;
    int diff;

    if (n < 10)
    {
        return 1;
    }
    while (n > 0)
    {
        digit[idx] = n % 10;
        n /= 10;
        idx++;
    }
    diff = digit[0] - digit[1];
    idx--;
    while (idx >= 1)
    {
        if (digit[idx] + diff != digit[idx - 1])
        {
            return 0;
        }
        idx--;
    }
    return 1;
}
