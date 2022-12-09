FLAGS = -Wall -Werror -Wextra -g
SANITIZE = -fsanitize=address
WRAP = -Wl,-wrap,malloc
TEST = ./unity/unity.c
LIBFT_TEST = ./test_libft.c
GNL_TEST = ./test_gnl.c
FT_PRINTF_TEST = ./test_ft_printf.c
CONVS = \
../conversions/convert_c.c			../conversions/convert_s.c		../conversions/convert_p.c		\
../conversions/convert_x.c			../conversions/convert_d.c		../conversions/convert_i.c		\
../conversions/convert_upper_x.c	../conversions/percent.c		../conversions/convert_u.c

all: ft_printf

compile:
	gcc $(FLAGS) main.c ../ft_printf.c $(CONVS) -L. -lft

ft_printf:
	gcc $(FLAGS) $(SANITIZE) $(TEST) $(FT_PRINTF_TEST) ../ft_printf.c $(CONVS) -L. -lft -o run_ft_printf
	./run_ft_printf
	rm ./test_output

malloc_failer:
	gcc $(FLAGS) $(WRAP) ./main.c ./malloc_failer.c ../ft_printf.c $(CONVS) -L. -lft_linux -o run_test
	valgrind --leak-check=full --show-leak-kinds=all ./run_test

clean:
	rm -fr run_ft_printf* run_test* a.out*
