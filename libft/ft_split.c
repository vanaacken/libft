#include "libft.h"
#include <stdio.h>

static unsigned int	count_words(char const *s, char c)
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
		else if (s[i] != c && check == 0)
		{
			check = 1;
			count += 1;
		}
		i++;
	}
	return (count);
}

char	*make_substring(const char *s, const char *sp, unsigned int i, char c)
{
	unsigned int len;

	len = 0;
	while (s[i + len] != c && s[i + len])
		len++;
	sp = ft_substr(s, i, len);
	return ((char *)sp);
}

char			**ft_split(char const *s, char c)
{
	unsigned int	count;
	char			**split;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	count = count_words(s, c);
	if (!(split = (char **)malloc(sizeof(char *) * (count + 1))))
		return (NULL);
	while (s[i] != '\0' && count > 0)
	{
		if (s[i] != c)
		{
			split[j] = make_substring(s, split[j], i, c);
			if (!split[j])
			{
				free (split);
				return (NULL);
			}
			i += ft_strlen(split[j]);
			j++;
			count--;
		}
		else
			i++;
	}
	return (split);
}


// int main(void)
// {
// 	char **split;
// 	char str[22] = "Split is mijn biatch!";
// 	split = ft_split(str, ' ');
// 	int i;
// 	i = 0;
// 	while (i < 4)
// 	{
// 		printf("%s\n", split[i]);
// 		i++;
// 	}
// 	free(split);
// 	return (0);
// }