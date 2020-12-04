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
	int i;

	i = box->wight;
	n = va_arg(box->argument_pointer, int);
/* меняет знак, если n < 0 */
	if (n < 0)
	{
		box->znak= '-';
		n *= -1;
	}
/* если есть выравнивание */
	if (box->align)
	{
		if (box->znak && (i--))
			ft_putchar(box->znak);
		ft_putnbr((int)n);
		if (box->wight)
			while (--i >= ft_rank_count(n, 10))
				ft_putchar(32);
	}
/* если нет выравнивания */
	else
	{
		/* если есть zero */
		if (box->zero)
		{
			if (box->znak)
			{
				ft_putchar(box->znak);
				i--;
			}
			while (i > 0 && --i >= ft_rank_count(n, 10))
				ft_putchar(48);
			ft_putnbr((int)n);
		}
		/* если нет zero */
		else
		{
			while (i > 0 && --i > ft_rank_count(n, 10))
				ft_putchar(32);
			/* есть есть знак */
			if (box->znak)
				ft_putchar(box->znak);
			/* есть нет знака */
			else
				ft_putchar(32);
			ft_putnbr((int)n);;
		}
	}
}
