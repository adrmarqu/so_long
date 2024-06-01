# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adrmarqu <adrmarqu@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/20 17:22:39 by adrmarqu          #+#    #+#              #
#    Updated: 2024/04/22 11:32:11 by adrmarqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
BNAME = so_long_bonus

INCLUDE = include/so_long.h
LIBFT = ./libft/libft.a
MLX = ./libft/mlx/libmlx.a

CFLAGS = -Wall -Wextra -Werror 

SRC = $(wildcard src/game/*c src/common/*c)
OBJ = $(SRC:.c=.o)

BSRC = $(wildcard src/bonus/*c src/common/*c)
BOBJ = $(BSRC:.c=.o)

all: _libft _mlx $(NAME)

bonus: _libft _mlx $(BNAME)

%.o: %.c $(INCLUDE) Makefile include/color.h
	$(CC) $(CFLAGS) -Imlx -c $< -o $@ -Iinclude

$(NAME): Makefile $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -framework OpenGL -framework Appkit -l z -o $(NAME)

$(BNAME): Makefile $(BOBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(BOBJ) $(LIBFT) $(MLX) -framework OpenGL -framework Appkit -l z -o $(BNAME)

_libft:
	@make -C ./libft

_mlx:
	@make -C ./libft/mlx

clean:
	@make clean -C ./libft
	@make clean -C ./libft/mlx
	$(RM) $(OBJ) $(BOBJ)

fclean: clean
	@make fclean -C ./libft
	@make clean -C ./libft/mlx
	$(RM) $(NAME) $(BNAME)

re: fclean all

.PHONY: all clean fclean re
