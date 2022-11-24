# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msariasl <msariasl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 21:32:18 by msariasl          #+#    #+#              #
#    Updated: 2022/10/27 15:53:38 by msariasl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = $(shell find . -type f ! -name "ft_lst*.c" -name "ft_*.c")
FILES = $(shell find . -name "*.c" ! -name "main.c")
OBJ = $(SRC:.c=.o)
BSRC = $(wildcard ft_lst*.c)
B_OBJ = $(BSRC:.c=.o)
NORM = norminette $(FILES) && norminette libft.h
FLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar -rc
FONAME = IAMReadyToPushLibft
TARGET = ../
DEST = $(TARGET)$(FONAME)
NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
		ar -rc $(NAME) $(OBJ)

all: $(NAME)

bonus: $(OBJ) $(B_OBJ)
	ar -rc $(NAME) $(OBJ) $(B_OBJ)

clean:
	$(RM) *.o && $(RM) *.out

fclean:
	make clean
	$(RM) $(NAME)

re:
	$(RM) $(NAME)
	$(MAKE)

release:
	$(RM) $(NAME)
	$(MAKE)
	$(RM) *.o
	$(NORM)

debug:
	clear
	gcc *.c
	./a.out

sdebug:
	gcc $(FLAGS) *.c
	./a.out

n:
	$(NORM)

push:
	git status
	git add ../.
	git commit -m "makefile commit"
	git push -f

ready:
	rm -rf $(DEST)
	mkdir $(DEST)
	cp $(FILES) $(DEST)
	cp libft.h $(DEST)
	cp makefile $(DEST)/Makefile

lldb:
	gcc -g *.c

test1:
	clear
	make fclean
	cd ../libft-unit-test && $(MAKE) f

test2:
	clear
	make fclean
	cd ../libftTester && $(MAKE) a

.PHONY: all clean fclean re bonus