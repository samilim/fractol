NAME		= fractol
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
MLXFLAGS	= -lm -lbsd -lX11 -lXext
AR 			= ar rcs
RM			= rm -f
IFLAGS		= -Iincludes/ -Imlx_linux #includes/fractol.h includes/keycodes.h mlx_linux/mlx.h mlx_linux/mlx_int.h
SRCS_PATH	:= srcs
BONUS_PATH	:= bonus
LIBFT_PATH	:= libft
MLX_PATH	:= mlx_linux

SRCS 		:= $(wildcard $(SRCS_PATH)/*.c fractal_sets/*.c)
SRCS_BONUS	:= $(wildcard $(BONUS_PATH)/*.c) # fractal_sets/*.c)
LIBFT		:= $(wildcard $(LIBFT_PATH)/*.c)

OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)
LIB_OBJS	= $(LIBFT:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(LIB_OBJS) dependencies
			$(CC) $(CFLAGS) $(IFLAGS) $(OBJS) $(LIB_OBJS) ./mlx_linux/libmlx.a $(MLXFLAGS) -o $(NAME)

#%.o: %.c	$(SRCS_PATH)/%.c $(LIBFT_PATH)/%.c
#			$(CC) $(CFLAGS) $(IFLAGS) $(MLXFLAGS) -o $@ -c $<


bonus:		$(OBJS_BONUS) $(LIB_OBJS) dependencies
			$(CC) $(CFLAGS) $(IFLAGS) $(OBJS_BONUS) $(LIB_OBJS) ./mlx_linux/libmlx.a $(MLXFLAGS) -o $(NAME)

dependencies :
		make -C ./mlx_linux

clean:
			$(RM) $(OBJS) $(OBJS_BONUS) $(LIB_OBJS)
			make clean -C ./mlx_linux

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all re clean fclean bonus