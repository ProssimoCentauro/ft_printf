#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int			ft_printf(const char *s, ...);
int			print_dec_to_hex(unsigned int n, char flag, int prefix, int count);
int			print_address(unsigned long address, int flag, int prefix,
				int count);
int			print_unsigned_int(unsigned int n, int count);
int			ft_putchar(char c);
int			ft_putstr(char *c);
int			ft_putnbr(int n, int count);
