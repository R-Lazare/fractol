NAME	=	fractol

CC	=	cc

SRC =	main.c \
		Mandelbrot.c \
		minihelper.c \
		mymath.c \
		julia.c \
		colors.c

OBJ = ${SRC:.c=.o}
CFLAGS = -Wall -Wextra -Werror -g

.c.o:
	@$(CC) $(CFLAGS) -Iincludes/minilibx-linux -Iincludes -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	cd ./includes/minilibx-linux && ./configure && $(MAKE)
	$(CC) ${OBJ} -Iincludes/minilibx-linux includes/minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)

clean:
	@rm -rf ${OBJ}
	@cd ./includes/minilibx-linux && $(MAKE) clean

fclean: clean
	@rm -rf $(NAME)
	@cd ./includes/minilibx-linux && $(MAKE) clean

re: fclean all

.PHONY: all clean fclean re
