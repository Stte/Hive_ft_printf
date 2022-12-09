NAME = libftprintf.a
CC = cc
FLAGS = -Wall -Werror -Wextra -c
CONVS = \
./conversions/convert_c.c			./conversions/convert_s.c		./conversions/convert_p.c		\
./conversions/convert_x.c			./conversions/convert_d.c		./conversions/convert_i.c		\
./conversions/convert_upper_x.c		./conversions/percent.c			./conversions/convert_u.c
CONVS_OBJ = $(CONVS:./conversions/%.c=%.o)
LIBFT = \
./libft/ft_bzero.c		./libft/ft_calloc.c		./libft/ft_isalnum.c	./libft/ft_isalpha.c		\
./libft/ft_isdigit.c	./libft/ft_itoa.c		./libft/ft_ltoa.c		./libft/ft_memcpy.c			\
./libft/ft_memset.c		./libft/ft_strchr.c		./libft/ft_strdup.c		./libft/ft_strjoin.c		\
./libft/ft_strlcpy.c	./libft/ft_strlen.c		./libft/ft_strmapi.c	./libft/ft_substr.c			\
./libft/ft_toupper.c	./libft/ft_ulongtohex.c
LIBFT_OBJ = $(LIBFT:./libft/%.c=%.o)
SRCS = \
ft_printf.c
SRCS_OBJ = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) $(CONVS)	$(LIBFT)
	ar rcs $(NAME) $(SRCS_OBJ) $(CONVS_OBJ) $(LIBFT_OBJ)

clean:
	rm -f $(SRCS_OBJ) $(CONVS_OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -f $(NAME) $(NAME:%.a=%_linux.a)

re: fclean all

linux:
	$(CC) $(FLAGS) $(SRCS) $(CONVS)	$(LIBFT)
	ar rcs $(NAME:%.a=%_linux.a) $(SRCS_OBJ) $(CONVS_OBJ) $(LIBFT_OBJ)
