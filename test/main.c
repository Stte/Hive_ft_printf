#include "../ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char	*hex;

	hex = ft_itohex(255);
	hex = ft_itohex(0);
	hex = ft_itohex(9);
	hex = ft_itohex(10);
	hex = ft_itohex(11);
	hex = ft_itohex(12);
	hex = ft_itohex(13);
	hex = ft_itohex(14);
	hex = ft_itohex(15);
	hex = ft_itohex(16);
	hex = ft_itohex(1024);

	if (hex)
		hex = NULL;
	// char *ptr = "hihii";
	// // printf("\n%d\n", printf("hehe"));
	// ft_printf("%p\n", ptr);
	// // printf("this is a strin: %s. Test\n", "hehehe");
	return (0);
}
