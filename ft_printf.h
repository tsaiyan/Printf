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
	int			wight;
	int			align;
	char		znak;
	int			zero;
	int			accuracy;
	int			point;
	int			retlen;

	va_list		argument_pointer;
}				t_struct;

void			ft_pwtype(t_struct *box);
void			display_int(t_struct *box);
void			ft_putchar(char c, t_struct *box);
void			ft_putstr(char *s);
size_t			ft_strlen(const char *str);
void			ft_putnbr_x(int n);
void			ft_putnbr_bx(int n);
void			ft_putnbr_p(unsigned long n);
void			ft_putnbr_u(unsigned int n);
int				ft_printf(char *argv1, ...);
int				ft_isdigit(int c);
int				ft_atoi(char *str);
void			ft_putnbr(long n);
void			display_int(t_struct *box);
size_t			ft_rank_count(long n, int base);
void			ft_putnull(t_struct *box);
#endif
