/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaiyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:37:58 by tsaiyan           #+#    #+#             */
/*   Updated: 2020/10/31 14:38:00 by tsaiyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			sign;
	long int	i;
	long int	res;

	res = 0;
	i = 0;
	sign = 1;
	while ((str[i] == 32) || ((str[i] >= 9 && str[i] <= 13)))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - 48);
		i++;
		if (res > 922337203685477580 && sign < 0)
			return (0);
		if (res > 922337203685477580 && sign > 0)
			return (-1);
	}
	return ((int)res * sign);
}
