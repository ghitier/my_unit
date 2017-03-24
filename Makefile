##
## Makefile for my_unit in /home/hitier_g/Projects/my_unit
## 
## Made by Guillaume HITIER
## Login   <guillaume.hitier@epitech.eu>
## 
## Started on  Fri Mar 24 01:36:36 2017 Guillaume HITIER
## Last update Fri Mar 24 01:36:43 2017 Guillaume HITIER
##

NAME	= libmy_unit

CC	= gcc

AR	= ar -rc

RM	= rm -f

SRC	= my_unit.c	\

OBJ	= $(SRC:.c=.o)

CFLAGS	+= -I./include	\

CFLAGS	+= -fpic	\

LDFLAGS	+= -shared	\

all:	$(NAME)

$(NAME):	static dynamic

static:		$(OBJ)
	$(AR) -o $(NAME).a $(OBJ)

dynamic:	$(OBJ)
	$(CC) -o $(NAME).so $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME).a $(NAME).so

re:	fclean all

.PHONY: all $(NAME) clean fclean re
