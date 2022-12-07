FLAGS = -Wall -Werror -Wextra -g
SANITIZE = -fsanitize=address
TEST = ./unity/unity.c
LIBFT_TEST = ./test_libft.c
GNL_TEST = ./test_gnl.c
FT_PRINTF_TEST = ./test_ft_printf.c
CONVS = \
../conversions/convert_c.c		../conversions/convert_s.c		../conversions/convert_p.c

all: ft_printf

build:
	gcc $(FLAGS) main.c ../ft_printf.c ../libft/ft_ulongtohex.c $(CONVS) -L. -lft

ft_printf:
	gcc $(FLAGS) $(SANITIZE) $(TEST) $(FT_PRINTF_TEST) ../ft_printf.c ../libft/ft_ulongtohex.c $(CONVS) -L. -lft -o run_ft_printf
	./run_ft_printf
	rm ./outputs/test

clean:
	rm -f run_libft run_gnl run_ft_printf