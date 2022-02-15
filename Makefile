NAME		= fractol
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
#MLXFLAGS	= -lbsd -lmlx -Lmlx_linux -lXext -lX11 -lm
AR 			= ar rcs
RM			= rm -f
# directories
INC_PATH	:= includes
SRCS_PATH	:= srcs
BONUS_PATH	:= bonus

SRCS 		:= $(wildcard $(SRCS_PATH)/*.c fractal_sets/*.c)
SRCS_BONUS	:= $(wildcard $(BONUS_PATH)/*.c)

# mlx
MLX_PATH	:= mlx_linux/
MLX_LIB		= $(addprefix $(MLX_PATH),libmlx_Linux.a)
MLX_INC		= -I $(MLX_PATH)
MLX_LNK		:= -L $(MLX_PATH) -l mlx -lXext -lX11

# libft
LIBFT_PATH	:= libft/
LIBFT_LIB	= $(addprefix $(LIBFT_PATH),libft.a)
LIBFT_INC	= -I ./libft
LIBFT_LNK	= -L ./libft -l ft -l pthread


OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all:		$(LIBFT_LIB) $(MLX_LIB) $(NAME)

%.o: %.c	$(SRCS_PATH)/%.c
			$(CC) $(CFLAGS) $(MLX_INC) $(LIBFT_INC) -I $(INC_PATH) -o $@ -c $<

$(LIBFT_LIB):
	@make -C $(LIBFT_PATH)

$(MLX_LIB):
	@make -C $(MLX_PATH)

$(NAME):	$(OBJS)
			$(CC) $(OBJS) $(MLX_LNK) $(LIBFT_LNK) -lm -o $(NAME)

bonus:		$(LIBFT_LIB) $(MLX_LIB) $(OBJS_BONUS)
			$(CC) $(OBJS_BONUS) $(LIBFT_LNK) $(MLX_LNK) -lm -o $(NAME)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS) $(LIB_OBJS)
			make -C $(LIBFT_PATH) clean
			make -C $(MLX_PATH) clean

fclean:		clean
			$(RM) $(NAME)
			make -C $(LIBFT_PATH) fclean

re:			fclean all

.PHONY:		all re clean fclean bonus