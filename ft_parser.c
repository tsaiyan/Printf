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
	int		i;
	size_t	len;
	i = 0;
	len = ft_strlen(box->argv1);
	while (box->argv1[i] && i < len)
	{
		while (box->argv1[i] != '%' && box->argv1[i])
			write(1, &box->argv1[i++], 1);
		if (box->argv1[++i] == 'c')
			ft_putchar(va_arg(box->argument_pointer, int));
		if (box->argv1[i] == 'd' || box->argv1[i] == 'i')
			ft_putnbr(va_arg(box->argument_pointer, int));
		if (box->argv1[i] == 's')
			ft_putstr(va_arg(box->argument_pointer, char*));
		if (box->argv1[i] == 'x')
			ft_putnbr_x(va_arg(box->argument_pointer, int));
		if (box->argv1[i] == 'X')
			ft_putnbr_bx(va_arg(box->argument_pointer, int));
		if (box->argv1[i] == 'p')
			ft_putnbr_p(va_arg(box->argument_pointer, unsigned long));
		if (box->argv1[i] == 'u')
			ft_putnbr_u(va_arg(box->argument_pointer, unsigned int));
		if (box->argv1[i] == '%')
			write(1, "%", 1);
		if (box->argv1[i - 1] == '%')
			i++;
		if (box->argv1[i] == '\n')
			write(1, "\n", 1);
	}
}
