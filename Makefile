##
## EPITECH PROJECT, 2021
## snake
## File description:
## Makefile
##

CFLAGS 	= -Llib -lmy

CFLAGS += -W -Wall -Wextra

CFLAGS 	+= -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CC		= gcc

SRC		= $(wildcard src/*.c)

LIBSRC	= $(wildcard lib/*.c)

OBJ		= $(SRC:.c=.o)

LIBOBJ 	= $(LIBSRC:.c=.o)

OUT		= snake

LIB		= lib/libmy.a

all: $(OUT)

$(OUT): $(LIB) $(OBJ)
	$(CC) -o $@ $(OBJ) $(CFLAGS)

$(LIB): $(LIBOBJ)
	$(AR) rsc $@ $(LIBOBJ)

clean:
	$(RM) $(LIBOBJ)
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(LIB)
	$(RM) $(OUT)

re: fclean all
