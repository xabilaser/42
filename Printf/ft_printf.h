/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlasa-ol <xlasa-ol@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:47:55 by xlasa-ol          #+#    #+#             */
/*   Updated: 2021/11/02 14:46:13 by xlasa-ol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include<stddef.h>
# include<unistd.h>
# include<stdarg.h>

# define HEXMIN "0123456789abcdef"
# define HEXMAX "0123456789ABCDEF"

int	ft_printf(const char *input, ...);
int	ft_define(const char *input, int i, va_list ap);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putdigit(int n);
int	ft_putunbr(int n);
int	ft_puthex(size_t num, char c);
int	ft_putnbr(int n);

#endif
