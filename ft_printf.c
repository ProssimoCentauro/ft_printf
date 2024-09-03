#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;

	va_start(args, s);
	while (*s)
	{
		if (*s == '%' && get_char(&*s) == 'c')
			ft_putchar_fd(va_arg(args, int), 1);
		else if (*s == '%' && get_char(&*s) == 's')
			ft_putstr_fd(va_arg(args, char *), 1);
		else if (*s == '%' && ((get_char(&*s) == 'x')
				|| (get_char(&*s) == 'X')))
			print_dec_to_hex(va_arg(args, unsigned int), get_char(&*s), 0);
		else if (*s == '%' && ((get_char(&*s) == 'd')
				|| (get_char(&*s) == 'i')))
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
