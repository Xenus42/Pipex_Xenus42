NAME        = pipex
HEADER      = pipex.h
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3
RM          = rm -f

SRCS        = pipex.c
OBJS        = $(SRCS:%.c=%.o)

LIBFT_DIR   = ../00-Libft
LIBFT       = $(LIBFT_DIR)/libft.a

all: $(NAME) $(LIBFT)

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C ../00-Libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
