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

NAME3 = visualizer

CC = @gcc

FLAGS = -Wall -Wextra -Werror -o

SRC1 = 	chckr/raps.c \
	chckr/checker.c \
	shared/stackops.c \
	shared/stackops2.c \
	shared/builder.c \
	shared/uts.c \
	shared/heap.c

SRC2 = algo/push_swap.c \
	algo/sort34.c \
	algo/algosort.c \
	algo/stackandprint.c \
	shared/heap.c \
	shared/builder.c \
	shared/stackops.c \
	shared/stackops2.c \
	shared/uts.c \
	shared/ranktools.c

SRC3 = visual/colors.c \
	visual/setcolor.c \
	visual/controlcol.c \
	chckr/raps.c \
	shared/heap.c \
	shared/builder.c \
	shared/stackops.c \
	shared/stackops2.c \
	shared/uts.c \
	shared/ranktools.c \

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

.PHONY: all clean fclean re both

clean:
	@rm -f $(OBJ1)
	@rm -f $(OBJ2)
	@rm -f $(OBJ3)
	@cd $(LIBDIR) && make clean

fclean: clean
	@rm -f $(NAME1)
	@rm -f $(NAME2)
	@rm -f $(NAME3)
	@cd $(LIBDIR) && make fclean

all: both

re: fclean all
