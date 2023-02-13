/* https://www.acmicpc.net/problem/1193 */
#include <stdio.h>

void set_frac(int* n, int* m, int input);
int get_scope(int n);

int main(void)
{
    int input, mol, den;
    int scope = 0;

    scanf("%d", &input);
    scope = get_scope(input);
    input = input - scope * (scope - 1) / 2;
    if (scope % 2 == 0)
    {
        mol = 1;
        den = scope;
        set_frac(&mol, &den, input);
    }
    else
    {
        mol = scope;
        den = 1;
        set_frac(&den, &mol, input);
    }
    printf("%d/%d\n", mol, den);
    return 0;
}

void set_frac(int* n, int* m, int input)
{
    while (input > 1)
    {
        (*n)++;
        (*m)--;
        input--;
    }
}

int get_scope(int n)
{
    int idx = 1;
    
    while (n > idx * (idx + 1) / 2)
    {
        idx++;
    }
    return (idx);
}
