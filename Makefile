# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 01:50:24 by afrangio          #+#    #+#              #
#    Updated: 2019/03/15 16:45:42 by afrangio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Fix nvme for 2015 mbp

NAME			=	fdf
CC				=	clang
ONOSCOPE		=	-fsanitize=address	\
					-fno-omit-frame-pointer		\
					-fsanitize-address-use-after-scope -g
CFLAGS			:=	-Wall -Wno-cast-align\
					-Wextra
NOSCOPE			=	-g -std=c89 \
					-Weverything \
					-Wno-padded
SOURCES			=	srcs/main.c
INCLUDES		=	includes/fdf.h
SRCS 			=	$(SOURCES) 
OFILES			=	${SRCS:.c=.o}

LIBS			=	-lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): libft $(OFILES)
	$(CC) $(OFILES)  $(OFLAGS) $(LIBS) libft/libft.a -o $(NAME)

%.o: %.c $(INCLUDES)
	$(CC)  $< -c $(CFLAGS) -Iincludes -Ilibft/includes -o $@

noscope: CFLAGS += $(NOSCOPE) 
noscope: OFLAGS = $(ONOSCOPE)
noscope: all

libft: libft/libft.a

libft/libft.a:
	make -C libft/

clean:
	/bin/rm -f $(OFILES)
	make -C libft/ clean

fclean: clean
	make -C libft/ fclean
	@/bin/rm -f $(NAME)
	@/bin/rm -rf $(NAME).dSYM/

re: fclean all
