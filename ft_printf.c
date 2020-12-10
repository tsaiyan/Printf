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
	t_struct *box;

	box = malloc(sizeof(t_struct));
	box->format = format;
	box->retlen = 0;
	box->i = 0;
	ft_putnull(box);
	va_start(box->ap, format);
	ft_parser(box);
	va_end(box->ap);
	return ((box->retlen) > 0) ? box->retlen : 0; 
}
