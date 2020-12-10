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

void	ft_putnbr_p(unsigned long n, t_struct *box)
{
	char *array;
	char result_array[ft_rank_count(n, 16) + 1];
	size_t len;

	len = ft_rank_count(n, 16);
	array = "0123456789abcdef";
	result_array[len] = '\0';
	if (n == 0)
		result_array[--len] = 48;
	else
		while (n != 0)
		{
			result_array[--len] = array[n % 16];
			n /= 16;
		}
	if (!box->precision)
		ft_putstr(box->ox, box);
	if (!n && !box->precision && box->point)
		return ;
	while (result_array[len])
	ft_putchar(result_array[len++], box);
}

void	display_pointer(t_struct *box)
{
	unsigned long n;
	int precision;
	int wight;

	n = va_arg(box->ap, unsigned long);
/* меняет знак, если n < 0 */
	precision = (int)(box->precision - ft_rank_count(n, 16));
	wight = box->wight - ((precision > 0) ? precision : 0) - (int)ft_rank_count(n, 16)\
															- 2;
	(!n && !box->precision && box->point)? wight++ : 0;
/* если есть выравнивание */
	if (box->align)
	{
		if (box->ox)
		{
			ft_putstr(box->ox, box);
			wight--;
		}
		while (precision-- > 0)
			ft_putchar(48, box);
		(!n && !box->precision && box->point)? 0 : ft_putnbr_p(n, box);
		wight += ((box->ox) ? 1 : 0);
		while (wight-- > 0)
			ft_putchar(32, box);
	}
/* если нет выравнивания */
	else
	{
		/* если есть zero */
		if (box->zero)
		{
			if (box->precision != -1)
			{
				while (wight-- > 0)
					ft_putchar(32, box);
				if (box->ox)
					ft_putstr(box->ox, box);
			}
			else
			{
				if (box->ox)
					ft_putstr(box->ox, box);
				while (wight-- > 0)
					ft_putchar(48, box);
			}
			while (precision-- > 0)
				ft_putchar(48, box);
			ft_putnbr_p(n, box);
		}
		/* если нет zero */
		else
		{
			while (wight-- > 0)
				ft_putchar(32, box);
			/* есть есть знак */
			if (box->precision)
				ft_putstr(box->ox, box);
			while (precision-- > 0)
				ft_putchar(48, box);
			(!n && !box->precision && box->point)? ft_putnbr_p(0, box) : ft_putnbr_p(n, box);
		}
	}
	ft_putnull(box);
}
