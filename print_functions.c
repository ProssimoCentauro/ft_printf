#include "ft_printf.h"

static void	print_dec_to_hex(unsigned int n, char flag, int prefix)
{
	unsigned int	rem;

	if (prefix == 1)
	{
		write(1, "0x", 2);
		prefix = 0;
	}
	if (n / 16 != 0)
		print_dec_to_hex(n / 16, flag, prefix);
	rem = n % 16;
	if (rem >= 10 && flag == 'x')
		ft_putchar_fd(rem + 87, 1);
	else if (rem >= 10 && flag == 'X')
		ft_putchar_fd(rem + 55, 1);
	else
		ft_putnbr_fd(rem, 1);
}

static void	print_address(unsigned long address, int flag, int prefix)
{
	unsigned int	rem;

	if (prefix == 1)
	{
		write(1, "0x", 2);
		prefix = 0;
	}
	if (address / 16 != 0)
		print_address(address / 16, flag, prefix);
	rem = address % 16;
	if (rem >= 10 && flag == 0)
		ft_putchar_fd(rem + 87, 1);
	else if (rem >= 10 && flag == 1)
		ft_putchar_fd(rem + 55, 1);
	else
		ft_putnbr_fd(rem, 1);
}

static void	print_unsigned_int(unsigned int n)
{
	if (n >= 10)
		print_unsigned_int(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
}
