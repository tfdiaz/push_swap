# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/17 12:28:34 by tdiaz             #+#    #+#              #
#    Updated: 2018/08/17 12:28:41 by tdiaz            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap

NAME3 = colormap

CC = @gcc

FLAGS = -Wall -Wextra -Werror -o

SRC1 = stackops.c checker.c builder.c uts.c

SRC2 = push_swap.c heap.c builder.c stackops.c uts.c

SRC3 = colors.c

OBJ1 = $(SRC1:.c=.o)

OBJ2 = $(SRC2:.c=.o)

OBJ3 = $(SRC3:.c=.o)

LIBDIR = libft

LIB = $(LIBDIR)/libft.a

both: $(NAME1) $(NAME2) $(NAME3)

$(NAME1): $(OBJ1) $(LIB)
	$(CC) $(FLAGS) $@ $(OBJ1) $(LIB)

$(NAME2): $(OBJ2) $(LIB)
	$(CC) $(FLAGS) $@ $(OBJ2) $(LIB)

$(NAME3): $(OBJ3) $(LIB)
	$(CC) $(FLAGS) $@ $(OBJ3) $(LIB)

$(LIB):
	@cd $(LIBDIR) && make 

.PHONY: all clean fclean re both debug

debug1: $(OBJ1) $(LIB)
	$(CC) -o debugger1 -g $(SRC1) $(LIB)

debug2: $(OBJ2) $(LIB)
	$(CC) -o debugger2 -g $(SRC2) $(LIB)

clean:
	@rm -f $(OBJ1)
	@rm -f $(OBJ2)
	@cd $(LIBDIR) && make clean

fclean: clean
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@rm -r debugger1
	@rm -r debugger2
	@rm -rf debugger1.dSYM
	@rm -rf debugger2.dSYM
	@cd $(PRINTDIR) && make fclean

all: $(NAME)
