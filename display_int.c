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

void	display_int(t_struct *box)
{
	int n;
	int i;

	i = box->wight;
	n = va_arg(box->argument_pointer, int);
	
	/* если есть выравнивание */
	if (i)
	{
		/* если есть - в ширине, сдвигаем влево */
		if (box->align)
		{
			/* если есть +, выводим его перед положительными числами (вкл 0)*/
			if ((box->plus && n >= 0))
			{
				ft_putchar('+');
				i--;
			}
			ft_putnbr(n);
			while (--i >= ft_rank_count(n, 10))
			putchar(32);
		}
			/* если нет выравнивания */
		else
		{
			/* снова проверка на плюс */
			if ((box->plus && n >= 0))
			{
				i--;
				while (--i >= ft_rank_count(n, 10))
					putchar(32);
				ft_putchar('+');
				ft_putnbr(n);
			}
			else
			{
				while (--i >= ft_rank_count(n, 10))
				putchar(32);
				ft_putnbr(n);
			}
		}
			
	}
	else
		ft_putnbr(n);
}
