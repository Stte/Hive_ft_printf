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

	char *ptr = "hihii";
	char *ptr2 = ptr + 1;
	// // printf("\n%d\n", printf("hehe"));
	ft_printf("%p\n", ptr);
	printf("%p\n", ptr);
	ft_printf("%p\n", ptr2);
	printf("%p\n", ptr2);
	ft_printf("%p\n", NULL);
	printf("%p\n", NULL);
	// // printf("this is a strin: %s. Test\n", "hehehe");
	return (0);
}