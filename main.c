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
int ints ()
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

	printf("------------------------ \n");
	printf("точность 0 значение 0 \n");
	printf("------------------------ \n");
	printf("printf(""|%%.d|)\n");
	printf("original :|%.d|\n", 0);
	ft_printf("yours    :|%.d|\n", 0);
	
	printf("------------------------ \n");
	printf("точность 0 значение 0 ширина 10\n");
	printf("------------------------ \n");
	printf("printf(""|%%10.d|)\n");
	printf("original :|%10.d|\n", 0);
	ft_printf("yours    :|%10.d|\n", 0);
		printf("\noriginal : %d\n", printf("%-5.0d", 0));
		ft_printf("\nmy       : %d\n",   ft_printf("%-5.0d", 0));
		int INT_MAX = 2147483647;
		int INT_MIN = -2147483648;
		ft_printf("----------------%%d-%%i--------------------\n");
		printf("01) standart PRINTF : |%d|\n", 42);
		ft_printf("01) my       PRINTF : |%d|\n", 42);
		printf("02) standart PRINTF : |%i|\n", 42);
		ft_printf("02) my       PRINTF : |%i|\n", 42);
		printf("03) standart PRINTF : |%-d|\n", 42);
		ft_printf("03) my       PRINTF : |%-d|\n", 42);
		printf("04) standart PRINTF : |%10d|\n", 100);
		ft_printf("04) my       PRINTF : |%10d|\n", 100);
		printf("05) standart PRINTF : |%-10d|\n", 64);
		ft_printf("05) my       PRINTF : |%-10d|\n", 64);
		printf("06) standart PRINTF : |%.10d|\n", 100);
		ft_printf("06) my       PRINTF : |%.10d|\n", 100);
		printf("07) standart PRINTF : |%10.5d|\n", 100);
		ft_printf("07) my       PRINTF : |%10.5d|\n", 100);
		printf("08) standart PRINTF : |%5.10d|\n", 64);
		ft_printf("08) my       PRINTF : |%5.10d|\n", 64);
		printf("09) standart PRINTF : |%1.1d|\n", 16);
		ft_printf("09) my       PRINTF : |%1.1d|\n", 16);
		printf("10) standart PRINTF : |%d|\n", -42);
		ft_printf("10) my       PRINTF : |%d|\n", -42);
		printf("11) standart PRINTF : |%10d|\n", -42);
		ft_printf("11) my       PRINTF : |%10d|\n", -42);
		printf("12) standart PRINTF : |%.10d|\n", -42);
		ft_printf("12) my       PRINTF : |%.10d|\n", -42);
		printf("13) standart PRINTF : |%10.5d|\n", -16);
		ft_printf("13) my       PRINTF : |%10.5d|\n", -16);
		printf("14) standart PRINTF : |%5.10d|\n", -16);
		ft_printf("14) my       PRINTF : |%5.10d|\n", -16);
		printf("15) standart PRINTF : |%1.1d|\n", -20);
		ft_printf("15) my       PRINTF : |%1.1d|\n", -20);
		printf("16) standart PRINTF : |%-10d|\n", -50);
		ft_printf("16) my       PRINTF : |%-10d|\n", -50);
		printf("17) standart PRINTF : |%2d|\n", -20);
		ft_printf("17) my       PRINTF : |%2d|\n", -20);
		printf("18) standart PRINTF : |%.2d|\n", -20);
		ft_printf("18) my       PRINTF : |%.2d|\n", -20);
		printf("19) standart PRINTF : |%2d|\n", -1);
		ft_printf("19) my       PRINTF : |%2d|\n", -1);
		printf("20) standart PRINTF : |%.2d|\n", -1);
		ft_printf("20) my       PRINTF : |%.2d|\n", -1);
		printf("21) standart PRINTF : |%-10d|\n", -80);
		ft_printf("21) my       PRINTF : |%-10d|\n", -80);
		printf("22) standart PRINTF : |%-.10d|\n", -80);
		ft_printf("22) my       PRINTF : |%-.10d|\n", -80);
		printf("23) standart PRINTF : |%06d|\n", 35);
		ft_printf("23) my       PRINTF : |%06d|\n", 35);
		printf("24) standart PRINTF : |%06d|\n", -35);
		ft_printf("24) my       PRINTF : |%06d|\n", -35);
		printf("25) standart PRINTF : |%05.3d|\n", 5);
		ft_printf("25) my       PRINTF : |%05.3d|\n", 5);
		printf("26) standart PRINTF : |%03.5d|\n", 5);
		ft_printf("26) my       PRINTF : |%03.5d|\n", 5);
		printf("27) standart PRINTF : |%05.3d|\n", -5);
		ft_printf("27) my       PRINTF : |%05.3d|\n", -5);
		printf("28) standart PRINTF : |%03.5d|\n", -5);
		ft_printf("28) my       PRINTF : |%03.5d|\n", -5);
		printf("29 standart PRINTF : |%d| |%d|\n", INT_MAX, INT_MIN);
		ft_printf("29) my       PRINTF : |%d| |%d|\n", INT_MAX, INT_MIN);
		printf("30) standart PRINTF : |%d| |%d|\n", INT_MAX + 1, INT_MIN - 1);
		ft_printf("30) my       PRINTF : |%d| |%d|\n", INT_MAX + 1, INT_MIN - 1);
		printf("31) standart PRINTF : |%10.d|\n", 0);
		ft_printf("31) my       PRINTF : |%10.d|\n", 0);
		printf("32) standart PRINTF : |%.d|\n", 100);
		ft_printf("32) my       PRINTF : |%.d|\n", 100);
	return (0);
}

int	main(void)
{
	//ints();
	printf("\noriginal = %d\n", printf("%-7x", 33));
	printf("\nmy = %d\n", ft_printf("%-7x", 33));
	return (0);
}

