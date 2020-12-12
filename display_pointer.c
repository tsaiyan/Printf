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
** special putnbr version for pointers
*/

static void	ft_putnbr_p(unsigned long n, t_struct *box)
{
	char	*array;
	char	result_array[ft_rank_count(n, 16) + 1];
	size_t	len;
	unsigned long m;

	m = n;
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
	if (ft_crutch(m, box))
		return ;
	while (result_array[len])
		ft_putchar(result_array[len++], box);
}

/*
** if format has align flag
*/

static void	ft_align(unsigned long n, t_struct *box)
{
	if (box->ox)
	{
		ft_putstr(box->ox, box);
		box->new_wight--;
	}
	while (box->new_precision-- > 0)
		ft_putchar(48, box);
	(ft_crutch(n, box)) ? 0 : ft_putnbr_p(n, box);
	box->new_wight += ((box->ox) ? 1 : 0);
	while (box->new_wight-- > 0)
		ft_putchar(32, box);
}

/*
** if format has zero flag
*/

static void	ft_zero(unsigned long n, t_struct *box)
{
	if (box->precision != -1)
	{
		while (box->new_wight-- > 0)
			ft_putchar(32, box);
		if (box->ox)
			ft_putstr(box->ox, box);
	}
	else
	{
		if (box->ox)
			ft_putstr(box->ox, box);
		while (box->new_wight-- > 0)
			ft_putchar(48, box);
	}
	while (box->new_precision-- > 0)
		ft_putchar(48, box);
	ft_putnbr_p(n, box);
}

/*
** 	main function for display pointers
*/

void		display_pointer(t_struct *box)
{
	unsigned long n;

	n = va_arg(box->ap, unsigned long);
	box->new_precision = (int)(box->precision - ft_rank_count(n, 16));
	box->new_wight = box->wight - ((box->new_precision > 0) ? \
	box->new_precision : 0) - (int)ft_rank_count(n, 16) - 2;
	(ft_crutch(n, box)) ? box->new_wight++ : 0;
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
			if (box->precision)
				ft_putstr(box->ox, box);
			while (box->new_precision-- > 0)
				ft_putchar(48, box);
			(!n && box->point && box->precision == -1) ? ft_putnbr_p(0, box) : ft_putnbr_p(n, box);
		}
	}
	ft_putin(box);
}
