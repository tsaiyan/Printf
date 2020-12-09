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
	char *arnull;
	
	arnull = "(null)";
	if (!s)
	{
		if (box->accuracy)
			while (box->accuracy-- && *arnull)
				ft_putchar(*arnull++, box);
		else
			ft_putstr(arnull, box);
			
	}
	if (!s)
		return ;
	while (*s)
		ft_putchar(*s++, box);
}

//static int ft_len_accuracy(char *str, t_struct *box)
//{
//	int i;
//
//	i = 0;
//	while (*str++ && box->accuracy--)
//	{
//		i++;
//	}
//	return (0);
//}

char	*ft_write_c(t_struct *box)
{
	int i;
	char *array;
	char result[box->accuracy + 1];
	char *pres;
	char *start;

	pres = result;
	start = pres;
	array = "(null)";
	i = box->accuracy;
	if (!box->point)
		return ("(null)");
	else
		while (i--)
		{
			*pres++ = *array++;
		}
	return (start);
}

void	display_str(t_struct *box)
{
	char *c;
	int wight;
	int accdivstrlen;
	int checkc;

	c = va_arg(box->argument_pointer, char*);
	checkc = ((!c && box->wight && !box->point) ? 6 : 0);
	accdivstrlen = (box->accuracy) ? ft_strlen(c) - box->accuracy : 0;
	wight = box->wight - ft_strlen(c) + (accdivstrlen > 0 ? accdivstrlen : 0) - checkc;
/* если есть выравнивание */
	if (!c)
	{
		c = "(null)";
		if (box->accuracy)
			c += box->accuracy;
	}
	if (box->align)
	{
		if (box->accuracy)
			while(box->accuracy-- && *c)
				ft_putchar(*c++, box);
		else
			(!box->accuracy && box->point) ? 0 :ft_putstr_ds(c, box);;
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
			if (box->accuracy && c)
				while(box->accuracy-- && *c)
					ft_putchar(*c++, box);
			else
				(!box->accuracy && box->point) ? 0 :ft_putstr_ds(c, box);
		}
	}
	ft_putnull(box);
}
