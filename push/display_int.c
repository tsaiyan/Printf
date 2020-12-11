/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaiyan <tsaiyan@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:48:29 by tsaiyan           #+#    #+#             */
/*   Updated: 2020/12/03 17:48:36 by tsaiyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** if format has align flag
*/

static void	ft_align(unsigned long long n, t_struct *box)
{
	if (box->znak)
	{
		ft_putchar(box->znak, box);
		box->new_wight--;
	}
	while (box->new_precision-- > 0)
		ft_putchar(48, box);
	(ft_crutch(n, box)) ? box->retlen-- : ft_putnbr(n);
	box->new_wight += ((box->znak) ? 1 : 0);
	while (box->new_wight-- > 0)
		ft_putchar(32, box);
}

/*
** if format has zero flag
*/

static void	ft_zero(unsigned long long n, t_struct *box)
{
	if (box->precision >= 0)
	{
		while (box->new_wight-- > 0)
			ft_putchar(32, box);
		if (box->znak)
			ft_putchar(box->znak, box);
	}
	else
	{
		if (box->znak)
			ft_putchar(box->znak, box);
		while (box->new_wight-- > 0)
			ft_putchar(48, box);
	}
	while (box->new_precision-- > 0)
		ft_putchar(48, box);
	(!box->precision && !n) ? box->retlen-- : ft_putnbr((int)n);
}

/*
** if format hasn't align and zero flags
*/

static void	ft_noalign_nozero(unsigned long long n, t_struct *box)
{
	while (box->new_wight-- > 0)
		ft_putchar(32, box);
	if (box->znak)
		ft_putchar(box->znak, box);
	while (box->new_precision-- > 0)
		ft_putchar(48, box);
	(!n && !box->precision && box->point) ? box->retlen-- : ft_putnbr(n);
}

/*
** main function for dislay all ints
*/

void		display_int(t_struct *box)
{
	unsigned long long	n;
	long long			m;

	m = va_arg(box->ap, long long);
	n = m;
	if (m < 0)
	{
		n = m * -1;
		box->znak = '-';
	}
	box->new_precision = (int)(box->precision - ft_rank_count(n, 10));
	box->new_wight = box->wight - ((box->new_precision > 0) ? \
	box->new_precision : 0) - (int)ft_rank_count(n, 10) - ((box->znak) ? 1 : 0);
	(ft_crutch(n, box)) ? box->new_wight++ : 0;
	if (box->align)
		ft_align(n, box);
	else
	{
		if (box->zero)
			ft_zero(n, box);
		else
			ft_noalign_nozero(n, box);
	}
	box->retlen += ft_rank_count(n, 10);
	ft_putin(box);
}
