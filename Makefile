# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfiguera <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/04 14:41:01 by mfiguera          #+#    #+#              #
#    Updated: 2018/01/04 14:50:09 by mfiguera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FILES = ft_main ft_parsing ft_sidefunctions ft_solving
SRCS_DIR = srcs
OBJ_DIR = obj
INCL_DIR = incl
SRCS = $(addprefix $(SRCS_DIR)/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(FILES)))
HEAD = $(addprefix $(INCL_DIR)/, $(INCLUDES))
INCLUDES = fillit.h
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@gcc $(FLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c $(HEAD)
	@gcc $(FLAGS) -c $< -o $@ -I $(INCL_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)
