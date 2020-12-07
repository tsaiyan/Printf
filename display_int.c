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

void	display_int(t_struct *box)
{
	long n;
	int accuracy;
	int wight;

	n = va_arg(box->argument_pointer, int);
/* меняет знак, если n < 0 */
	if (n < 0)
	{
		box->znak= '-';
		n *= -1;
	}
	accuracy = (int)(box->accuracy - ft_rank_count(n, 10));
	wight = box->wight - ((accuracy > 0) ? accuracy : 0) \
	- ((!n && box->point)? 0 : ((int)ft_rank_count(n, 10))) - ((box->znak) ? 1 : 0);
/* если есть выравнивание */
	if (box->align)
	{
		if (box->znak && (wight--))
			ft_putchar(box->znak);
		while (accuracy-- > 0)
			ft_putchar(48);
		ft_putnbr((int)n);
		wight += ((box->znak) ? 1 : 0);
		while (wight-- > 0)
			ft_putchar(32);
	}
/* если нет выравнивания */
	else
	{
		/* если есть zero */
		if (box->zero)
		{
			if (box->accuracy)
			{
				while (wight-- > 0)
					ft_putchar(32);
				ft_putchar(box->znak);
			}
			else
			{
				ft_putchar(box->znak);
				while (wight-- > 0)
					ft_putchar(48);
			}
			while (accuracy-- > 0)
				ft_putchar(48);
			ft_putnbr((int)n);
		}
		/* если нет zero */
		else
		{
			while (wight-- > 0)
				ft_putchar(32);
			/* есть есть знак */
			if (box->znak)
				ft_putchar(box->znak);
			while (accuracy-- > 0)
				ft_putchar(48);
			(!n && !box->accuracy && box->point)? 0 : ft_putnbr(n);
		}
	}
}
