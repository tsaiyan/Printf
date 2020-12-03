/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaiyan <tsaiyan@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:14:06 by tsaiyan           #+#    #+#             */
/*   Updated: 2020/12/02 13:14:08 by tsaiyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_list
{
	char		*argv1;
	va_list		argument_pointer;
}				t_struct;
void			ft_pwtype(t_struct *box);
void			ft_putchar(char c);
void			ft_putnbr(int n);
void			ft_putstr(char *s);
size_t			ft_strlen(const char *str);
void			ft_putnbr_x(int n);
void			ft_putnbr_bx(int n);
void			ft_putnbr_p(unsigned long n);
#endif
