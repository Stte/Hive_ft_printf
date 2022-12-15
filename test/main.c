#include "../inc/ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include "malloc_failer.h"

void	test_printf()
{
	char	*p = "";
	ft_printf(">%c%s%p%d%i%u%x%X%%<\n", 'a', "ajsdf", p, 1, 2, 3, 255, 255);
}

int	main(void)
{
	malloc_failer(test_printf);
	return (0);
}
