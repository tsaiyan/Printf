/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaiyan <tsaiyan@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 14:28:18 by tsaiyan           #+#    #+#             */
/*   Updated: 2020/12/02 14:28:48 by tsaiyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pwtype(t_struct *box)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(box->argv1);
	while (box->argv1[i] && i < len)
	{
		/* печатаем все до % и потом после. */
		while (box->argv1[i] != '%' && box->argv1[i])
			ft_putchar(box->argv1[i++], box);
		if (box->argv1[i++] == '%')
		{
/* запись align, и знака +- и нуля*/
			while (box->argv1[i] == 48 || box->argv1[i] == 32 || box->argv1[i] == '-' || box->argv1[i] == '+')
			{
				if ( box->argv1[i] == '-')
					box->align = 1;
				if ( box->argv1[i] == '+')
					box->znak = '+';
				if ( box->argv1[i] == ' ')
					box->znak = 32;
				if (box->argv1[i++] == 48)
					box->zero = 1;
			}
/* запись ширины */
			if (box->argv1[i] == '*' && (++i))
				box->wight = va_arg(box->argument_pointer, int);
			else
				while (ft_isdigit(box->argv1[i]))
				{
					box->wight *= 10;
					box->wight += box->argv1[i++] - 48;
				}
/* запись точности */
			if (box->argv1[i] == '.')
			{
				box->point = 1;
				if (box->argv1[++i] == '*')
				{
					box->accuracy = va_arg(box->argument_pointer, int);
					i++;
				}
				else
					while (ft_isdigit(box->argv1[i]))
					{
						box->accuracy *= 10;
						box->accuracy += box->argv1[i++] - 48;
					}
			}
			if (box->argv1[i] == 'd' || box->argv1[i] == 'i')
				display_int(box);
			if (box->argv1[i] == 'c')
				display_char(box);
//			if (box->argv1[i] == 's')
//				ft_putstr(va_arg(box->argument_pointer, char*));
			if (box->argv1[i] == 'x')
				display_x(box);
			if (box->argv1[i] == 'X')
				display_bighex(box);
			if (box->argv1[i] == 'p')
				display_pointer(box);
			if (box->argv1[i] == 'u')
				display_unsigned(box);
			if (box->argv1[i] == '%')
				display_percent(box);
			i++;
		}
//		if (box->argv1[i] == '\n')
//			write(1, "\n", 1);
	}
}
