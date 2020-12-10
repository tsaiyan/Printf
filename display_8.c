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
void	ft_putnbr_8(unsigned n, t_struct *box)
{
	char *array;
	char result_array[ft_rank_count(n, 7) + 1];
	size_t len;

	len = ft_rank_count(n, 7);
	array = "01234567";
	result_array[len] = '\0';
	if (n == 0)
		result_array[--len] = 48;
	else
		while (n != 0)
		{
			result_array[--len] = array[n % 8];
			n /= 8;
		}
	while (result_array[len])
	ft_putchar(result_array[len++], box);
}

void	display_8(t_struct *box)
{
	unsigned n;
	int precision;
	int wight;

	n = va_arg(box->ap, unsigned);
/* меняет знак, если n < 0 */
	precision = (int)(box->precision - ft_rank_count(n, 7));
	wight = box->wight - ((precision > 0) ? precision : 0) - (int)ft_rank_count(n, 7)\
															- ((box->znak) ? 1 : 0);
	(ft_crutch(n, box))? wight++ : 0;
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
		(ft_crutch(n, box))? 0 : ft_putnbr_8((int)n, box);
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
				if ((box->point && !box->precision))
					while (wight-- > 0)
						ft_putchar(32, box);
				else
					while (wight-- > 0)
					ft_putchar(48, box);
			}
			while (precision-- > 0)
				ft_putchar(48, box);
				(ft_crutch(n, box)) ? 0 : ft_putnbr_8((int)n, box);
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
			(ft_crutch(n, box))? 0 : ft_putnbr_8((int)n, box);
		}
	}
	ft_putnull(box);
}