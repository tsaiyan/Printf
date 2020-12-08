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
	ft_putchar('0', box);
	ft_putchar('x', box);
	if (!n && !box->accuracy && box->point)
		return ;
	while (result_array[len])
	ft_putchar(result_array[len++], box);
}

void	display_pointer(t_struct *box)
{
	unsigned long n;
	int accuracy;
	int wight;

	n = va_arg(box->argument_pointer, unsigned long);
/* меняет знак, если n < 0 */
	accuracy = (int)(box->accuracy - ft_rank_count(n, 16));
	wight = box->wight - ((accuracy > 0) ? accuracy : 0) - (int)ft_rank_count(n, 16)\
															- ((box->znak) ? 1 : 0) - 2;
	(!n && !box->accuracy && box->point)? wight++ : 0;
/* если есть выравнивание */
	if (box->align)
	{
		if (box->znak)
		{
			ft_putchar(box->znak, box);
			wight--;
		}
		while (accuracy-- > 0)
			ft_putchar(48, box);
		(!n && !box->accuracy && box->point)? 0 : ft_putnbr_p(n, box);
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
			if (box->accuracy)
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
			while (accuracy-- > 0)
				ft_putchar(48, box);
			ft_putnbr_p(n, box);
		}
		/* если нет zero */
		else
		{
			while (wight-- > 0)
				ft_putchar(32, box);
			/* есть есть знак */
			if (box->znak)
				ft_putchar(box->znak, box);
			while (accuracy-- > 0)
				ft_putchar(48, box);
			(!n && !box->accuracy && box->point)? ft_putnbr_p(0, box) : ft_putnbr_p(n, box);
		}
	}
	ft_putnull(box);
}
