NAME	=	libft.a
CFLAGS	=	-Wall -Wextra -Werror

HEADERS	=	libft.h \
			get_next_line.h \
			ft_printf.h

SRCS	=	ft_isascii.c \
			ft_memcpy.c \
			ft_strjoin.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_isdigit.c \
			ft_memmove.c \
			ft_strlcat.c \
			ft_strrchr.c \
			ft_bzero.c \
			ft_isprint.c \
			ft_memset.c \
			ft_strlcpy.c \
			ft_strtrim.c \
			ft_calloc.c \
			ft_itoa.c \
			ft_split.c \
			ft_strlen.c \
			ft_substr.c \
			ft_isalnum.c \
			ft_memchr.c \
			ft_strchr.c \
			ft_strmapi.c \
			ft_tolower.c \
			ft_isalpha.c \
			ft_memcmp.c \
			ft_strdup.c \
			ft_strncmp.c \
			ft_toupper.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_printf.c \
			ft_functions.c \
			ft_display_arg.c \
			ft_putnbr_base.c

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

%.o: %.c 	$(HEADERS) Makefile
			$(CC) $(CFLAGS) -g3 -c $< -o $@ -I .

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re