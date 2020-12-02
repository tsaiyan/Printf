#include "libft.h"
#include <stdio.h>

size_t	ft_putstr(char **str)
{
	size_t i = 0;
	while (*str)
	{
		puts(*str++);
		i++;
	}
	return i;
}

int main ()
{
//	char **mall;
//	mall = ft_split("   lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
//	//ft_putstr(mall);
//	printf("%zu", ft_putstr(mall));
	//ft_putnbr_fd(10000, 1);
	puts(ft_strnstr(NULL, "igolka", 10));
}
