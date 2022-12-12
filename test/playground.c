#include "../headers/ft_printf.h"
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	printf("+%c %c %c\n", '0', 0, '1');
	ft_printf("-%c %c %c\n", '0', 0, '1');
	printf("+%c %c %c\n", '2', '1', 0);
	ft_printf("-%c %c %c\n", '2', '1', 0);
	printf("+%c %c %c\n", 0, '1', '2');
	ft_printf("-%c %c %c\n", 0, '1', '2');
	return (0);
}
