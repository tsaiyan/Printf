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
	char		*format;
	int			wight;
	int			new_wight;
	int			align;
	char		znak;
	int			zero;
	int			precision;
	int			new_precision;
	int			point;
	int			retlen;
	char		*ox;
	size_t		i;

	va_list		ap;
}				t_struct;

void			ft_parser(t_struct *box);
void			display_int(t_struct *box);
void			ft_putchar(char c, t_struct *box);
void			ft_putstr(char *s, t_struct *box);
int				ft_strlen(const char *str);
int				ft_printf(char *argv1, ...);
int				ft_isdigit(int c);
void			ft_putnbr(long n);
size_t			ft_rank_count(long n, int base);
void			ft_putin(t_struct *box);
void			display_char(t_struct *box);
void			display_x(t_struct *box);
void			display_int(t_struct *box);
void			display_bighex(t_struct *box);
void			display_unsigned(t_struct *box);
void			display_pointer(t_struct *box);
void			display_percent(t_struct *box);
void			display_8(t_struct *box);
void			display_str(t_struct *box);
int				ft_crutch(long long n, t_struct *box);
#endif
