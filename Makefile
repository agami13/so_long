NAME	=	so_long

LIB		=	libft.a

SRCS	=	srcs/so_long.c \
			srcs/parsing.c \
			srcs/parsing_utils.c \
			srcs/utils.c \
			srcs/map_blocked.c \
			srcs/display_win.c \

OBJ		=	$(SRCS:.c=.o)

CC		=	cc

MLX = -Lminilibx-linux -lmlx_Linux -lX11 -lXext

CFLAGS	=	-Wall -Wextra -Werror

LIB_PATH =	libft/

all: $(NAME)

$(NAME):	$(OBJ) $(LIB_PATH) $(LIB)
			$(CC) $(CFLAGS) $(OBJ) -L $(LIB_PATH) $(MLX) -lft -o $(NAME)

$(LIB_PATH) $(LIB):
			$(MAKE) -s -C $(LIB_PATH)

%.o	 : %.c
			$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJ)
			$(MAKE) -s -C $(LIB_PATH) clean

fclean : clean
			$(RM) $(NAME)
			$(MAKE)	-s -C	$(LIB_PATH)	fclean

re	: fclean all

.PHONY: all clean fclean re