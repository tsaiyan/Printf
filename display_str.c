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

void	ft_putstr_ds(char *s, t_struct *box)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar(*s++, box);
}

void	display_str(t_struct *box)
{
	char *c;
	int wight;
	int accdivstrlen;
	
	c = va_arg(box->argument_pointer, char*);
	accdivstrlen = (box->accuracy) ? ft_strlen(c) - box->accuracy : 0;
	wight = box->wight - ft_strlen(c) + (accdivstrlen > 0 ? accdivstrlen : 0);
/* если есть выравнивание */
	if (box->align)
	{
		ft_putstr_ds(c, box);
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
			ft_putstr_ds(c, box);
		}
		/* если нет zero */
		else
		{
			while (wight-- > 0)
				ft_putchar(32, box);
			/* есть есть знак */
			if (box->accuracy)
				while(box->accuracy-- && *c)
					ft_putchar(*c++, box);
			else
				(!box->accuracy && box->point) ? 0 :ft_putstr_ds(c, box);
		}
	}
	ft_putnull(box);
}
