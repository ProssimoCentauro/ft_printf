//#

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *c)
{
	int	count;

	count = 0;
	while (*c)
	{
		write(1, c++, 1);
		count++;
	}
	return (count);
}

int	ft_putnbr(int n, int count)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n = -n;
		write(1, "-", 1);
		count++;
	}
	if (n >= 10)
		count = ft_putnbr(n / 10, count);
	ft_putchar((n % 10) + '0');
	count++;
	return (count);
}
