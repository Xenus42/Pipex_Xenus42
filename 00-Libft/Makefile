NAME 		= 	libft.a

CC 			=	cc

CFLAGS 		= 	-Wall -Wextra -Werror -I.

CPPFLAGS	=	-MD -MP

RM			=	rm -rf

vpath %.c src
-include $(DEPS)


SRCS 		= 	ft_atoi.c\
				ft_bzero.c\
				ft_calloc.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoa.c\
				ft_lstadd_front_bonus.c\
				ft_lstnew_bonus.c\
				ft_lstsize_bonus.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memset.c\
				ft_putchar_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_putstr_fd.c\
				ft_split.c\
				ft_strchr.c\
				ft_strdup.c\
				ft_striteri.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strmapi.c\
				ft_strncmp.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strtrim.c\
				ft_substr.c\
				ft_tolower.c\
				ft_toupper.c

DEPS		= 	$(SRCS:%.c=$(OBJS_DIR)%.d)

OBJS		=	${SRCS:%.c=$(OBJS_DIR)%.o}

OBJS_DIR	=	obj/


all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)%.o: %.c Makefile libft.h
	mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_DIR)

fclean:	clean
	$(RM) $(NAME)

re:	fclean $(NAME)


.PHONY : all clean fclean re