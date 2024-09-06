#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;

	va_start(args, s);
	count = 0;
	while (*s)
	{
		if (*s == '%' && get_char(&*s) == 'c')
			count += ft_putchar(va_arg(args, int));
		else if (*s == '%' && get_char(&*s) == 's')
			count += ft_putstr(va_arg(args, char *));
		else if (*s == '%' && ((get_char(&*s) == 'x')
				|| (get_char(&*s) == 'X')))
			count += print_dec_to_hex(va_arg(args, unsigned int), get_char(&*s),
					0, 0);
		else if (*s == '%' && ((get_char(&*s) == 'd')
				|| (get_char(&*s) == 'i')))
			count += ft_putnbr(va_arg(args, int), 0);
		else if (*s == '%' && get_char(&*s) == 'p')
			count += print_address(va_arg(args, unsigned long), 0, 1, 0);
		else if (*s == '%' && get_char(&*s) == 'u')
			count += print_unsigned_int(va_arg(args, unsigned int), 0);
		else if (*s == '%' && get_char(&*s) == '%')
			count += ft_putchar('%');
		if (*s == '%')
			s = jump_index(s);
		else
			count += ft_putchar(*s);
		s++;
	}
	va_end(args);
	return (count);
}
#include <stdio.h>
int	main()
{
	int x = ft_printf("hello my friend! %i, %s, %X\n", 325632, "poi", 763428);
	int i = printf("hello my friend! %i, %s, %X\n", 325632, "poi", 763428);

	ft_putnbr(x, 0);
	printf("\n");
	ft_putnbr(i, 0);
}
