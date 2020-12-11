/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaiyan <tsaiyan@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:13:44 by tsaiyan           #+#    #+#             */
/*   Updated: 2020/12/02 13:13:49 by tsaiyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *format, ...)
{
	t_struct	*box;
	int			ret;

	if (!(box = malloc(sizeof(t_struct))))
		return (-1);
	box->format = format;
	box->retlen = 0;
	box->i = 0;
	ft_putin(box);
	va_start(box->ap, format);
	ft_parser(box);
	va_end(box->ap);
	ret = box->retlen;
	free(box);
	return (ret);
}
