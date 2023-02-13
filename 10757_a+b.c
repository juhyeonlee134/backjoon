/* https://www.acmicpc.net/problem/10757 */
#include <stdio.h>
#include <string.h>
#define BUFF_SIZE 16384

char*	reverse(char* str);
void	put_add(char* s1, char* s2);

int main(void)
{
	char	s1[BUFF_SIZE] = {0, };
	char	s2[BUFF_SIZE] = {0, };

	scanf("%s %s", s1, s2);
	put_add(reverse(s1), reverse(s2));
	return 0;
}

char*	reverse(char* str)
{
	char	temp;
	size_t	idx;
	size_t	len;

	len = strlen(str);
	for (idx = 0; idx < len / 2; idx++)
	{
		temp = str[idx];
		str[idx] = str[len - 1 - idx];
		str[len - 1 - idx] = temp;
	}
	return str;
}

void	put_add(char* s1, char* s2)
{
	char	buff[BUFF_SIZE] = {0, };
	int		num;
	size_t	len;
	size_t	idx = 0;

	while (s1[idx] && s2[idx])
	{
		buff[idx] = s1[idx] - '0'+ s2[idx] - '0';
		idx++;
	}
	while (s1[idx] || s2[idx])
	{
		buff[idx] = s1[idx] + s2[idx] - '0';
		idx++;
	}
	len = idx;
	for (idx = 0; idx < len; idx++)
	{
		num = buff[idx];
		if (num >= 10)
		{
			buff[idx] = num % 10 + '0';
			buff[idx + 1] += num / 10;
		}
		else
		{
			buff[idx] += '0';
		}
	}
	if (buff[idx] != 0)
	{
		buff[idx] += '0';
	}
	reverse(buff);
	puts(buff);
}