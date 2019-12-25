# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: belhatho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/12 21:15:08 by belhatho          #+#    #+#              #
#    Updated: 2019/11/21 18:08:50 by aait-el-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls

SRC = create_args.c details_parse.c details_parse1.c details_parse2.c\
	display.c display2.c display_all.c display_clmns.c flags.c free_all.c main.c\
	parse_arg.c sort.c sort2.c spaces.c spaces2.c spaces3.c stat_args.c\
	stat_dir.c tri.c tri2.c

SRCS = $(SRC:%=srcs/%)

LIBFT_DIR = srcs/libft

OBJS = $(SRC:%.c=objs/%.o)

CFLAG	= -Wall -Wextra -Werror

CREATE_OBJ = objs

all : $(NAME)
	@echo > /dev/null

$(NAME) : $(CREATE_OBJ) $(OBJS)
	@make -C $(LIBFT_DIR)
	@gcc $(CFLAG) $(OBJS) $(LIBFT_DIR)/libft.a -o $(NAME)

$(CREATE_OBJ):
	@mkdir -p $@

objs/%.o: srcs/%.c include/ft_ls.h
	@gcc $(CFLAG) -c $< -o $@

clean :
	@rm -rf $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean : clean
	@rm -rf $(NAME)
	@make -C $(LIBFT_DIR) fclean

re : fclean all

.PHONY: all clean fclean re
