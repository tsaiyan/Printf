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
void	ft_putnbr_bx(unsigned n, t_struct *box)
{
	char *array;
	char result_array[ft_rank_count(n, 16) + 1];
	size_t len;

	len = ft_rank_count(n, 16);
	array = "0123456789ABCDEF";
	result_array[len] = '\0';
	if (n == 0)
		result_array[--len] = 48;
	else
		while (n != 0)
		{
			result_array[--len] = array[n % 16];
			n /= 16;
		}
	while (result_array[len])
	ft_putchar(result_array[len++], box);
}

void	display_bighex(t_struct *box)
{
	long n;
	int precision;
	int wight;

	n = va_arg(box->ap, int);
/* меняет знак, если n < 0 */
	precision = (int)(box->precision - ft_rank_count(n, 16));
	wight = box->wight - ((precision > 0) ? precision : 0) - (int)ft_rank_count(n, 16)\
															- ((box->znak) ? 1 : 0);
	(!n && !box->precision && box->point)? wight++ : 0;
/* если есть выравнивание */
	if (box->align)
	{
		if (box->znak)
		{
			ft_putchar(box->znak, box);
			wight--;
		}
		while (precision-- > 0)
			ft_putchar(48, box);
		(!n && !box->precision && box->point)? 0 : ft_putnbr_bx((int)n, box);
		wight += ((box->znak) ? 1 : 0);
		while (wight-- > 0)
			ft_putchar(32, box);
	}
/* если нет выравнивания */
	else
	{
		/* если есть zero */
		if (box->zero)
		{
			if (box->precision > 0)
			{
				while (wight-- > 0)
					ft_putchar(32, box);
				if (box->znak)
				ft_putchar(box->znak, box);
			}
			else
			{
				if (box->znak)
					ft_putchar(box->znak, box);
				while (wight-- > 0)
					ft_putchar(48, box);
			}
			while (precision-- > 0)
				ft_putchar(48, box);
			ft_putnbr_bx((int)n, box);
		}
		/* если нет zero */
		else
		{
			while (wight-- > 0)
				ft_putchar(32, box);
			/* есть есть знак */
			if (box->znak)
				ft_putchar(box->znak, box);
			while (precision-- > 0)
				ft_putchar(48, box);
			(!n && !box->precision && box->point)? 0 : ft_putnbr_bx((int)n, box);
		}
	}
	ft_putnull(box);
}
