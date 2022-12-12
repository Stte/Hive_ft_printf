NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Werror -Wextra -c
CONVS = \
./conversions/convert_c.c			./conversions/convert_s.c		./conversions/convert_p.c		\
./conversions/convert_x.c			./conversions/convert_d.c		./conversions/convert_i.c		\
./conversions/convert_upper_x.c		./conversions/percent.c			./conversions/convert_u.c
CONVS_OBJ = $(CONVS:./conversions/%.c=%.o)
SRCS = \
ft_printf.c
SRCS_OBJ = $(SRCS:.c=.o)
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a


all: $(NAME)

$(NAME): $(SRCS_OBJ) $(LIBFT)
	$(CC) $(FLAGS) $(SRCS) $(CONVS)
	ar rcs $(NAME) $(SRCS_OBJ) $(CONVS_OBJ) $(LIBFT)

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

clean:
	rm -f $(SRCS_OBJ) $(CONVS_OBJ) $(LIBFT_OBJ)
	make clean -C ./libft

fclean: clean
	rm -f $(NAME) $(NAME:%.a=%_linux.a)
	make fclean -C ./libft

re: fclean all

linux:
	make linux -C ./libft
	cp $(LIBFT:%.a=%_linux.a) $(NAME:%.a=%_linux.a)
	$(CC) $(FLAGS) $(SRCS) $(CONVS)
	ar rcs $(NAME:%.a=%_linux.a) $(SRCS_OBJ) $(CONVS_OBJ) $(LIBFT_OBJ)
