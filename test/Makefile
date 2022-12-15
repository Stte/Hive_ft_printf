FLAGS = -Wall -Werror -Wextra -g
SANITIZE = -fsanitize=address
WRAP = -Wl,-wrap,malloc
TEST = ./unity/unity.c
LIBFT_TEST = ./test_libft.c
GNL_TEST = ./test_gnl.c
FT_PRINTF_TEST = ./test_ft_printf.c

.PHONY: all build ft_printf setup_failer malloc_failer clean fclean playground

all: build ft_printf setup_failer clean

build:
	make -C ../

ft_printf:
	gcc $(FLAGS) $(SANITIZE) $(TEST) $(FT_PRINTF_TEST) -L.. -lftprintf -o run_ft_printf
	./run_ft_printf
	rm -f test_output

setup_failer: fclean
	sh malloc_failer_setup.sh

malloc_failer:
	gcc $(FLAGS) $(WRAP) ./main.c ./malloc_failer.c -L.. -lftprintf -o run_test
	valgrind --leak-check=full --show-leak-kinds=all ./run_test

run_failer:
	docker exec -ti printf_malloc_failer make malloc_failer -C ./test

clean:
	rm -fr run_ft_printf* run_test* a.out* run_playground*

fclean:
	make fclean -C ..
	make fclean -C ../libft

playground:
	make -C ..
	gcc $(FLAGS) $(SANITIZE) playground.c -L.. -lftprintf -o run_playground
	./run_playground
