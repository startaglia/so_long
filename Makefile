# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: startagl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 17:42:29 by startagl          #+#    #+#              #
#    Updated: 2023/03/13 17:42:38 by startagl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c debug.c controller_files/map_edge.c controller_files/map_shape.c utils/get_next_line.c utils/get_next_line_str_utils.c utils/get_next_line_mem_utils.c utils/free_mem.c utils/itoa.c controller_files/map_values.c controller_files/file_type.c operations/win_op.c operations/img_op/en_img.c operations/img_op/sprite_tile_img.c operations/modify_val.c operations/sprite_op.c operations/player_movement.c operations/map_op.c operations/en_sprite_op.c operations/animations.c operations/set_animations.c operations/chainsaw_animations.c operations/r_police_animations.c operations/l_police_animations.c operations/string_op.c operations/condition_to_put_enemy.c

OBJ = ${SRCS:.c=.o}
NAME = so_long
LIBRARY := -lmlx -framework OpenGL -framework AppKit utils/ft_printf/libftprintf.a
MINILIBX := minilibx_2/
FTPRINTF := utils/ft_printf/

FLAG = -Wall -Werror -Wextra -g -O3
CC = gcc

.c.o:
	@${CC} -c $< -o ${<:.c=.o}

all	: $(NAME)

$(NAME) : $(OBJ)
	@make -C $(FTPRINTF)
	@$(CC) $(FLAG) $(OBJ) $(LIBRARY) -o $(NAME)
	
clean: 
	@make fclean -C $(FTPRINTF)
	@rm -f $(OBJ)
	
fclean:	clean
	@rm -f $(NAME)

re:	fclean all clean
