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

void		ft_putnbr_8(unsigned n, t_struct *box)
{
	char	*array;
	char	result_array[ft_rank_count(n, 7) + 1];
	size_t	len;

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

static void	ft_if_align(unsigned n, t_struct *box)
{
	if (box->znak)
	{
		ft_putchar(box->znak, box);
		box->new_wight--;
	}
	while (box->new_precision-- > 0)
		ft_putchar(48, box);
	(ft_crutch(n, box)) ? 0 : ft_putnbr_8((int)n, box);
	box->new_wight += ((box->znak) ? 1 : 0);
	while (box->new_wight-- > 0)
		ft_putchar(32, box);
}

static void	ft_if_zero(unsigned n, t_struct *box)
{
	if (box->precision > 0)
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
		if ((box->point && !box->precision))
			while (box->new_wight-- > 0)
				ft_putchar(32, box);
		else
			while (box->new_wight-- > 0)
				ft_putchar(48, box);
	}
	while (box->new_precision-- > 0)
		ft_putchar(48, box);
	(ft_crutch(n, box)) ? 0 : ft_putnbr_8((int)n, box);
}

void		display_8(t_struct *box)
{
	unsigned n;

	n = va_arg(box->ap, unsigned);
	box->new_precision = (int)(box->precision - ft_rank_count(n, 7));
	box->new_wight = box->wight - ((box->new_precision > 0) ?\
	box->new_precision : 0) - (int)ft_rank_count(n, 7) - ((box->znak) ? 1 : 0);
	(ft_crutch(n, box)) ? box->new_wight++ : 0;
	if (box->align)
		ft_if_align(n, box);
	else
	{
		if (box->zero)
			ft_if_zero(n, box);
		else
		{
			while (box->new_wight-- > 0)
				ft_putchar(32, box);
			if (box->znak)
				ft_putchar(box->znak, box);
			while (box->new_precision-- > 0)
				ft_putchar(48, box);
			(ft_crutch(n, box)) ? 0 : ft_putnbr_8((int)n, box);
		}
	}
	ft_putnull(box);
}
