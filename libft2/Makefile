# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huaydin <huaydin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/16 17:53:16 by huaydin           #+#    #+#              #
#    Updated: 2022/10/24 21:28:54 by huaydin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libft.a
SRCS        = ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_striteri.c \
ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  \
ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c 

SRCS_BONUS = ft_lstmap.c ft_lstnew.c ft_lstiter.c ft_lstlast.c \
ft_lstsize.c ft_lstclear.c ft_lstdelone.c ft_lstadd_back.c ft_lstadd_front.c

OBJS		= $(SRCS:%.c=%.o)
OBJS_BONUS	= $(SRCS_BONUS:%.c=%.o)
CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -f
LIBC		= ar rcs

.PHONY:		all clean fclean re bonus

all:		$(NAME)

$(NAME):	$(OBJS) 
			$(LIBC) $(NAME) $(OBJS)

%.o: %.c
			$(CC) -c $(CFLAGS) $?

bonus: fclean
	$(CC) $(CFLAGS) -c $(SRCS) $(SRCS_BONUS)
	$(LIBC) $(NAME) $(OBJS) $(OBJS_BONUS)

$(OBJS_BONUS):	$(SRCS_BONUS)
	

clean:          
			@$(RM) $(OBJS) $(OBJS_BONUS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean $(NAME)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(SRCS_BONUS)
	$(CC) -nostartfiles -shared -o libft.so $(OBJS) $(OBJS_BONUS)
