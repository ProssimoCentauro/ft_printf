//#include "ft_printf.h"
static char	get_char(const char *s)
{
	s++;
	while ((*s == '-') || (*s == '0') || (*s == '.'))
		s++;
	return (*s);
}

static const char	*jump_index(const char *s)
{
	s++;
	while (*s == ' ')
		s++;
	return (&*s);
}
