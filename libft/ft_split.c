#include "libft.h"
#include <stdio.h>

unsigned int	count_words(char const *s, char c)
{
	unsigned int count;
	unsigned int check;
	unsigned int i;

	count = 0;
	check = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			check = 0;
		else if (s[1] != c && check == 0)
		{
			check = 1;
			count += 1;
		}
		i++;
	}
	return (count);
}

char		**ft_split(char const *s, char c)
{
	unsigned int	count;
	char			**split;
	unsigned int	i;
	unsigned int	len;
	unsigned int	j;

	i = 0;
	j = 0;
	count = count_words(s, c);
	split = (char **)malloc(sizeof(char *) * count);
	while (s[i] != '\0' && count > 0)
	{
		if (s[i] != c)
		{
			len = 0;
			while (s[i + len] != c)
				len++;
			split[j] = ft_substr(s, i, len);
			j++;
			count--;
			i += len;
		}
		else
			i++;
	}
	return (split);
}


int main(void)
{
	char **split;
	char str[22] = "Split is mijn biatch!";
	split = ft_split(str, ' ');
	int i;
	i = 0;
	while (i < 4)
	{
		printf("%s\n", split[i]);
		i++;
	}
	free(split);
	return (0);
}