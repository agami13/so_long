NAME	=	so_long

SRCS	=	srcs/so_long.c \
			srcs/parsing.c \
			srcs/parsing_utils.c \
			srcs/utils.c \
			srcs/movment.c \
			srcs/finish.c \
			srcs/floodfill.c \
			srcs/display_win.c \
			srcs/struct_fill.c \
			srcs/display_map.c \

OBJ		=	$(SRCS:.c=.o)

CC		=	cc

MLX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext -lm

CFLAGS	=	-Wall -Wextra -Werror

LIBFT	=	libft/libft.a

all: $(NAME)

$(NAME):	$(OBJ) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJ) -L libft/ $(MLX) -lft -o $(NAME)

$(LIBFT):
		make -s -C libft/

%.o	 : %.c
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJ)
			@$(MAKE) -s -C libft/ clean

fclean : clean
			@$(RM) $(NAME)
			@$(MAKE) -s -C libft/ fclean

re	: fclean all

.PHONY: all clean fclean re