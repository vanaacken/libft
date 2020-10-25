#include "libft.h"

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strtrim(char const *s)
{
	unsigned int i;
	unsigned int len;
	unsigned int start;
	char *new;

	len = ft_strlen((char *)s);

	start = 0;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	i = 0;
	while (s[len - i - 1] == ' ' || s[len - i - 1] == '\t' || s[len - i - 1] == '\n')
		i++;
	new = (char *)malloc(sizeof(char) * (len - start - i));
	new = (char *)s + start;
	return (new);
}
#include <stdio.h>
int	main(void)
{
	char str[52] = "        GeeksForGeeks is for programming geeks.\n";
	char *new;

	new = ft_strtrim((char const *) str);
	printf("%s\n", str);
	printf("%s\n",new);
	free (new);
	return (0);
}
