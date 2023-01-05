# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpupier <lpupier@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 08:32:06 by lpupier           #+#    #+#              #
#    Updated: 2023/01/05 13:00:22 by lpupier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Constants
NAME		=	push_swap
CFLAGS		=	-Wall -Wextra -Werror

# Directories path
DIR_SRCS	=	sources/
DIR_HEADERS	=	headers/
DIR_LIBFT	=	libft/
LIBFT		=	$(DIR_LIBFT)libft.a

# Files path
HEADERS	=	$(DIR_HEADERS)push_swap.h

SRCS	=	$(DIR_SRCS)main.c \
			$(DIR_SRCS)numbers_gestion.c \
			$(DIR_SRCS)sort.c \
			$(DIR_SRCS)utils.c \
			$(DIR_SRCS)algo.c

OBJS	=	$(SRCS:.c=.o)

# Rules
.PHONY :	all re clean fclean FORCE watermark

all :	 	${NAME}

%.o: %.c	$(HEADERS) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

${NAME}:	$(LIBFT) ${OBJS}
			$(CC) $(CFLAGS) $(OBJS) $(DIR_LIBFT)libft.a -o $(NAME)

$(LIBFT):	FORCE
			$(MAKE) -C $(DIR_LIBFT)

clean:
			${RM} ${OBJS}
			make clean -C $(DIR_LIBFT)

fclean:		clean
			${RM} ${NAME} 
			make fclean -C $(DIR_LIBFT)

re :		fclean all

watermark:
			@echo "$$WATERMARK"

FORCE:

# Text art
define WATERMARK

██╗  ██╗██████╗ 
██║  ██║╚════██╗ name:  Leon Pupier
███████║ █████╔╝ login: lpupier
╚════██║██╔═══╝  
     ██║███████╗
     ╚═╝╚══════╝lyon.fr

endef
export WATERMARK