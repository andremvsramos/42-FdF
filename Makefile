# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andvieir <andvieir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 13:54:18 by andvieir          #+#    #+#              #
#    Updated: 2023/04/04 14:21:12 by andvieir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
BONUS = fdf_bonus
LIBFT = libft.a
MLX = libmlx.a

SRCDIR = ./src/
LIBFTDIR = ./libft/
HEADERDIR = ./headers/
MLXDIR = ./minilibx-linux/

SRC =		src/colors.c \
			src/draw.c \
			src/fdf_init.c \
			src/main.c \
			src/mem.c \
			src/read_file.c \
			src/refresh.c \
			src/utils.c \
			src/win_ctrl.c \

BONUS_SRC =	bonus/colors_bonus.c \
			bonus/draw_bonus.c \
			bonus/fdf_init_bonus.c \
			bonus/main_bonus.c \
			bonus/mem_bonus.c \
			bonus/read_file_bonus.c \
			bonus/refresh_bonus.c \
			bonus/utils_bonus.c \
			bonus/win_ctrl_bonus.c \

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -rf
MLXFLAGS = -L -lmlx -lXext -lX11
MATH = -lm

OBJ = ${SRC:.c=.o}
BONUS_OBJ = ${BONUS_SRC:.c=.o}


.c.o:
			$(CC) $(CFLAGS) -c -I$(HEADERDIR) $< -o ${<:.c=.o}

all:		$(NAME)

$(LIBFT):
			cd $(LIBFTDIR) && $(MAKE)

$(MLX):
			cd $(MLXDIR) && $(MAKE)

$(NAME):	$(OBJ) $(LIBFT) $(MLX)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFTDIR)$(LIBFT) $(MLXDIR)$(MLX) $(MLXFLAGS) $(MATH) -o $(NAME)

bonus:		$(BONUS_OBJ) $(LIBFT) $(MLX)
			$(CC) $(CFLAGS) $(OBJ_CHECKER) $(LIBFTDIR)$(LIBFT) $(MLXDIR)$(MLX) $(MLXFLAGS) $(MATH) -o $(BONUS)

clean:
			@$(RM) $(OBJ) $(BONUS_OBJ)
			@cd $(LIBFTDIR) && $(MAKE) clean

fclean:		clean
			@$(RM) $(NAME) $(BONUS) $(LIBFT) $(MLX)
			@cd $(LIBFTDIR) && $(MAKE) fclean
			@cd $(MLXDIR) && $(MAKE) clean

aclean:		all clean

re:			fclean all
