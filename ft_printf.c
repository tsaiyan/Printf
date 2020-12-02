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
	m_struct *box;

	box = malloc(sizeof(m_struct));
	box->argv1 = argv1;
	va_start(box->argument_pointer, argv1);
	ft_parcer(box);
	va_end(box->argument_pointer);
	return (0);
}

int main ()
{
	ft_printf("%d %i %c %c %c %s pidor\n", 3, 2, 'r', 'a', 'z', "like you", "lol");
}
