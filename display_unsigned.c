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

static void	ft_align(unsigned n, t_struct *box)
{
	if (box->znak)
	{
		ft_putchar(box->znak, box);
		box->new_wight--;
	}
	while (box->new_precision-- > 0)
		ft_putchar(48, box);
	(!n && !box->precision && box->point) ? box->retlen-- : ft_putnbr(n);
	box->new_wight += ((box->znak) ? 1 : 0);
	while (box->new_wight-- > 0)
		ft_putchar(32, box);
}

static void	ft_zero(unsigned n, t_struct *box)
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
	(!n && box->point && !box->precision) ? box->retlen-- : ft_putnbr((int)n);
}

void		display_unsigned(t_struct *box)
{
	unsigned n;

	n = va_arg(box->ap, unsigned);
	box->new_precision = (int)(box->precision - ft_rank_count(n, 10));
	box->new_wight = box->wight - ((box->new_precision > 0) ? \
	box->new_precision : 0) - (int)ft_rank_count(n, 10) - ((box->znak) ? 1 : 0);
	(!n && !box->precision && box->point) ? box->new_wight++ : 0;
	if (box->align)
		ft_align(n, box);
	else
	{
		if (box->zero)
			ft_zero(n, box);
		else
		{
			while (box->new_wight-- > 0)
				ft_putchar(32, box);
			while (box->new_precision-- > 0)
				ft_putchar(48, box);
			(!n && !box->precision && box->point) \
								? box->retlen-- : ft_putnbr(n);
		}
	}
	box->retlen += ft_rank_count(n, 10);
	ft_putnull(box);
}
