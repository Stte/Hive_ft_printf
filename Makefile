NAME 		= libftprintf.a

S			= src/
O			= obj/
I			= inc/

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -c -I$I

AR			= ar
ARFLAGS		= rcs

SRC = \
$S/convert_c.c			$S/convert_s.c		$S/convert_p.c		\
$S/convert_x.c			$S/convert_d.c		$S/convert_i.c		\
$S/convert_upper_x.c	$S/percent.c		$S/convert_u.c		\
$S/ft_printf.c
OBJ			= $(SRC:$S%=$O%.o)

RM			= /bin/rm -f
RMDIR		= /bin/rmdir

LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re

all: $(NAME)

$O:
	@mkdir $@

$(OBJ): | $O

$(OBJ): $O%.o: $S%
	$(CC) $(CFLAGS) $< -o $@

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)
	$(AR) $(ARFLAGS) $@ $(OBJ)

$(LIBFT):
	make -C $(LIBFT_DIR)
	cp $(LIBFT) $(NAME)

cleanobj:
	$(RM) $(wildcard $(OBJ))

cleanobjdir: cleanobj
	$(RMDIR) $O

clean: cleanobjdir

fclean: clean
	$(RM) $(NAME)

re: fclean all
