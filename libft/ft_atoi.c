int	ft_atoi(char *str)
{
	int min_count;
	int number;

	number = 0;
	min_count = 0;
	while (*str == '\t' || *str == ' ' ||
	*str == '\n' || *str == '\v'
	|| *str == '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			min_count++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number *= 10;
		number += *str - 48;
		str++;
	}
	if (min_count % 2 == 1)
		number *= -1;
	return (number);
}
