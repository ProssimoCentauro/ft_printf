#include "Libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>

int			ft_printf(const char *, ...);
char		get_char(const char *s);
const char	*jump_index(const char *s);
void		print_dec_to_hex(unsigned int n, char flag, int prefix);
void		print_address(unsigned long n, int flag, int prefix);
void		print_unsigned_int(unsigned int n);
