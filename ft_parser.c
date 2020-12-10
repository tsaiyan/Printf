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
static void ft_write_flags(size_t i, t_struct *box)
{
	{
		if ( box->format[i] == '-')
			box->align = 1;
		if ( box->format[i] == '+')
			box->znak = '+';
		if ( box->format[i] == ' ')
			box->znak = 32;
		if (box->format[i] == 48)
			box->zero = 1;
	}
}

void	ft_parser(t_struct *box)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(box->format);
	while (box->format[i] && i < len)
	{
		/* печатаем все до % и потом после. */
		while (box->format[i] != '%' && box->format[i])
			ft_putchar(box->format[i++], box);
		if (box->format[i++] == '%')
		{
/* запись align, и знака +- и нуля*/
			while (box->format[i] == 48 || box->format[i] == 32 \
				   || box->format[i] == '-' || box->format[i] == '+')
				ft_write_flags(i++, box);
/* запись ширины */
			if (box->format[i] == '*' && (++i))
				box->wight = va_arg(box->ap, int);
			else
				while (ft_isdigit(box->format[i]))
				{
					box->wight *= 10;
					box->wight += box->format[i++] - 48;
				}
			if (box->wight < 0)
			{
				box->align = 1;
				box->wight *= -1;
			}
/* запись точности */
			if (box->format[i] == '.')
			{
				box->point = 1;
				if (box->format[++i] == '*')
				{
					box->precision = va_arg(box->ap, int);
					i++;
				}
				else
				{
					box->precision = 0;
					while (ft_isdigit(box->format[i]))
					{
						box->precision *= 10;
						box->precision += box->format[i++] - 48;
					}
				}
			}
			if (box->format[i] == 'd' || box->format[i] == 'i')
				display_int(box);
			if (box->format[i] == 'c')
				display_char(box);
			if (box->format[i] == 's')
				display_str(box);
			if (box->format[i] == 'x')
				display_x(box);
			if (box->format[i] == 'X')
				display_bighex(box);
			if (box->format[i] == 'p')
				display_pointer(box);
			if (box->format[i] == 'u')
				display_unsigned(box);
			if (box->format[i] == '%')
				display_percent(box);
			if (box->format[i++] == 'o')
				display_8(box);
		}
//		if (box->format[++i] == '\n')
//			write(1, '\n', 2);
	}
}
