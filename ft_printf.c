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

int	ft_printf(char *argv1, ...)
{
	t_struct *box;

	box = malloc(sizeof(t_struct));
	box->argv1 = argv1;
	box->retlen = 0;
	ft_putnull(box);
	va_start(box->argument_pointer, argv1);
	ft_pwtype(box);
	va_end(box->argument_pointer);
	return ((box->retlen) > 0) ? box->retlen : 0; 
}
