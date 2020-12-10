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
static void ft_write_flags(t_struct *box)
{
	{
		if ( box->format[box->i] == '-')
			box->align = 1;
		if ( box->format[box->i] == '+')
			box->znak = '+';
		if ( box->format[box->i] == ' ')
			box->znak = 32;
		if (box->format[box->i++] == 48)
			box->zero = 1;
	}
}

static void ft_call_to_functions(t_struct *box)
{
	if (box->format[box->i] == 'd' || box->format[box->i] == 'i')
		display_int(box);
	if (box->format[box->i] == 'c')
		display_char(box);
	if (box->format[box->i] == 's')
		display_str(box);
	if (box->format[box->i] == 'x')
		display_x(box);
	if (box->format[box->i] == 'X')
		display_bighex(box);
	if (box->format[box->i] == 'p')
		display_pointer(box);
	if (box->format[box->i] == 'u')
		display_unsigned(box);
	if (box->format[box->i] == '%')
		display_percent(box);
	if (box->format[box->i++] == 'o')
		display_8(box);
}

void	ft_parser(t_struct *box)
{
	size_t	len;

	len = ft_strlen(box->format);
	while (box->format[box->i] && box->i < len)
	{
		while (box->format[box->i] != '%' && box->format[box->i])
			ft_putchar(box->format[box->i++], box);
		if (box->format[box->i++] == '%')
		{
/* запись align, и знака +- и нуля*/
			while (box->format[box->i] == 48 || box->format[box->i] == 32 \
				   || box->format[box->i] == '-' || box->format[box->i] == '+')
				ft_write_flags(box);
/* запись ширины */
			if (box->format[box->i] == '*' && (++box->i))
				box->wight = va_arg(box->ap, int);
			else
				while (ft_isdigit(box->format[box->i]))
				{
					box->wight *= 10;
					box->wight += box->format[box->i++] - 48;
				}
			if (box->wight < 0)
			{
				box->align = 1;
				box->wight *= -1;
			}
/* запись точности */
			if (box->format[box->i] == '.')
			{
				box->point = 1;
				if (box->format[++box->i] == '*')
				{
					box->precision = va_arg(box->ap, int);
					box->i++;
				}
				else
				{
					box->precision = 0;
					while (ft_isdigit(box->format[box->i]))
					{
						box->precision *= 10;
						box->precision += box->format[box->i++] - 48;
					}
				}
			}
			ft_call_to_functions(box);
		}
	}
}
