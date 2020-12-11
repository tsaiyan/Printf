/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaiyan <tsaiyan@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:08:39 by tsaiyan           #+#    #+#             */
/*   Updated: 2020/12/02 16:08:41 by tsaiyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, t_struct *box)
{
	if (!s)
		return ;
	while (*s)
		ft_putchar(*s++, box);
}

int		ft_strlen(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c, t_struct *box)
{
	if (box)
		box->retlen++;
	write(1, &c, 1);
}

size_t	ft_rank_count(long n, int base)
{
	size_t i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		n *= -1;
		i = 1;
	}
	while (n)
	{
		i++;
		n /= base;
	}
	return (i);
}

void	ft_putnbr(long n)
{
	unsigned res;

	res = (unsigned)n;
	if (res >= 10)
		ft_putnbr(res / 10);
	ft_putchar(res % 10 + 48, NULL);
}
