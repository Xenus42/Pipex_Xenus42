NAME        = pipex
HEADER      = pipex.h
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3 -I./
RM          = rm -f

vpath %.c src
vpath %.o obj

SRCS        = main.c \
			  main_utils.c \
			  get_path.c \
			  get_path_utils.c \
			  1st_child_process.c \
			  2nd_child_process.c \
			  2nd_child_process_utils.c
			  
OBJS        = $(SRCS:%.c=$(OBJS_DIR)/%.o)
OBJS_DIR	= obj
LIBFT_DIR   = 00-Libft
LIBFT       = $(LIBFT_DIR)/libft.a

$(OBJS_DIR)/%.o:%.c $(HEADER) Makefile
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT)

clean:
	$(RM) $(OBJS)
	$(RM) -rf $(OBJS_DIR)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all
