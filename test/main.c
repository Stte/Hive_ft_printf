#include "../ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	char *ptr = "hihii";
	// printf("\n%d\n", printf("hehe"));
	ft_printf("%p\n", ptr);
	// printf("this is a strin: %s. Test\n", "hehehe");
	return (0);
}
