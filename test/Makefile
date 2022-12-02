FLAGS = -Wall -Werror -Wextra -g
BUFFER_SIZE = -D BUFFER_SIZE=42
SANITIZE = -fsanitize=address
TEST = ./unity/unity.c
LIBFT_TEST = ./test_libft.c
GNL_TEST = ./test_gnl.c

all: libft gnl

libft:
	gcc $(FLAGS) $(SANITIZE) $(TEST) $(LIBFT_TEST) -L.. -lft -o run_libft
	./run_libft

gnl:
	$(CC) $(FLAGS) $(SANITIZE) $(TEST) $(GNL_TEST) -L.. -lft -o run_gnl
	./run_gnl

clean:
	rm -f run_libft run_gnl
