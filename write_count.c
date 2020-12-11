/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaiyan <tsaiyan@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:15:24 by tsaiyan           #+#    #+#             */
/*   Updated: 2020/12/11 16:15:25 by tsaiyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_count(t_struct *box)
{
	int *a;
	long *aa;
	long long *aaa;
	
	if (!box->flag_int)
	{
		a = va_arg(box->ap, int*);
		*a = box->retlen;
	}
	else if (box->flag_int == 1)
	{
		aa = va_arg(box->ap, long *);
		*aa = box->retlen;
	}
	else if (box->flag_int == 2)
	{
		aaa = va_arg(box->ap, long long *);
		*aaa = box->retlen;
	}
}
