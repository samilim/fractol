NAME		= fractol
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
MLXFLAGS	= -Llmlx -LlXext -LlX11 -Lmlx -lmlx -Imlx_linux
AR 			= ar rcs
RM			= rm -f
IFLAGS		= -include fractol.h keycodes.h

SRCS 		= fractol.c \
			key_management.c \

SRCS_BONUS				= fractol_bonus.c \

SRCS_PATH	= srcs/
INC_PATH	= includes
OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) $(IFLAGS) $(MLXFLAGS) -o $@ -c $<

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)

bonus:		$(OBJS) $(OBJS_BONUS)
			$(AR) $(NAME) $(OBJS) $(OBJS_BONUS)

clean:
			$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all re clean fclean