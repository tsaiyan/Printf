/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsaiyan <tsaiyan@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:14:06 by tsaiyan           #+#    #+#             */
/*   Updated: 2020/12/02 13:14:08 by tsaiyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int tester ()
{
	printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	printf("\nТестируем INT\n");
	printf("\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n");
	printf("\n\n");

	printf("------------------------ \n");
	printf("Ширина\n");
	printf("------------------------ \n");
	printf("printf(""|%%10d|\\n"", 1); \n\n");
	printf("original :|%10d|\n", 1);
	ft_printf("yours    :|%10d|\n", 1);	printf("\n\n");
	printf("\n......\n\n");

	printf("------------------------ \n");
	printf("Точность\n");
	printf("------------------------ \n");
	printf("printf(""|%%.2d|\\n"", 1); \n\n");
	printf("original :|%.2d|\n", 1);
	ft_printf("yours    :|%.2d|\n", 1);
	printf("\n......\n\n");


	printf("------------------------ \n");
	printf("      *.* \n");
	printf("------------------------ \n");
	printf("printf(""|%%*.*d|\\n"", 10, 5, 11); \n\n");
	printf("original :|%*.*d|\n", 10, 5, 11);
	ft_printf("yours    :|%*.*d|\n", 10, 5, 11);
	printf("\n......\n\n");

	printf("------------------------\n");
	printf("Ширина + точность + знак \n");
	printf("---------------------\n");
	printf("printf(""|%%10.2d|\\n"", -1); \n\n");
	printf("original :|%10.2d|\n", -1);
	ft_printf("yours    :|%10.2d|\n", -1);
	printf("\n......\n\n");

	printf("------------------------ \n");
	printf("Флаг 0 + ширина + точность + знак \n");
	printf("------------------------ \n");
	printf("printf(""|%%010.2d|\\n"", -1); \n\n");
	printf("original :|%010.2d|\n", -1);
	ft_printf("yours    :|%010.2d|\n", -1);
	printf("\n......\n\n");

	printf("------------------------ \n");
	printf("Флаг 0 + выравнивание + ширина + точность + знак \n");
	printf("------------------------ \n");
	printf("printf(""|%%-010.2d|\\n"", -1); \n\n");
	printf("original :|%-010.2d|\n", -1);
	ft_printf("yours    :|%-010.2d|\n", -1);
	printf("\n......\n\n");

	printf("------------------------ \n");
	printf("int max int min \n");
	printf("------------------------ \n");
	printf("max int: \n");
	ft_printf("%d\n", 2147483647);
	printf("max int with + flag: \n");
	ft_printf("%+d\n", 2147483647);
	printf("min int: \n");
	ft_printf("%d\n", -2147483648);
	return (0);
}

int	main(void)
{
	tester();

	return (0);
}

