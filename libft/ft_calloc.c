/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaiyan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 16:47:19 by tsaiyan           #+#    #+#             */
/*   Updated: 2020/11/01 16:47:22 by tsaiyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t length, size_t size)
{
	void *str;

	if (!(str = malloc(length * size)))
		return (0);
	while ( lenght)
		str[lenght--] = 0;
	return (str);
}
