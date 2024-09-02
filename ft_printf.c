#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include "Libft/libft.h"

char	get_char(const char *s)
{
	s++;
	while (*s == ' ')
		s++;
	return (*s);
}

const char	*jump_index(const char *s)
{
	s++;
	while(*s == ' ')
		s++;
	return (&*s);
}
/*
void	check_format(const char *s, ...)

{
	char	c;
	va_list args;

	va_copy(args, ...);
	va_start (args, s);
	c = get_char(s);
	if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	va_end(args);
}
*/
/*
int	count_bin(int n)
{

}
*/

void	print_dec_to_hex(unsigned int n, char flag, int prefix)
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

void	print_address(unsigned long address, int flag, int prefix)
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

int	*dec_to_bin(int n)
{
	int	*dest;
	int	rem;

	if (n / 2 != 0)
	{
		dec_to_bin(n / 2);
	}
	rem = n % 2;
	dest = (int *)malloc(4);
	dest[(sizeof(dest) / 4) - 1] = rem;
	return (dest);
}

void	print_unsigned_int(unsigned int n)
{
	if (n >= 10)
		print_unsigned_int(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
}
int	ft_printf(const char *s, ...)
{
	va_list args;

	va_start (args, s);

	while (*s)
	{
		if (*s == '%' && get_char(&*s) == 'c')
			ft_putchar_fd(va_arg(args, int), 1);
		else if (*s == '%' && get_char(&*s) == 's')
			ft_putstr_fd(va_arg(args, char *), 1);
		else if (*s == '%' && ((get_char(&*s) == 'x') || (get_char(&*s) == 'X')))
			print_dec_to_hex(va_arg(args, unsigned int), get_char(&*s), 0);
		else if (*s == '%' && ((get_char(&*s) == 'd') || (get_char(&*s) == 'i')))
			ft_putnbr_fd(va_arg(args, int), 1);
		else if (*s == '%' && get_char(&*s) == 'p')
			print_address(va_arg(args, unsigned long), 0, 1);
		else if (*s == '%' && get_char(&*s) == 'u')
			print_unsigned_int(va_arg(args, unsigned int));
		else if (*s == '%' && get_char(&*s) == '%')
			write(1, "%", 1);
		if (*s == '%')
			s = jump_index(s);
		else
			write(1, s, 1);
		s++;
	}
	va_end(args);
	return (0);
}

int	main()
{
	//unsigned int	x = 4294967295;
	//int i = 89;
	//ft_printf("%p\n", &x);
	//int	*ptr = &x;
	//unsigned long address = (unsigned long)&x;
	//printf("%li\n", (unsigned long)&x);
	//printf("holawei %% int:%  di, address:% p, hex:%      X, uns:%u, str:% s, char:%  c\n",i, &i, x, x, "pippliuos", 'j' );
	//ft_printf("holawei %% int:%  di, address:% p, hex:%      X, uns:%u, str:% s, char:%  c\n",i, &i, x, x, "pippliuos", 'j' );
	
	ft_printf("%d", 21474836479122);

	//ft_printf("% %");
	return 0;
}
