#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stddef.h>
#include <unistd.h>

# define HEXAMIN "0123456789abcdef"
# define HEXAMAX "0123456789ABCDEF"

int		      ft_printf(const char *input, ...);
static int	ft_spec(va_list ap, char c, int count);
int         ft_putlchar(char c);
int         *ft_putstr(char *str);
int         ft_puthex(int num, char *c);

#endif
