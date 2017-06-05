# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaunovi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/10 17:35:29 by dpaunovi          #+#    #+#              #
#    Updated: 2017/04/21 13:41:29 by dpaunovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \
	setup.c \
	run.c \
	bind.c \
	mandelbrot.c \
	julia.c \
	ship.c \
	bird.c \
	ito.c \

OBJS = $(addprefix srcs/,$(SRCS:.c=.o))

NAME = fractol
CC = gcc
FLAGS = -Wall -Wextra -Werror -Ofast
INCS = includes -I libft

GREEN = \x1b[32m
EOC = \x1b[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(GREEN)[compiling libft]$(EOC)"
	@make -C libft
	@make -C minilibx
	@gcc $(FLAGS) -o $(NAME) libft/libft.a minilibx/libmlx.a $(OBJS) \
	-framework OpenGL -framework AppKit
	@echo "$(GREEN)[$(NAME)]$(EOC)"@make -C libft

srcs/%.o: srcs/%.c
	@$(CC) $(FLAGS) -I $(INCS) -I minilibx -o $@ -c $<
	@echo "[$@]"

clean:
	@make clean -C libft
	@rm -f $(OBJS)
	@echo "$(GREEN)[objs removed]$(EOC)"

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "$(GREEN)[workspace clean]$(EOC)"

re: fclean all
