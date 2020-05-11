# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 01:50:24 by afrangio          #+#    #+#              #
#    Updated: 2020/05/11 18:31:24 by afrangio         ###   ########.fr        #
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
					-Ilibft/includes/ \


LDFLAGS			:=  libft/libft.a -lm   \
					-fsanitize=address	\
					-fno-omit-frame-pointer	\
					-fsanitize-address-use-after-scope
LINUX			=   minilibx_linux/libmlx_x86_64.a -lX11 -lXext
MACOS			=   minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

IMACOS			=   -Iminilibx_macos/
ILINUX			=   -Iminilibx_linux/

MLX_LINUX		=   minilibx_linux
MLX_MACOS		=   minilibx_macos

INCLUDES 		=   includes/fdf.h
SRCS			=	srcs/main.c \
					srcs/put_segment.c \
					srcs/read_map.c \
					srcs/parsing.c \
					srcs/put_pixel.c \
					srcs/projection.c \
					srcs/mlx.c \
					srcs/update_caption.c \
					srcs/rotation.c \
					srcs/hooks.c \
					srcs/keys_move.c \
					srcs/keys_rotate.c \
					srcs/keys_other.c \
					srcs/link_points.c 

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



all: mlx libft $(NAME)

$(NAME): $(OBJECTS) 
	@echo linking objects
	$(CC) $(OBJECTS)  $(LDFLAGS) -o $(NAME)

%.o: %.c $(INCLUDES)
	@echo compiling objects
	$(CC) -c $(CFLAGS) -o $@ $<


libft: libft/libft.a

mlx: $(MLX)
	@make -C $(MLX)

libft/libft.a:
	@make -C libft/ -j$(NPROC)

clean:
	@make -C $(MLX) clean
	@make -C libft/ clean
	@rm -f $(OBJECTS)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
