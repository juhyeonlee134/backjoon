/* https://www.acmicpc.net/problem/4673 */
#include <stdio.h>
#define ARR_SIZE 10000

int get_d(int n);

int main(void)
{
    int arr[ARR_SIZE] = {0, };
    int idx;
    int n;

    for (idx = 1; idx < ARR_SIZE; idx++)
    {
        n = idx + get_d(idx);
        while (n < ARR_SIZE && arr[n] == 0)
        {
            arr[n] = 1;
            n = n + get_d(n);
        }
    }
    for (idx = 1; idx < ARR_SIZE; idx++)
    {
        if (arr[idx] == 0)
        {
            printf("%d\n", idx);
        }
    }
    return 0;
}

int get_d(int n)
{
    if (n < 10)
    {
        return n;
    }
    return get_d(n / 10) + get_d(n % 10);
}
