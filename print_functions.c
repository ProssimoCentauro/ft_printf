#include "ft_printf.h"

int	print_dec_to_hex(unsigned int n, char flag, int prefix, int count)
{
	unsigned int	rem;

	if (prefix == 1)
	{
		write(1, "0x", 2);
		prefix = 0;
	}
	if (n / 16 != 0)
		count = print_dec_to_hex(n / 16, flag, prefix, count);
	rem = n % 16;
	if (rem >= 10 && flag == 'x')
		ft_putchar(rem + 87);
	else if (rem >= 10 && flag == 'X')
		ft_putchar(rem + 55);
	else
		ft_putnbr(rem, 0);
	count++;
	return (count);
}

int	print_address(unsigned long address, int flag, int prefix,
		int count)
{
	unsigned int	rem;

	if (prefix == 1)
	{
		write(1, "0x", 2);
		prefix = 0;
		count += 2;
	}
	if (address / 16 != 0)
		count = print_address(address / 16, flag, prefix, count);
	rem = address % 16;
	if (rem >= 10 && flag == 0)
		ft_putchar(rem + 87);
	else if (rem >= 10 && flag == 1)
		ft_putchar(rem + 55);
	else
		ft_putnbr(rem, 0);
	count++;
	return (count);
}

int	print_unsigned_int(unsigned int n, int count)
{
	if (n >= 10)
		count = print_unsigned_int(n / 10, count);
	ft_putchar((n % 10) + '0');
	count++;
	return (count);
}
