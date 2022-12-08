#include "../ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	// char	*hex;

	// hex = ft_itohex(255);
	// free(hex);
	// hex = ft_itohex(0);
	// free(hex);
	// hex = ft_itohex(9);
	// free(hex);
	// hex = ft_itohex(10);
	// free(hex);
	// hex = ft_itohex(11);
	// free(hex);
	// hex = ft_itohex(12);
	// free(hex);
	// hex = ft_itohex(13);
	// free(hex);
	// hex = ft_itohex(14);
	// free(hex);
	// hex = ft_itohex(15);
	// free(hex);
	// hex = ft_itohex(16);
	// free(hex);
	// hex = ft_itohex(1024);
	// free(hex);

	// if (hex)
	// 	hex = NULL;

	ft_printf("%d\n", -1);
	printf(">%d<\n", -1);
	ft_printf("%d\n", 0);
	printf(">%d<\n", 0);
	ft_printf("%d\n", 1000);
	printf(">%d<\n", 1000);

	ft_printf("%i\n", -1);
	printf(">%i<\n", -1);
	ft_printf("%i\n", 0);
	printf(">%i<\n", 0);
	ft_printf("%i\n", 1000);
	printf(">%i<\n", 1000);

	// char *ptr = "hihii";
	// char *ptr2 = ptr + 1;
	// // printf("\n%d\n", printf("hehe"));
	// ft_printf("%p\n", ptr);
	// printf("%p\n", ptr);
	// ft_printf("%p\n", ptr2);
	// printf("%p\n", ptr2);
	// ft_printf("%p\n", NULL);
	// printf("%p\n", NULL);
	// // printf("this is a strin: %s. Test\n", "hehehe");
	return (0);
}
