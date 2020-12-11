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
** if format hasn't align flag
*/

static void	ft_no_align(char c, t_struct *box)
{
	if (box->zero)
	{
		if (box->precision > 0)
		{
			while (box->wight-- > 0)
				ft_putchar(32, box);
			if (box->znak)
				ft_putchar(box->znak, box);
		}
		else
		{
			if (box->znak)
				ft_putchar(box->znak, box);
			while (box->wight-- > 0)
				ft_putchar(48, box);
		}
		ft_putchar(c, box);
	}
	else
	{
		while (box->wight-- > 0)
			ft_putchar(32, box);
		ft_putchar(c, box);
	}
}

/*
** 	main function for display char
*/

void		display_char(t_struct *box)
{
	char c;

	c = va_arg(box->ap, int);
	box->wight--;
	if (box->align)
	{
		ft_putchar(c, box);
		while (box->wight-- > 0)
			ft_putchar(32, box);
	}
	else
		ft_no_align(c, box);
	ft_putnull(box);
}
