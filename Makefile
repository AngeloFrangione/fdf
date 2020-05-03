# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anonymous <anonymous@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 01:50:24 by afrangio          #+#    #+#              #
#    Updated: 2020/05/03 23:39:31 by anonymous        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ONOSCOPE		=	-fsanitize=address	\
# 					-fno-omit-frame-pointer		\
# 					-fsanitize-address-use-after-scope


NAME			=	fdf
CC				=   gcc -g

CFLAGS			:=	-Wall \
					-Wextra \
					-Iincludes/ \
					-Ilibft/includes/

LDFLAGS			:=  libft/libft.a -lm
LINUX			=   minilibx_linux/libmlx_x86_64.a -lX11 -lXext
MACOS			=   -framework OpenGL

IMACOS			=   -Iminilibx_macos/
ILINUX			=   -Iminilibx_linux/

MLX_LINUX		=   minilibx_linux
MLX_MACOS		=   minilibx_macos

INCLUDES 		=   includes/fdf.h
SRCS			=	srcs/main.c \
					srcs/bresenham.c





OBJECTS			=	${SRCS:.c=.o}


UNAME_S := $(shell uname -s)
NPROC := $(nproc)

ifeq ($(UNAME_S),Linux)
	LDFLAGS := $(LDFLAGS) $(LINUX)
	CFLAGS := $(CFLAGS) $(ILINUX)
	MLX = $(MLX_LINUX)
endif
ifeq ($(UNAME_S),Darwin)
	LDFLAGS := $(LDFLAGS) $(MACOS)
	CFLAGS := $(CFLAGS) $(IMACOS)
	MLX = $(MLX_MACOS)
endif



all: $(NAME)

$(NAME): mlx libft $(OBJECTS)
	@echo linking objects
	$(CC) $(OBJECTS)  $(LDFLAGS) -o $(NAME)

%.o: %.c $(INCLUDES)
	@echo compiling objects
	$(CC) -c $(CFLAGS) -o $@ $<


libft: libft/libft.a

mlx:
	make -C $(MLX)

libft/libft.a:
	make -C libft/ -j$(NPROC)

clean:
	make -C $(MLX) clean
	make -C libft/ clean
	rm -f $(OBJECTS)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
