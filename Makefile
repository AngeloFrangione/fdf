# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 01:50:24 by afrangio          #+#    #+#              #
#    Updated: 2020/05/19 05:08:56 by afrangio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	fdf
CC				=	gcc

CFLAGS			:=	-Wall \
					-Wextra \
					-Iincludes/ \
					-Ilibft/includes/ \

LDFLAGS			:=	libft/libft.a -lm

IMACOS			=	-Iminilibx_macos/
ILINUX			=	-Iminilibx_linux/

MLX_LINUX		=	minilibx_linux/
MLX_MACOS		=	minilibx_macos/

MLX_F_LINUX		:=	libmlx.a
MLX_F_MAC		:=	libmlx.a

MLX_LIB_LINUX	=	$(MLX_LINUX)$(MLX_F_LINUX)
MLX_LIB_MAC		=	$(MLX_MACOS)$(MLX_F_MAC)

LINUX			=	$(MLX_LIB_LINUX) -lX11 -lXext
MACOS			=	$(MLX_LIB_MAC) -framework OpenGL -framework AppKit

INCLUDES 		=	includes/fdf.h
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

UNAME_S			:=	$(shell uname -s)
NPROC			:=	$(nproc)

ifeq ($(UNAME_S),Linux)
	LDFLAGS		:=	$(LDFLAGS) $(LINUX)
	CFLAGS		:=	$(CFLAGS) $(ILINUX)
	MLX_PATH	=	$(MLX_LINUX)
	MLX			=	$(MLX_LIB_LINUX)
endif
ifeq ($(UNAME_S),Darwin)
	LDFLAGS		:=	$(LDFLAGS) $(MACOS)
	CFLAGS		:=	$(CFLAGS) $(IMACOS)
	MLX_PATH	=	$(MLX_MACOS)
	MLX			=	$(MLX_LIB_MAC)
endif

all: $(NAME)

$(NAME): $(MLX) libft $(OBJECTS) 
	@echo linking objects
	$(CC) $(OBJECTS)  $(LDFLAGS) -o $(NAME)

%.o: %.c $(INCLUDES)
	@echo compiling objects
	$(CC) -c $(CFLAGS) -o $@ $<


libft: libft/libft.a

$(MLX):
	@make -C $(MLX_PATH)

libft/libft.a:
	@make -C libft/ -j$(NPROC)

clean:
	@make -C $(MLX_PATH) clean
	@make -C libft/ clean
	@rm -f $(OBJECTS)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all
