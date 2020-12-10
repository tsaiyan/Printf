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

static void	ft_putstr_ds(char *s, t_struct *box)
{
	if (!s)
		return ;
	if (!box->precision && box->point)
		return ;
	if (box->precision > 0)
		while (*s && box->precision--)
			ft_putchar(*s++, box);
	else
		while (*s)
			ft_putchar(*s++, box);
}
static int	ft_strlen_ds (char *s, t_struct *box)
{
	int result;
	int precision;
	int i;
	
	i = box->precision;
	precision = 0;
	result = 0;
	if (box->point && !box->precision)
		return (0);
	if (box->precision > 0)
		while (s[precision] && i--)
			precision++;
	if (box->wight && !box->precision)
		result = ft_strlen(s);
	else if (box->precision > 0 && box->wight)
		result += precision;
	else
		result = ft_strlen(s);
	return (result);
}

void	display_str(t_struct *box)
{
	char *s;
	int wight;

	s = va_arg(box->ap, char*);
	if (!s)
		s = "(null)";
	wight = (box->wight) ? box->wight - ft_strlen_ds(s, box) : 0;
/* если есть выравнивание */
	if (box->align)
	{
		ft_putstr_ds(s, box);
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
				while (wight-- > 0)
					ft_putchar(32, box);
			else
				while (wight-- > 0)
					ft_putchar(48, box);
			ft_putstr_ds(s, box);
		}
		/* если нет zero */
		else
		{
			while (wight-- > 0)
				ft_putchar(32, box);
			ft_putstr_ds(s, box);
		}
	}
	ft_putnull(box);
}
