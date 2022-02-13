NAME		= fractol
CC			= gcc
CFLAGS		= 
#MLXFLAGS	= -Llmlx -LlXext -LlX11 -Lmlx -lmlx -Imlx_linux
#MLXFLAGS	= -lbsd -lmlx -L/usr/lib -Lmlx_linux -lXext -lX11 -lm 
MLX_FLAGS	= -lbsd -lmlx -L/usr/lib -Lmlx_linux -lXext -lX11 -lm -I./lib/mlx_linux mlx_linux/mlx.h mlx_linux/mlx_int.h -I/usr/include -Imlx_linux -O3 -c $< -o $@
AR 			= ar rcs
RM			= rm -f
IFLAGS		= include/fractol.h includes/keycodes.h includes/colors.h -I/usr/include -I./lib/mlx_linux mlx_linux/mlx.h mlx_linux/mlx_int.h
SRCS_PATH	:= srcs
BONUS_PATH	:= bonus
LIBFT_PATH	:= libft
MLX_PATH	:= mlx_linux

SRCS 		:= $(wildcard $(MLX_PATH)/*.c $(SRCS_PATH)/*.c fractal_sets/*.c)
SRCS_BONUS	:= $(wildcard $(BONUS_PATH)/*.c $(MLX_PATH)/*.c fractal_sets/*.c)
LIBFT		:= $(wildcard $(LIBFT_PATH)/*.c)

OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)
LIB_OBJS	= $(LIBFT:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS) $(LIB_OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_OBJS)

%.o: %.c	$(MLX_PATH)/%.c $(SRCS_PATH)/%.c $(LIBFT_PATH)/%.c
			$(CC) $(CFLAGS) $(MLXFLAGS) $(IFLAGS) -o $@ -c $<

bonus:		$(OBJS_BONUS) $(LIB_OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS_BONUS) $(LIB_OBJS)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS) $(LIB_OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all re clean fclean bonus