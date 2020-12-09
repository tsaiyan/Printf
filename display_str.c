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
	if (!box->accuracy && box->point)
		return ;
	if (box->accuracy)
		while (*s && box->accuracy--)
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
	
	i = box->accuracy;
	precision = 0;
	result = 0;
	if (box->point && !box->accuracy)
		return (0);
	if (box->accuracy)
		while (s[precision] && i--)
			precision++;
	if (box->wight && !box->accuracy)
		result = ft_strlen(s);
	else if (box->accuracy && box->wight)
		result += precision;
	else
		result = ft_strlen(s);
	return (result);
}

void	display_str(t_struct *box)
{
	char *s;
	int wight;

	s = va_arg(box->argument_pointer, char*);
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
			if (box->accuracy)
				while (wight-- > 0)
					ft_putchar(48, box);
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
