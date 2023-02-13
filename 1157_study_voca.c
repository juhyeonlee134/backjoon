/* https://www.acmicpc.net/problem/1157 */
#include <stdio.h>
#define BUFF_SIZE 1000000

int main(void)
{
	char buff[BUFF_SIZE];
	int alpha[26] = {0, };
	int max = 0;
	int m_idx = -1;
	size_t idx;

	scanf("%s", buff);
	idx = 0;
	while (buff[idx])
	{
		buff[idx] |= 32;
		alpha[buff[idx] - 'a']++;
		idx++;
	}
	for (idx = 0; idx < 26; idx++)
	{
		if (max < alpha[idx])
		{
			max = alpha[idx];
			m_idx = idx;
		}
		else if(max == alpha[idx])
		{
			m_idx = -1;
		}
	}
	putchar(m_idx == -1 ? '?' : m_idx + 'A');
	putchar('\n');
	return 0;
}
