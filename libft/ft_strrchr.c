char *strrchr(const char *s, int c)
{
	unsigned int i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s);
		i--;	
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}