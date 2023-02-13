/* https://www.acmicpc.net/problem/2869 */
#include <stdio.h>

int main(void)
{
    int a, b, v;
    int day;

    scanf("%d %d %d", &a, &b, &v);
    day = (v - b) / (a - b);
    if ((v - b) % (a - b) != 0)
    {
        day++;
    }
    printf("%d\n", day);
    return 0;
}
