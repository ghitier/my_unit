##
## Makefile for my_unit in /home/hitier_g/Projects/my_unit
## 
## Made by Guillaume HITIER
## Login   <guillaume.hitier@epitech.eu>
## 
## Started on  Fri Mar 24 01:36:36 2017 Guillaume HITIER
## Last update Fri Mar 24 17:17:58 2017 Guillaume HITIER
##

NAME	= libmy_unit

CC	= gcc

CP	= cp

AR	= ar -rc

RM	= rm -f

SRC	= my_unit.c	\

OBJ	= $(SRC:.c=.o)

CFLAGS	+= -I./include	\

CFLAGS	+= -fpic	\

LDFLAGS	+= -shared	\

all:	$(NAME)

$(NAME):	dynamic

static:		$(OBJ)
	$(AR) -o $(NAME).a $(OBJ)

dynamic:	$(OBJ)
	$(CC) -o $(NAME).so $(OBJ) $(LDFLAGS)

install:
	@runner=`whoami`;						\
	if [ $$runner != "root" ]; then					\
	  echo "\nYou need root privileges to execute this command.\n";	\
	  exit 1;							\
	fi
	$(CP) include/my_unit.h /usr/include/
	$(CP) $(NAME).so /usr/lib/

uninstall:
	@runner=`whoami`;						\
	if [ $$runner != "root" ]; then					\
	  echo "\nYou need root privileges to execute this command.\n";	\
	  exit 1;							\
	fi
	$(RM) /usr/include/my_unit.h
	$(RM) /usr/lib/$(NAME).so

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME).a $(NAME).so

re:	fclean all

.PHONY: all $(NAME) static dynamic install uninstall clean fclean re
